%include 'functions.asm'

SECTION .text
global _start

_start:

mov ecx, 10
mov eax, 1

cmp ecx, 0
je endLoop

next:

cmp ecx, 0
je endLoop 

mul ecx

dec ecx
jmp next


endLoop:

call iprintLF

end:

call quit
