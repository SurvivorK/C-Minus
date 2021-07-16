FUNC @mod: 
	mod.arg  mod__i, mod__j
	push mod__i 
	push mod__i 
	push mod__j 
	div 
	push mod__j 
	mul 
	sub 
	ret ~ 
ENDFUNC@mod
 
FUNC @quick_power_mod: 
	quick_power_mod.arg  quick_power_mod__x, quick_power_mod__y, quick_power_mod__k
quick_power_mod.var quick_power_mod_1_res 
	push 1
	pop quick_power_mod_1_res
_begIf_1: 
	push quick_power_mod__x 
	push 0
	cmple 
	push quick_power_mod__y 
	push 0
	cmple 
	or 
	push quick_power_mod__k 
	push 0
	cmple 
	or 
	jz _elIf_1 
	push 1
	neg 
	ret ~ 
	jmp _endIf_1
_elIf_1: 
	push quick_power_mod__x 
	push quick_power_mod__k 
	$mod 
	pop quick_power_mod__x
_begWhile_1: 
	push quick_power_mod__y 
	push 0
	cmpne 
	jz _endWhile_1 
_begIf_2: 
	push quick_power_mod__y 
	push 2
	$mod 
	push 1
	cmpeq 
	jz _elIf_2 
	push quick_power_mod_1_res 
	push quick_power_mod__x 
	mul 
	push quick_power_mod__k 
	$mod 
	pop quick_power_mod_1_res
	jmp _endIf_2
_elIf_2: 
_endIf_2: 
	push quick_power_mod__y 
	push 2
	div 
	pop quick_power_mod__y
	push quick_power_mod__x 
	push quick_power_mod__x 
	mul 
	push quick_power_mod__k 
	$mod 
	pop quick_power_mod__x
	jmp _begWhile_1
_endWhile_1: 
	push quick_power_mod_1_res 
	ret ~ 
_endIf_1: 
ENDFUNC@quick_power_mod
 
FUNC @main: 
main.var main_1_a,main_1_b,main_1_c,main_1_cnt 
	readint  ""
	pop main_1_a
	readint  ""
	pop main_1_b
	readint  ""
	pop main_1_c
	push main_1_a 
	push main_1_b 
	push main_1_c 
	$quick_power_mod 
	print "%d"
	push 0
	ret ~ 
ENDFUNC@main
 
