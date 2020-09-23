  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_4_3_output_P)
    ;%
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.A_0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.B_0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% heli_q8_4_3_output_P.C_0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 48;
	
	  ;% heli_q8_4_3_output_P.Joystick_gain_x
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 60;
	
	  ;% heli_q8_4_3_output_P.Joystick_gain_y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 61;
	
	  ;% heli_q8_4_3_output_P.K
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 62;
	
	  ;% heli_q8_4_3_output_P.L
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 72;
	
	  ;% heli_q8_4_3_output_P.P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 84;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_input_maxi
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 88;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_input_max
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 89;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_input_mini
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 90;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_input_min
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 91;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_output_max
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 92;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_output_ma
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 93;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_output_min
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 94;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_output_mi
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 95;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_final_analog_outp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 96;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_final_analog_out
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 97;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_final_pwm_outputs
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 98;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_final_pwm_output
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 99;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_initial_analog_ou
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 100;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_initial_analog_o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 101;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_initial_pwm_outpu
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 102;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_initial_pwm_outp
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 103;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_frequency
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 104;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_frequency
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 105;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_leading_deadb
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 106;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_leading_dead
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 107;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_trailing_dead
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 108;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_trailing_dea
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 109;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_other_outputs
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 110;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_other_output
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 111;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_other_outpu_m
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 112;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_other_outp_d
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 113;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_other_outpu_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 114;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_other_outp_h
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 115;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_other_outpu_j
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 116;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_other_outp_g
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 117;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_watchdog_analog_o
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 118;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_watchdog_analog_
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 119;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_watchdog_pwm_outp
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 120;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_watchdog_pwm_out
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 121;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_hardware_clocks
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_initial_encoder_c
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 7;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_initial_encoder_
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_alignment
	  section.data(6).logicalSrcIdx = 47;
	  section.data(6).dtTransOffset = 9;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_alignment
	  section.data(7).logicalSrcIdx = 48;
	  section.data(7).dtTransOffset = 10;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_configuration
	  section.data(8).logicalSrcIdx = 49;
	  section.data(8).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_configuratio
	  section.data(9).logicalSrcIdx = 50;
	  section.data(9).dtTransOffset = 12;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_modes
	  section.data(10).logicalSrcIdx = 51;
	  section.data(10).dtTransOffset = 13;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_modes
	  section.data(11).logicalSrcIdx = 52;
	  section.data(11).dtTransOffset = 14;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_polarity
	  section.data(12).logicalSrcIdx = 53;
	  section.data(12).dtTransOffset = 15;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_polarity
	  section.data(13).logicalSrcIdx = 54;
	  section.data(13).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_watchdog_digital_
	  section.data(14).logicalSrcIdx = 55;
	  section.data(14).dtTransOffset = 17;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_watchdog_digital
	  section.data(15).logicalSrcIdx = 56;
	  section.data(15).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_input_cha
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_analog_output_cha
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_analog_output_ch
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_4_3_output_P.HILReadEncoderTimebase_channels
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_4_3_output_P.HILWriteAnalog_channels
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_encoder_channels
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 37;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_encoder_channels
	  section.data(8).logicalSrcIdx = 64;
	  section.data(8).dtTransOffset = 45;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_pwm_channels
	  section.data(9).logicalSrcIdx = 65;
	  section.data(9).dtTransOffset = 53;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_pwm_channels
	  section.data(10).logicalSrcIdx = 66;
	  section.data(10).dtTransOffset = 61;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_quadrature
	  section.data(11).logicalSrcIdx = 67;
	  section.data(11).dtTransOffset = 69;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_quadrature
	  section.data(12).logicalSrcIdx = 68;
	  section.data(12).dtTransOffset = 70;
	
	  ;% heli_q8_4_3_output_P.HILReadEncoderTimebase_samples_
	  section.data(13).logicalSrcIdx = 69;
	  section.data(13).dtTransOffset = 71;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_active
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_final_digital_out
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_final_digital_ou
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_initial_digital_o
	  section.data(5).logicalSrcIdx = 74;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_initial_digital_
	  section.data(6).logicalSrcIdx = 75;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_input_
	  section.data(7).logicalSrcIdx = 76;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_input
	  section.data(8).logicalSrcIdx = 77;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_inpu_m
	  section.data(9).logicalSrcIdx = 78;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_inp_f
	  section.data(10).logicalSrcIdx = 79;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_output
	  section.data(11).logicalSrcIdx = 80;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_outpu
	  section.data(12).logicalSrcIdx = 81;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_outp_b
	  section.data(13).logicalSrcIdx = 82;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_out_o
	  section.data(14).logicalSrcIdx = 83;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_outp_e
	  section.data(15).logicalSrcIdx = 84;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_out_n
	  section.data(16).logicalSrcIdx = 85;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_outp_j
	  section.data(17).logicalSrcIdx = 86;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_out_p
	  section.data(18).logicalSrcIdx = 87;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_outp_c
	  section.data(19).logicalSrcIdx = 88;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_ou_oi
	  section.data(20).logicalSrcIdx = 89;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_out_ex
	  section.data(21).logicalSrcIdx = 90;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_out_l
	  section.data(22).logicalSrcIdx = 91;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_analog_outp_p
	  section.data(23).logicalSrcIdx = 92;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_analog_out_d
	  section.data(24).logicalSrcIdx = 93;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_clock_frequen
	  section.data(25).logicalSrcIdx = 94;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_clock_freque
	  section.data(26).logicalSrcIdx = 95;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_clock_frequ_e
	  section.data(27).logicalSrcIdx = 96;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_clock_freq_j
	  section.data(28).logicalSrcIdx = 97;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_clock_params_
	  section.data(29).logicalSrcIdx = 98;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_clock_params
	  section.data(30).logicalSrcIdx = 99;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_clock_param_c
	  section.data(31).logicalSrcIdx = 100;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_clock_para_b
	  section.data(32).logicalSrcIdx = 101;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_outpu
	  section.data(33).logicalSrcIdx = 102;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_outp
	  section.data(34).logicalSrcIdx = 103;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_out_b
	  section.data(35).logicalSrcIdx = 104;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_ou_a
	  section.data(36).logicalSrcIdx = 105;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_out_c
	  section.data(37).logicalSrcIdx = 106;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_o_ah
	  section.data(38).logicalSrcIdx = 107;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_ou_c1
	  section.data(39).logicalSrcIdx = 108;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_ou_m
	  section.data(40).logicalSrcIdx = 109;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_out_a
	  section.data(41).logicalSrcIdx = 110;
	  section.data(41).dtTransOffset = 40;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_ou_o
	  section.data(42).logicalSrcIdx = 111;
	  section.data(42).dtTransOffset = 41;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_out_j
	  section.data(43).logicalSrcIdx = 112;
	  section.data(43).dtTransOffset = 42;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_ou_k
	  section.data(44).logicalSrcIdx = 113;
	  section.data(44).dtTransOffset = 43;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_digital_out_m
	  section.data(45).logicalSrcIdx = 114;
	  section.data(45).dtTransOffset = 44;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_digital_o_oo
	  section.data(46).logicalSrcIdx = 115;
	  section.data(46).dtTransOffset = 45;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_encoder_count
	  section.data(47).logicalSrcIdx = 116;
	  section.data(47).dtTransOffset = 46;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_encoder_coun
	  section.data(48).logicalSrcIdx = 117;
	  section.data(48).dtTransOffset = 47;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_encoder_cou_k
	  section.data(49).logicalSrcIdx = 118;
	  section.data(49).dtTransOffset = 48;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_encoder_co_h
	  section.data(50).logicalSrcIdx = 119;
	  section.data(50).dtTransOffset = 49;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_encoder_param
	  section.data(51).logicalSrcIdx = 120;
	  section.data(51).dtTransOffset = 50;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_encoder_para
	  section.data(52).logicalSrcIdx = 121;
	  section.data(52).dtTransOffset = 51;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_encoder_par_m
	  section.data(53).logicalSrcIdx = 122;
	  section.data(53).dtTransOffset = 52;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_encoder_pa_e
	  section.data(54).logicalSrcIdx = 123;
	  section.data(54).dtTransOffset = 53;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_other_outpu_l
	  section.data(55).logicalSrcIdx = 124;
	  section.data(55).dtTransOffset = 54;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_other_outp_c
	  section.data(56).logicalSrcIdx = 125;
	  section.data(56).dtTransOffset = 55;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_outputs_a
	  section.data(57).logicalSrcIdx = 126;
	  section.data(57).dtTransOffset = 56;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_outputs_
	  section.data(58).logicalSrcIdx = 127;
	  section.data(58).dtTransOffset = 57;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_outputs_g
	  section.data(59).logicalSrcIdx = 128;
	  section.data(59).dtTransOffset = 58;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_output_a
	  section.data(60).logicalSrcIdx = 129;
	  section.data(60).dtTransOffset = 59;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_outputs_p
	  section.data(61).logicalSrcIdx = 130;
	  section.data(61).dtTransOffset = 60;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_output_j
	  section.data(62).logicalSrcIdx = 131;
	  section.data(62).dtTransOffset = 61;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_output_ap
	  section.data(63).logicalSrcIdx = 132;
	  section.data(63).dtTransOffset = 62;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_output_f
	  section.data(64).logicalSrcIdx = 133;
	  section.data(64).dtTransOffset = 63;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_outputs_o
	  section.data(65).logicalSrcIdx = 134;
	  section.data(65).dtTransOffset = 64;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_output_c
	  section.data(66).logicalSrcIdx = 135;
	  section.data(66).dtTransOffset = 65;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_params_at
	  section.data(67).logicalSrcIdx = 136;
	  section.data(67).dtTransOffset = 66;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_params_a
	  section.data(68).logicalSrcIdx = 137;
	  section.data(68).dtTransOffset = 67;
	
	  ;% heli_q8_4_3_output_P.HILInitialize_set_pwm_params__f
	  section.data(69).logicalSrcIdx = 138;
	  section.data(69).dtTransOffset = 68;
	
	  ;% heli_q8_4_3_output_P.HILInitialize1_set_pwm_params_f
	  section.data(70).logicalSrcIdx = 139;
	  section.data(70).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.Integrator_IC
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.PitchCounttorad_Gain
	  section.data(2).logicalSrcIdx = 141;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain
	  section.data(3).logicalSrcIdx = 142;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_4_3_output_P.Constant1_Value
	  section.data(4).logicalSrcIdx = 143;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_k
	  section.data(5).logicalSrcIdx = 144;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_4_3_output_P.PitchTransferFcn_A
	  section.data(6).logicalSrcIdx = 145;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_4_3_output_P.PitchTransferFcn_C
	  section.data(7).logicalSrcIdx = 146;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_4_3_output_P.PitchTransferFcn_D
	  section.data(8).logicalSrcIdx = 147;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_i
	  section.data(9).logicalSrcIdx = 148;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_P.Gain4_Gain
	  section.data(10).logicalSrcIdx = 149;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_4_3_output_P.ElevationCounttorad_Gain
	  section.data(11).logicalSrcIdx = 150;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_4_3_output_P.ElevationTransferFcn_A
	  section.data(12).logicalSrcIdx = 151;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_P.ElevationTransferFcn_C
	  section.data(13).logicalSrcIdx = 152;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_4_3_output_P.ElevationTransferFcn_D
	  section.data(14).logicalSrcIdx = 153;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_o
	  section.data(15).logicalSrcIdx = 154;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_4_3_output_P.Gain6_Gain
	  section.data(16).logicalSrcIdx = 155;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_4_3_output_P.Constant_Value
	  section.data(17).logicalSrcIdx = 156;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_P.TravelCounttorad_Gain
	  section.data(18).logicalSrcIdx = 157;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_n
	  section.data(19).logicalSrcIdx = 158;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_4_3_output_P.TravelTransferFcn_A
	  section.data(20).logicalSrcIdx = 159;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_4_3_output_P.TravelTransferFcn_C
	  section.data(21).logicalSrcIdx = 160;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_4_3_output_P.TravelTransferFcn_D
	  section.data(22).logicalSrcIdx = 161;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_l
	  section.data(23).logicalSrcIdx = 162;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_4_3_output_P.Gain_Gain_e
	  section.data(24).logicalSrcIdx = 163;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_4_3_output_P.Constant_Value_j
	  section.data(25).logicalSrcIdx = 164;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_4_3_output_P.Gain2_Gain
	  section.data(26).logicalSrcIdx = 165;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_4_3_output_P.Integrator_IC_i
	  section.data(27).logicalSrcIdx = 166;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_4_3_output_P.Integrator1_IC
	  section.data(28).logicalSrcIdx = 167;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_4_3_output_P.RateTransitionx_X0
	  section.data(29).logicalSrcIdx = 168;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_4_3_output_P.DeadZonex_Start
	  section.data(30).logicalSrcIdx = 169;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_4_3_output_P.DeadZonex_End
	  section.data(31).logicalSrcIdx = 170;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_4_3_output_P.Gainx_Gain
	  section.data(32).logicalSrcIdx = 171;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_4_3_output_P.Gain2_Gain_h
	  section.data(33).logicalSrcIdx = 172;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_4_3_output_P.RateTransitiony_X0
	  section.data(34).logicalSrcIdx = 173;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_4_3_output_P.DeadZoney_Start
	  section.data(35).logicalSrcIdx = 174;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_4_3_output_P.DeadZoney_End
	  section.data(36).logicalSrcIdx = 175;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_4_3_output_P.Gainy_Gain
	  section.data(37).logicalSrcIdx = 176;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_4_3_output_P.Gain5_Gain
	  section.data(38).logicalSrcIdx = 177;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_4_3_output_P.Backgain_Gain
	  section.data(39).logicalSrcIdx = 178;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_4_3_output_P.Frontgain_Gain
	  section.data(40).logicalSrcIdx = 179;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_4_3_output_P.Gain1_Gain
	  section.data(41).logicalSrcIdx = 180;
	  section.data(41).dtTransOffset = 40;
	
	  ;% heli_q8_4_3_output_P.Gain3_Gain
	  section.data(42).logicalSrcIdx = 181;
	  section.data(42).dtTransOffset = 41;
	
	  ;% heli_q8_4_3_output_P.FrontmotorSaturation_UpperSat
	  section.data(43).logicalSrcIdx = 182;
	  section.data(43).dtTransOffset = 42;
	
	  ;% heli_q8_4_3_output_P.FrontmotorSaturation_LowerSat
	  section.data(44).logicalSrcIdx = 183;
	  section.data(44).dtTransOffset = 43;
	
	  ;% heli_q8_4_3_output_P.BackmotorSaturation_UpperSat
	  section.data(45).logicalSrcIdx = 184;
	  section.data(45).dtTransOffset = 44;
	
	  ;% heli_q8_4_3_output_P.BackmotorSaturation_LowerSat
	  section.data(46).logicalSrcIdx = 185;
	  section.data(46).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 186;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.GameController_ControllerNumber
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 188;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 189;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_4_3_output_P.GameController_AutoCenter
	  section.data(3).logicalSrcIdx = 190;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_4_3_output_P.GameController_Enabled
	  section.data(4).logicalSrcIdx = 191;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_4_3_output_B)
    ;%
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_B.Integrator
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_B.PitchCounttorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% heli_q8_4_3_output_B.Sum1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% heli_q8_4_3_output_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_B.Gain_l
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 9;
	
	  ;% heli_q8_4_3_output_B.Gain4
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% heli_q8_4_3_output_B.ElevationCounttorad
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_B.Gain_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
	  ;% heli_q8_4_3_output_B.Gain6
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 13;
	
	  ;% heli_q8_4_3_output_B.Constant
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% heli_q8_4_3_output_B.TravelCounttorad
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% heli_q8_4_3_output_B.Gain_k
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_B.Gain_n
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% heli_q8_4_3_output_B.Sum
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% heli_q8_4_3_output_B.RateTransitionx
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 19;
	
	  ;% heli_q8_4_3_output_B.Joystick_gain_x
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 20;
	
	  ;% heli_q8_4_3_output_B.Gain2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 21;
	
	  ;% heli_q8_4_3_output_B.RateTransitiony
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 22;
	
	  ;% heli_q8_4_3_output_B.Joystick_gain_y
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 23;
	
	  ;% heli_q8_4_3_output_B.Gain5
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% heli_q8_4_3_output_B.P
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 25;
	
	  ;% heli_q8_4_3_output_B.Gain1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% heli_q8_4_3_output_B.Gain3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 28;
	
	  ;% heli_q8_4_3_output_B.FrontmotorSaturation
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 29;
	
	  ;% heli_q8_4_3_output_B.BackmotorSaturation
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 30;
	
	  ;% heli_q8_4_3_output_B.Sum_c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 31;
	
	  ;% heli_q8_4_3_output_B.GameController_o4
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% heli_q8_4_3_output_B.GameController_o5
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% heli_q8_4_3_output_B.Sum_cl
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 39;
	
	  ;% heli_q8_4_3_output_B.Sum1_i
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_4_3_output_DW)
    ;%
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_AIMinimums
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_AIMaximums
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 72;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_AOMinimums
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 80;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_AOMaximums
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 88;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_AOVoltages
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 96;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_FilterFrequency
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 104;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POSortedFreqs
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 112;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POValues
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 120;
	
	  ;% heli_q8_4_3_output_DW.RateTransitionx_Buffer0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 128;
	
	  ;% heli_q8_4_3_output_DW.RateTransitiony_Buffer0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 129;
	
	  ;% heli_q8_4_3_output_DW.HILWriteAnalog_Buffer
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 130;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_Card
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace3_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace4_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_4_3_output_DW.ToWorkspace5_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_4_3_output_DW.ElevationScopedegs_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_4_3_output_DW.ElevationScopedeg_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 31;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_4_3_output_DW.PitchScopedeg_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 32;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_4_3_output_DW.PtichrateScopedegs_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 33;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_4_3_output_DW.TravelrateScopedegs_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 34;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_DW.TravelScopedeg_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 35;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_4_3_output_DW.HILWriteAnalog_PWORK
	  section.data(14).logicalSrcIdx = 36;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_4_3_output_DW.Scope_PWORK_a.LoggedData
	  section.data(15).logicalSrcIdx = 37;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_4_3_output_DW.XScope_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 38;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_4_3_output_DW.YScope_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 39;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_ClockModes
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 43;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_QuadratureModes
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 46;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_InitialEICounts
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 54;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POModeValues
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 62;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POAlignValues
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 70;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POPolarityVals
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 78;
	
	  ;% heli_q8_4_3_output_DW.HILReadEncoderTimebase_Buffer
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 86;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_4_3_output_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_4_3_output_DW.HILInitialize1_POSortedChans
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3788726643;
  targMap.checksum1 = 388431954;
  targMap.checksum2 = 1392367358;
  targMap.checksum3 = 1148345719;

