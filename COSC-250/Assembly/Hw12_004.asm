%include 'functions.asm'

SECTION .text
global _start

_start:

pop eax
pop eax 
pop eax

call atoi
mov ecx, eax

mov eax, 0

cmp ecx, 0
je endLoop

next:

cmp ecx, 0
je endLoop 

add eax, ecx

dec ecx
jmp next


endLoop:

call iprintLF

end:

call quit
