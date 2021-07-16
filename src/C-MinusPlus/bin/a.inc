%define mod.argc 2 

%MACRO mod.arg mod.argc 
	%define mod__i [EBP + 8 + 4*mod.argc - 4*1] 
	%define mod__j [EBP + 8 + 4*mod.argc - 4*2] 
%ENDMACRO 
; ==== begin function mod==== 

%MACRO $mod 0
	CALL @mod
	ADD ESP, 4*mod.argc
	PUSH EAX
%ENDMACRO 

%MACRO ENDFUNC@mod 0
	LEAVE
	RET 
	%undef mod__i 
	%undef mod__j 
%ENDMACRO 
; ==== end function `mod`   ====
 
%define quick_power_mod.argc 3 

%MACRO quick_power_mod.arg quick_power_mod.argc 
	%define quick_power_mod__x [EBP + 8 + 4*quick_power_mod.argc - 4*1] 
	%define quick_power_mod__y [EBP + 8 + 4*quick_power_mod.argc - 4*2] 
	%define quick_power_mod__k [EBP + 8 + 4*quick_power_mod.argc - 4*3] 
%ENDMACRO 
; ==== begin function quick_power_mod==== 

%MACRO $quick_power_mod 0
	CALL @quick_power_mod
	ADD ESP, 4*quick_power_mod.argc
	PUSH EAX
%ENDMACRO 
%define quick_power_mod.varc 1 

%MACRO quick_power_mod.var quick_power_mod.varc 
	%define quick_power_mod_1_res [EBP - 4*1] 
	SUB ESP, 4*quick_power_mod.varc 
%ENDMACRO 

%MACRO ENDFUNC@quick_power_mod 0
	LEAVE
	RET 
	%undef quick_power_mod__k 
	%undef quick_power_mod__x 
	%undef quick_power_mod__y 
%ENDMACRO 
; ==== end function `quick_power_mod`   ====
 
%define main.argc 0 
; ==== begin function main==== 

%MACRO $main 0
	CALL @main
	ADD ESP, 4*main.argc
	PUSH EAX
%ENDMACRO 
%define main.varc 4 

%MACRO main.var main.varc 
	%define main_1_a [EBP - 4*1] 
	%define main_1_b [EBP - 4*2] 
	%define main_1_c [EBP - 4*3] 
	%define main_1_cnt [EBP - 4*4] 
	SUB ESP, 4*main.varc 
%ENDMACRO 

%MACRO ENDFUNC@main 0
	LEAVE
	RET 
%ENDMACRO 
; ==== end function `main`   ====
 
