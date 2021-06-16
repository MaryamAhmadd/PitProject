;------------------------------------------------------Factorial---------------------------------------------------------------------
[org 0x0100]
start:
		mov ax,[no]
		mov [i1],2
		sub [i1],[no]
		mov [i2],1
		sub [i2],[no]
		mov bx,ax

l1:
		add bx,ax
		sub [i2],1
		cmp [i2],1
		jne l1
		je l2
l2:
		sub [i1],1
		cmp [i1],0
		jne l3
		je end1
l3:
		mov ax,bx
		mov [i2],[i1]
		add [i2],1
		jmp l1
		
end1:
		mov [result],bx			;result stored 
		mov ax, 0x4c00      ; terminate program
		int 0x21
 
 no: dw 5
 i1: dw 0
 i2: dw 0
 result: dw 0