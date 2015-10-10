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
#include <project.h>
#include "boot.h"
#include "sd/ff.h"
#include "cmd.h"
uint8_t buf[1024];
char file_names[4][32];
FATFS Fatfs;
FIL map_file,log_file;
uint8_t cd_flag=0;
void disk_init(void);
int main(void);

CY_ISR(cd_isr)
{
    cd_flag=1;
}

FRESULT map_image(uint8_t disk_n, FIL *img_file)
{
    FRESULT rc;
    
    rc=f_open(img_file,file_names[disk_n],FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
    return rc;
}
void fatal_error(void)
{
    char lst=0;
    while(1)
    {
        LED1_Write(lst);
        lst=1-lst;
        CyDelay(250);
        if(cd_flag)
        {
            cd_flag=0;
            main(); // very ugly, mem leak!!!!
        }
    }
}
void find_filename(int disk_n)
{
    uint16_t i,j;
    uint8_t found=0;
    char *str="/disks/filenamefilenamefilename____.ext";
    char *fname=file_names[disk_n-1];
    for (i=0;i<32;i++) fname[i]=str[i];
        for(i=2;i<1024;i++)
        {
            if((buf[i]==48+disk_n) && (buf[i+1]==':'))
            {
                i=i+2;
                j=0;
                while(buf[i]>32)
                {
                    fname[7+j]=buf[i];
                    i++;
                    j++;
                    if(j>31) break;
                }
                fname[j+7]=0;
                found=1;
                break;
            }
        }
        if(found)
        {
            
        }
}

void read_map(void)
{
    FRESULT rc;
    UINT readed,i;
    rc=f_open(&map_file, "/map.txt",FA_READ);
    if(rc!=FR_OK) fatal_error();
    rc=f_read(&map_file, buf+2, sizeof(buf),&readed);
    if(rc!=FR_OK) fatal_error();
    buf[0]=readed & 0xff;
    buf[1]=readed>>8;
    for(i=readed;i<512;i++) buf[i]=0;
find_filename(1);
find_filename(2);
find_filename(3);
find_filename(4);
f_close(&map_file);
}

void write_map(void)
{
    FRESULT rc;
    UINT readed;
    rc=f_open(&map_file, "/map.txt",FA_WRITE);
    if(rc!=FR_OK) fatal_error();
    rc=f_lseek(&map_file,0);
    rc=f_truncate(&map_file);
    if(rc!=FR_OK) fatal_error();
    rc=f_write(&map_file, buf+2, buf[0]+(buf[1]<<8),&readed);
    if(rc!=FR_OK) fatal_error();
find_filename(1);
find_filename(2);
find_filename(3);
find_filename(4);
f_close(&map_file);
}



void init_all(void)
{
     FRESULT rc;
    UINT i;
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//    disk_init();
    CyDelay(500);  
  
    f_mount(0,&Fatfs);
    for(i=0;i<1024;i++) buf[i]='\n';
    rc=f_open(&log_file,"/log.txt",FA_WRITE | FA_OPEN_ALWAYS);
    if(rc!=FR_OK) fatal_error();
    rc=f_lseek(&log_file,0);
    rc=f_truncate(&log_file);
    if(rc!=FR_OK) fatal_error();
    f_close(&log_file);
    read_map();
    
    
 }
void reinit_fs(void)
{
    f_mount(0,&Fatfs);
    read_map();
}


int main(void)
{
    uint8_t st;
    uint16_t adr;
    uint8_t* rom=(void*)boot_rom;
    LED1_Write(1);
    IDX_Write(1);   
    isr_1_StartEx(cd_isr);
    init_all();
    LED1_Write(0);
    IDX_Write(0);   
     //debug 

          buf[0]=0;
          buf[1]=0;
          buf[2]=2;
          buf[3]=0x83;
            buf[4]=79;
            buf[5]=10;
        buf[6]=0xAA;
        buf[7]=0x55;
          buf[1022]=1;
//          execute_cmd(buf);
    //debug
    CyGlobalIntEnable; 
    for(;;)
    {
        /* Place your application code here. */
        if(cd_flag)
        {
            cd_flag=0;
            init_all();
        }
        st=STATE_Read();
        while(st==7) st=STATE_Read();
        if(st>=4)
        {
            AD_H_SetDriveMode(AD_H_DM_STRONG);
            AD_L_SetDriveMode(AD_L_DM_STRONG);
        
            if(st==5)
            {
                adr=AL_reg_Read()+(AH_reg_Read()<<8)-0116000;
                AD_L_Write(~buf[adr]);
                AD_H_Write(~buf[adr+1]);
            }
            else
            {
                adr=(AL_reg_Read()+(AH_reg_Read()<<8)-0100000);
                if(BYTE_Read()) AD_H_Write(~rom[adr+1]); else AD_H_Write(0);
                AD_L_Write(~rom[adr]);
            }
            SIP_Write(0);
            st=STATE_Read();
            while(st!=7) st=STATE_Read();
        
            AD_H_SetDriveMode(AD_H_DM_DIG_HIZ);
            AD_L_SetDriveMode(AD_L_DM_DIG_HIZ);
            SIP_Write(1);
        }
        else
        {
            adr=AL_reg_Read()+(AH_reg_Read()<<8)-0116000;
            buf[adr]=~AD_L_Read();
            buf[adr+1]=~AD_H_Read();
            SIP_Write(0);
            st=STATE_Read();
            while(st!=7) st=STATE_Read();
            SIP_Write(1);
            if(adr==01776)
            {
                IDX_Write(1);
                LED1_Write(1);
                    execute_cmd(buf);
                IDX_Write(0);
                LED1_Write(0);
            }
        }
    }
}

/* [] END OF FILE */
