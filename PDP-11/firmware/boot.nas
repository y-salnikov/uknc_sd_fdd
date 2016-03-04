equ("b1_adr=010000")
equ("tmp_buf=020000")
equ("dsk_buf=0116000")
		org(0)
		240
		137
		start_
		0
		0
		0
		0
		0
		0
		org(0100)
		dummy_int
		0
		org(0360)
		dummy_int
		0
		dummy_int
		0
		dummy_int
		0
		dummy_int
		0

start_:		12706
		stk_l
		12701
		msg0
		4737
		print_msg
		13737
		1112
		mp_n_kas
		4737
		load
		105737
		mp
		beq(ld1_ok)
		12701
		msg_err
		4737
		print_msg
		0
ld1_ok:		137
		b1_adr
		

##################################
cout:		10146
		12701
		177564		# канал 0
cout_l1:	132711
		200
		beq(cout_l1)
		5201
		5201
		110011
		12601
		207

#################################
mp_out:		10146
		12701
		176674		# канал 2
mp_l1:		132711
		200
		beq(mp_l1)
		5201
		5201
		110011
		12601
		207

load:		12703
		mp
		5000
		110300
		4737
		mp_out
		303
		110300
		4737
		mp_out
		12700
		377
		4737
		mp_out
		4737
		mp_out
ld1_wait:	32737
		200
		176674
		beq(ld1_wait)
		207
#################################
print_msg:	5000
print_l1:	112100
		4737
		cout
		5700
		bne(print_l1)
		207
print_number:	12700    # R1 - number
		nm_buf+6
p_n_l:		10102
		6201
		6201
		6201
		42702
		177770
		62702
		60
		110240
		22700
		nm_buf
		bne(p_n_l)
		12701
		nm_buf
		4737
		print_msg
		207

dummy_int:	2
#################################
nm_buf:		0
		0
		0
		0
msg0:		'BOOT0 Загружен\n\r'
		0
msg_err:	'BOOT1 Ошибка загрузки \n\r'
		0
mp:		4000
mp_n_kas:	21
		1000
		b1_adr
		(end_ - boot1)/2
		0
		0
		0
		0
stk_h:		
		
		org(PC+64)
stk_l:		0
max_mem:	0
tmp_adr:	0
tmp_adr2:	0
tmp_lng:	0
		org(01000)
boot1:		240
		12701
		b1_msg1-boot1+b1_adr
		4737
		print_msg
		12701
		mp
		12721
		400
		11167
		rel67(slot_n)
		12721
		32
		12721
		0
		12721
		177777
		4737
		load		#выделить всю память
		12701
		mp
		12721
		1000
		13737
		mp+6
		max_mem
		4737
		load
		162737
		(end_-boot2+10)/2
		max_mem
		12701
		mp
		12721
		400
		12721
		32
		5021
		13721
		max_mem
		4737
		load
		13737
		mp+4
		tmp_adr
		13737
		mp+6
		max_mem
		12701
		mp
		12721
		400
		12721
		32
		5021
		12721
		(end_-boot2)/2
		4737
		load
		105737
		mp
		beq(getmem_ok)
		12701
		b1_gm_err-boot1+b1_adr
		4737 
		print_msg
getmem_ok:	13737
		mp+4
		tmp_adr2
		13737
		mp+6
		tmp_lng
		13737
		tmp_adr
		mp+4
		13737
		max_mem
		mp+6
		12737
		1000
		mp
		4737
		load
		13737
	 	tmp_adr2
	 	mp+4
	 	13737
	 	tmp_lng
	 	mp+6
		12701
		b1_msg2-boot1+b1_adr
		4737
		print_msg
		13701
		mp+4
		4737
		print_number
		12701
		b1_msg2_end-boot1+b1_adr
		4737
		print_msg
		12737
		boot2-boot1+b1_adr
		mp+06
		12737
		(end_-boot2)/2
		mp+010
		12737
		10000
		mp
		4737
		load
		105737
		mp
		beq(boot1_b2_tr_ok)
		12701
		b1_b2_tr_err-boot1+b1_adr
		4737
		print_msg
boot1_b2_tr_ok:	12701
		b1_msg3-boot1+b1_adr
		4737
		print_msg
		12737
		14000
		mp
		4737
		load
		105737
		mp
		beq(boot1_b2_run_ok)
		12701
		b1_b2_run_err-boot1+b1_adr
		4737
		print_msg
boot1_b2_run_ok:12701
		b1_msg4-boot1+b1_adr
		4737
		print_msg
		12701
		nm_buf
		4737
		print_msg
		12701
		b1_msg2_end-boot1+b1_adr
		4737
		print_msg
		12701
		50
wait1:		12700
		10000
wait1_1:	sob(R0,wait1_1)
		sob(R1,wait1)
		12701
		mp
		12721
		4000
		16721
		rel67(slot_n)
		12721
		16000
		12721
		tmp_buf
		12721
		377
		4737
		load
		12701
		tmp_buf
		5711
		beq(b1_map_err)
		12104
		10102
		12701
		b1_msg_map_ok-boot1+b1_adr
		4737
		print_msg
		12703
		12
		12705
		15
print_file:	112200
		4737
		cout
		120003
		bne(pr_f_skip)
		10500
		4737
		cout
pr_f_skip:	77400+relm(print_file)	
		br(cont_map)
b1_map_err:	12701
		b1_msg_map_err-boot1+b1_adr
		4737
		print_msg
cont_map:	240
		12706
		new_stack-boot1+b1_adr
		12701
		mp2-boot1+b1_adr
		12721
		4000
		12721
		2
		12721
		400
		12721
		0
		12721
		400
		12700
		20000
wait2:		sob(R0,wait2)
		4767
		rel67(load2)
		12700         
		0
		22737
		240
		0
		bne(cp_end)
		137
		0
cp_end:		12701
		boot_sector_err-boot1+b1_adr
		4767
		rel67(print_msg2)
		0		# <-- end
####################################################
####################################################
####################################################
####################################################
load2:		12703
		mp2-boot1+b1_adr
		5000
		110300
		4767
		rel67(mp_out2)
		303
		110300
		4767
		rel67(mp_out2)
		12700
		377
		4767
		rel67(mp_out2)
		4767
		rel67(mp_out2)
ld2_wait:	32737
		200
		176674
		beq(ld2_wait)
		207
mp_out2:	10146
		12701
		176674		# канал 2
mp_l2:		132711
		200
		beq(mp_l2)
		5201
		5201
		110011
		12601
		207
##################################
cout2:		10146
		12701
		177564		# канал 0
cout2_l1:	132711
		200
		beq(cout2_l1)
		5201
		5201
		110011
		12601
		207
#################################
print_msg2:	5000
print2_l1:	112100
		4767
		rel67(cout2)
		5700
		bne(print2_l1)
		207

mp2:		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
		0
new_stack:	0

b1_msg_map_err: 'Ошибка чтения map.txt с SD-карты\n\r'
		0
b1_msg_map_ok:	'sd/map.txt :\n\r'
		0
b1_msg1:	'BOOT1 Зугружен\n\r'
		0
b1_msg2:	'Память ПП выделена  @ '
		0
b1_msg2_end:	'\n\r'
		0
b1_msg3:	'BOOT2 Загружен в память ПП\n\r'
		0
b1_msg4:	'BOOT2 Запущен @ '
		0
b1_gm_err:	'Ошибка выделения памяти ПП\n\r'
		0
b1_b2_tr_err:	'Ошибка загрузки BOOT2 в память ПП \n\r'
		0
b1_b2_run_err:	'Ошибка запуска BOOT2\n\r'
		0
boot_sector_err: 'Ошибка. Некорректный загрузочный сектор.\n\r'
		0
boot2:		240
		167
		rel67(b2_strt)
slot_n:		0
slot_old:	0
tmp_16:		0
tmp_10:		0

#int4_old:	0
#		240
#		240
#int4:		240
#		240
#		5726
#		5726
#		167
#		rel67(lock_lp1)

lock:		
		13767
		177710
		rel67(tmp_10)
		13767
		177716
		rel67(tmp_16)
		42737
		20
		177710     #запрет прерывания по внешнему событию
		42737
		10
		177716	   # внешнее событие - индекс
		52737
		4
		177716	   # разрешить прием внешнего события
lock_w1:	32737
		1
		177716
		bne(lock_w1)  # ждем готовности
#		13767
#		4
#		rel67(int4_old)
		10046
#		10700
#		62700
#		rel67(int4+4)
#		10037
#		4
		106700
		52700
		200
#		106400 # запрет прерываний
		12600
		13767
		177054
		rel67(slot_old)
		16704
		rel67(slot_n)
		304
		105704
		beq(slot1)
		12704
		12
		br(b2_ss_cont)
slot1:		12704
		2
b2_ss_cont:	10437
		177054
#lock_lp1:	240
#		240
#		240
#		240
#		240
#		240
#		5737
#		dsk_buf
#		16737
#		rel67(int4_old)
#		4
		207
unlock:		16737
		rel67(slot_old)
		177054
		16737
		rel67(tmp_16)
		177716
		16737
		rel67(tmp_10)
		177710
		10046
		106700
		42700
		200
#		106400 # разрешение прерываний
		12600
		207

k2_task_set:	10701
		62701
		rel67(k2_task+4)
		10137
		(07062+024)
		207

k2_delay:	4767
		rel67(lock)
		12737
		5
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)
		4767
		rel67(unlock)
		207
k2_log:		10146		#R0 адрес МП в ЦП /2
		4767
		rel67(lock)
		12701
		dsk_buf+8
		12705 
		6
		10537
		dsk_buf+2
k2_log_l1:	10037
		177010
		13721
		177014
		5200
		sob(R5,k2_log_l1)
		12737
		4			#log cmd
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)
		4767
		rel67(unlock)
		12601
		207

		240
k2_task:	240
		240
		4767
		rel67(k2_task_set)
		13700             # R0 - адрес МП в озу ЦП
		23200
		241
		6000
		10001		  # R1 - адрес МП/2
		5200
		10037
		177010            # 
		13700
		177014		  # R0 - тип устройства
		5002
		110002		  # R2(l) - тип устройства
		5702
		beq(k2_goto_old)
		20227
		3
		blos(k2_tsk_dsk)
k2_goto_old:	4737
		125030            # переход на старую программу обработки
		137
		174164		  # возврат к менеджеру процессов
k2_tsk_dsk:	10100
		4767
		rel67(k2_delay)
		10137
		177010
		13700
		177014		  # R0 - команда/ответ
		300
		120027
		3
		blos(dsk_ok)
		120027
		10
		beq(dsk_read_loc)
		120027
		20
		beq(dsk_write_loc)
		120027
		30
		beq(dsk_frmt_loc)
		120027
		101
		beq(ch_dsk_read_map_loc)
		120027
		102
		beq(ch_dsk_write_map_loc)
		120027
		103
		beq(ch_dsk_ls_loc)
		12700
		11
dsk_exit:	10137
		177010
		110037
		177014
		5337               #exit
		7062
		5737
		177064		# готовность к2
		137
		174164		# возврат к менеджеру процессов
dsk_ok:		5000
		br(dsk_exit)
dsk_read_loc:	4767
		rel67(dsk_read)
		br(dsk_exit)
dsk_write_loc:  4767
		rel67(dsk_write)
		br(dsk_exit)
dsk_frmt_loc:	4767
		rel67(dsk_frmt)
		br(dsk_exit)
ch_dsk_read_map_loc:
		4767
		rel67(ch_dsk_read_map)
		br(dsk_exit)
ch_dsk_write_map_loc:
		4767
		rel67(ch_dsk_write_map)
		br(dsk_exit)
ch_dsk_ls_loc:	4767
		rel67(ch_dsk_ls)
		br(dsk_exit)


#################################################################
#	input:  R1 - адрес МП в памяти ЦП /2
#	output: R0 - код ошибки в мл.байте R1 - адрес МП в памяти ЦП /2
#################################################################

dsk_read:	10146
		4767
		rel67(dsk_set_par)
dsk_read_lp1:	4767
		rel67(dsk_read_next)
		5767
		rel67(dsk_err)
		bne(dsk_read_end)
		5767
		rel67(dsk_N_words)
		bne(dsk_read_lp1)
dsk_read_end:	12601
		16700
		rel67(dsk_err)
		207
		
dsk_write:	10146
		4767
		rel67(dsk_set_par)
dsk_write_lp1:  4767
		rel67(dsk_write_next)		
		5767
		rel67(dsk_err)
		bne(dsk_write_end)
		5767
		rel67(dsk_N_words)
		bne(dsk_write_lp1)
dsk_write_end:	12601
		16700
		rel67(dsk_err)
		207
dsk_frmt:	10146
		4767
		rel67(dsk_set_par)
		4767
		rel67(lock)
		11600
		62700
		3
		10037
		177010
		13737
		177014
		dsk_buf+6
		12737
		3
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)
		13700
		dsk_buf
		4767
		rel67(unlock)
		12601
		207
dsk_cp_adr:	0
dsk_N_words:	0
dsk_err:	0
dsk_inc_err:	0
dsk_set_par:	4767
		rel67(lock)
		5067
		rel67(dsk_inc_err)
		10102  # R1 - адрес МП в памяти ЦП /2
		5202
		12704  # R4 - buf
		dsk_buf
		5024	# buf[0]=0
		10237
		177010
		13724  # |S|N-накопителя(0-3)||тип накопителя|
		177014 
		5202
		10237 
		177010
		13724  # |дорожка||сектор|
		177014 
		5202
		10237
		177010
		13767
		177014
		rel67(dsk_cp_adr)
		5202
		10237
		177010
		13767
		177014
		rel67(dsk_N_words)
		5067
		rel67(dsk_err)
		4767
		rel67(unlock)
		207

dsk_read_next:	5767
		rel67(dsk_inc_err)
		beq(drn_1)
		12700
		123
		br(dsk_read_error)
drn_1:		4767           
		rel67(lock)
		12737
		1
		dsk_buf+1022   # read 
		4767
		rel67(unlock)
		4767
		rel67(lock)    
		13700
		dsk_buf
		bne(dsk_read_error)
		13700
		dsk_buf+6	# reded
		241
		6000		# /2
		4767
		rel67(dsk_copy_to_cp)
		br(dsk_rd_n_skp)
dsk_read_error: 10067
		rel67(dsk_err)
dsk_rd_n_skp:	4767
		rel67(dsk_inc_sector)
		4767
		rel67(unlock)
		207


dsk_write_next:	5767
		rel67(dsk_inc_err)
		beq(dwn_1)
		12700
		123
		br(dsk_write_error)
dwn_1:		4767           
		rel67(lock)
		4767
		rel67(dsk_copy_from_cp)
		12737
		2
		dsk_buf+1022   # write
		4767
		rel67(unlock)
		4767
		rel67(lock)    
		13700
		dsk_buf
		bne(dsk_write_error)
		13700
		dsk_buf+6	# writed
		60067
		rel67(dsk_cp_adr)
		241
		6000		# /2
		160067
		rel67(dsk_N_words)
		5767
		rel67(dsk_N_words)
		bpl(dsk_wr_n_skp)
		5067
		rel67(dsk_N_words)
		br(dsk_wr_n_skp)
dsk_write_error: 10067
		rel67(dsk_err)
dsk_wr_n_skp:	4767
		rel67(dsk_inc_sector)
		4767
		rel67(unlock)
		207



dsk_copy_to_cp: 16701
		rel67(dsk_N_words)
		20001
		blt(dsk_cp_cont)
		10100
dsk_cp_cont:	16701			#R0 - кол-во слов
		rel67(dsk_cp_adr)
		241
		6001			#R1 - адрес ЦП/2
		160067
		rel67(dsk_N_words)
		12702
		dsk_buf+8
dsk_cp_loop1:	10137
		177010
		12237
		177014
		5201
		sob(R0,dsk_cp_loop1)
		241
		6101
		10167
		rel67(dsk_cp_adr)
		207

dsk_copy_from_cp:
		16701
		rel67(dsk_N_words)
		12700
		400
		20001
		blt(dsk_cp_w_l1)
		10100
dsk_cp_w_l1:	16701
		rel67(dsk_cp_adr)
		241
		6001
		12702
		dsk_buf+8
dsk_cpw_loop1:	10137
		177010
		13722
		177014
		5201
		sob(R0,dsk_cpw_loop1)
		207




dsk_types:	(79)		#tracks
		(0)		#sides
		(10)		#sectors
		0
		(79)		#tracks
		(1)		#sides
		(10)		#sectors
		0
		(255)		#tracks
		(1)		#sides
		(256)		#sectors
		0

dsk_cur_sec:	13700
		dsk_buf+4
		300
		42700
		177400			#R0 - current sector
		207
		
dsk_upd_sec:	10046 		#R0 - new sector
		13700
		dsk_buf+4
		42700
		177400
		300
		52600
		300
		10037
		dsk_buf+4
		207

dsk_cur_trk:	13700
		dsk_buf+4
		42700
		177400		#R0 - current track
		207

dsk_upd_trk:	10046		#R0 - new track
		13700
		dsk_buf+4
		42700
		377
		52600
		10037
		dsk_buf+4
		207

dsk_cur_side:	13700
		dsk_buf+2
		32700
		100000
		bne(dsk_cur_sd_1)
		5000
		207
dsk_cur_sd_1:	12700
		1
		207			#R0 - side


dsk_upd_side:	5700			#R0 - new side
		beq(dsk_upd_s_0)
		13700
		dsk_buf+2
		52700
		100000
		br(dsk_upd_s_end)
dsk_upd_s_0:	13700
		dsk_buf+2
		42700
		100000
dsk_upd_s_end:  10037
		dsk_buf+2
		207
		


dsk_inc_sector: 			#перейти на следующий сектор
		13700
		dsk_buf+2
		42700
		177400			#R0 - disk_type
		5300
		241
		6300
		6300
		6300
		62700
		rel67(dsk_types-2)		
		60700	
		12001			#R1 - tracks
		12002			#R2 - sides
		12003			#R3 - sectors
		4767
		rel67(dsk_cur_sec)
		5200
		20003
		bgt(dsk_inc_sd)
		4767
		rel67(dsk_upd_sec)
		br(dsk_inc_sec_end)
dsk_inc_sd:	12700
		1
		4767
		rel67(dsk_upd_sec)
		4767
		rel67(dsk_cur_side)
		5700
		bne(dsk_inc_trk)
		5200
		20002
		bgt(dsk_inc_trk)
		4767
		rel67(dsk_upd_side)
		br(dsk_inc_sec_end)
dsk_inc_trk:	12700
		1
		4767
		rel67(dsk_upd_sec)
		12700
		0
		4767
		rel67(dsk_upd_side)
		4767
		rel67(dsk_cur_trk)
		5200
		20001
		bgt(dsk_inc_error)
		4767
		rel67(dsk_upd_trk)
		br(dsk_inc_sec_end)
dsk_inc_error:	5267
		rel67(dsk_inc_err)
dsk_inc_sec_end:
		207

ch_dsk_read_map:
		10100
		5200
		5200
		10037
		177010
		13700
		177014	# R0 - адрес ЦП
		241
		6000	#/2
		10146
		10246
		12701
		dsk_buf+2
		4767
		rel67(lock)
		12737
		6
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)
		13702
		dsk_buf
		32702
		1
		beq(ch_d_r_m_1)			# +1 к длине если не четное.
		5202
ch_d_r_m_1:	241
		6002
ch_d_r_m_2:	10037
		177010
		12137
		177014
		5200
		sob(R2,ch_d_r_m_2)
		4767
		rel67(unlock)
		12602
		12601
		10100
		5200
		5200
		5200
		10037
		177010
		13737
		dsk_buf
		177014
		5000
		207
		
ch_dsk_write_map:
		10146
		10246
		10100
		5200
		5200
		10037
		177010
		13702
		177014	# R2 - адрес ЦП
		241
		6002    #/2
		5200
		10037
		177010
		13700
		177014  # R0 - кол-во слов
		12701
		dsk_buf  #R1 - adr
		10003
		241
		6103
		4767
		rel67(lock)
		10321
ch_d_w_m_1:	10237
		177010
		13721
		177014
		5202
		sob(R0,ch_d_w_m_1)
		12737
		7
		dsk_buf+1022
		4767
		rel67(unlock)
		12602
		12601
		5000
		207

ch_dsk_ls:	10146
		5201
		5201
		10137
		177010
		13700
		177014   #R0 - N файла с которого начинается список
		5201
		10137
		177010
		13702	
		177014   #R2 - адрес ЦП
		241
		6002     # /2
		5201
		10137
		177010
		13703
		177014   # R3 - кол-во файлов
		12705    # R5 - буфер
		dsk_buf
		4767
		rel67(lock)
		10025
		10325
		12737
		(8)
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)
		11601   # R1 - адрес мп /2 
		12704
		dsk_buf
		12400	# R0 - длина
		32700
		1
		bne(ch_d_ls_1)
		5200
ch_d_ls_1:	241
		6000	# R0 - кол-во слов
		62701
		4
		10137	# МП+010 - общее кол-во файлов
		177010
		12437  
		177014
		5201
		10137
		177010 # кол-во слов
		10037
		177014
ch_d_ls_2:	10237
		177010
		12437
		177014
		5202
		sob(R0,ch_d_ls_2)
		4767
		rel67(unlock)
		12601
		5000
		207

b2_strt:	240
		4767
		rel67(k2_task_set)
		4767
		rel67(lock)
		12737
		0
		dsk_buf+1022
		4767
		rel67(unlock)
		4767
		rel67(lock)    #ugly
		4767
		rel67(unlock)
		207
pp_adr:		0
end_:		0



