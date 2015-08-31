/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdint.h>
#include <project.h>
#include "sd/ff.h"

FRESULT f_closedir (
  DIR* dp     /* [IN] Pointer to the directory object */
);
uint16_t sector_size=512;
FIL disk;
extern FIL log_file;
void reinit_fs(void);
void write_map(void);
void fatal_error(void);
char oct_buf[10];
FRESULT map_image(uint8_t disk_n, FIL *img_file);
void read_map(void);
#define logging 1


void ls_files(uint8_t *buf, int file_number, int files)
{
    FRESULT res;
    FILINFO fno;
    DIR dir;
    char *fn; 
    int f_counter=0;
    int length=0;
    res = f_opendir(&dir, "/disks"); 
    if(res!=FR_OK) fatal_error();
    for (;;) {
                res = f_readdir(&dir, &fno);                   /* Read a directory item */
                if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
                if (fno.fname[0] == '.') continue;             /* Ignore dot entry */
                fn = fno.fname;
                if((f_counter>=file_number) && (f_counter<(file_number+files)) && (files>0))
                {
                    do
                    {
                        buf[4+length++]=*fn;
                    }while(*fn++);
                }
                f_counter++;
                
            }
    buf[0]=length & 0xff;
    buf[1]=(length>>8) & 0xff;
    buf[2]=f_counter & 0xff;
    buf[3]=(f_counter>>8) & 0xff;
//    f_closedir(&dir);
        
}

void print_oct(uint16_t num)
{
    uint8_t i;
    uint16_t s=num;
    
    for(i=0;i<6;i++) oct_buf[i]=32;
    i=5;
    oct_buf[i+2]=0;
    oct_buf[i+1]='\n';
    while(s)
    {
        oct_buf[i--]=48+(s & 0x07);
        s=s>>3;
    }
}

void execute_cmd(uint8_t *buf)
{
FRESULT rc;

#define RESPONCE buf[0]
#define D_TYPE buf[2]
#define DISK_N (buf[3] & 0x7f)
#define SIDE    (buf[3] & 0x80)
#define TRACK   buf[4]
#define SECTOR  buf[5]
#define CMD     buf[1022]
    uint8_t spt,sides;
    uint32_t img_size,file_size,offset,readed;
    uint16_t tracks,i;
    spt=10;
    sides=1;
    tracks=80;
    static int log_N;
    if(CMD==0)
    {
        reinit_fs();
        return;
    }
    if(CMD==5)
    {
        CyDelayUs(1000);
        return;
    }
    if(CMD==4)
        {
            if(D_TYPE>0)
            {
#ifdef  logging
                for(i=0;i<11;i++) buf[512+i]="Log entry:"[i];
                rc=f_open(&log_file,"/log.txt",FA_WRITE | FA_READ);
                rc=f_lseek(&log_file,f_size(&log_file));
                rc=f_write(&log_file,&buf[512],10,&readed);
                if (rc!=FR_OK) RESPONCE=2;
                print_oct(log_N++);
                rc=f_write(&log_file,oct_buf,7,&readed);
                if (rc!=FR_OK) RESPONCE=2;
                for(i=0;i<D_TYPE;i++)
                {
                    print_oct(buf[8+(i*2)]+(buf[9+(i*2)]<<8));
                    rc=f_write(&log_file,oct_buf,7,&readed);
                    if (rc!=FR_OK) RESPONCE=2;
                }
                rc=f_close(&log_file);
                if (rc!=FR_OK) RESPONCE=2;
#endif                
            }
            return;
        }
    if(CMD==6)
    {
        read_map();
        return;
    }
    if(CMD==7)
    {
        write_map();
        return;
    }
    
    if(CMD==8)
    {
        ls_files(buf,buf[0]+(buf[1]<<8),buf[2]+(buf[3]<<8));
        return;
    }
    
    if(CMD<4) map_image(DISK_N, &disk);
    
    if(D_TYPE==1) {   tracks=80;    sides=0;  }
    else
    if(D_TYPE==2) {    tracks=80; }
    else
    if (D_TYPE==3){    tracks=256; spt=255; }
    
    img_size=sector_size*spt*tracks;
    if(sides) img_size*=2;
    file_size=f_size(&disk);
    if ((file_size!=0) && (file_size!=img_size))
    {
        img_size=file_size;
        if (sides) tracks=(img_size/(2*sector_size*spt));
        else tracks=(img_size/(sector_size*spt));
    }
    
    if(file_size==0) f_lseek(&disk,img_size);
    if(CMD<3)
    {
        if ((D_TYPE>3) || (TRACK>=tracks) || (SECTOR==0) || (SECTOR>spt) || ((sides==0) && (SIDE)))
        {
            RESPONCE=1;
            f_close(&disk);
            return;
        }
    }else
    if (CMD==3)
        if ((D_TYPE>3) || (TRACK>=tracks) || (SECTOR==0) || ((sides==0) && (SIDE)))
            {
                RESPONCE=1;
                f_close(&disk);
                return;
            }
   RESPONCE=0;
   
   if(CMD==1)             //1 read sector
        {
            offset=sector_size*((spt*TRACK*(sides+1))+(SECTOR-1));
            if(SIDE) offset+=sector_size*spt;
            rc=f_lseek(&disk,offset);
            rc=f_read(&disk,buf+8,sector_size,&readed);  // buf+8 - readed data
            if(rc!=FR_OK) RESPONCE=5+rc;
            else
                if (readed<sector_size) RESPONCE=2;
            buf[6]=readed & 0xff;                   // bytes readed
            buf[7]=(readed>>8) & 0xff; 
            f_close(&disk);
        }
    else if (CMD==2)
                         //2 write sector
        {
            offset=sector_size*((spt*TRACK*(sides+1))+(SECTOR-1));
            if(SIDE) offset+=sector_size*spt;
            rc=f_lseek(&disk,offset);
            rc=f_write(&disk,buf+8,sector_size,&readed);  // buf+8 - written data
            if (readed<sector_size) RESPONCE=2;
            buf[6]=readed & 0xff;                   // bytes readed
            buf[7]=(readed>>8) & 0xff; 
            f_close(&disk);
        }
    else if (CMD==3)
                     //3 format track
        {
            offset=sector_size*((spt*TRACK*(sides+1)));
            if(SIDE) offset+=sector_size*spt;
            f_lseek(&disk,offset);
            for(i=0;i<(sector_size/2);i++)
            {
                buf[8+(i*2)]=buf[6];
                buf[9+(i*2)]=buf[7];
            }
            for(i=0;i<spt;i++)
            {
                rc=f_write(&disk,buf+8,sector_size,&readed);
                if (rc!=FR_OK) break;
            }
            if (i<spt) RESPONCE=2;
            f_close(&disk);
        }
    
        else
        {
            RESPONCE=4;       // invalid cmd
            return;
        }
    
}
/* [] END OF FILE */
