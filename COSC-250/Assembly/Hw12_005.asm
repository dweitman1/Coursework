%include 'functions.asm'

SECTION .data
    msg1 db 'Min = ', 0h
    msg2 db 'Max = ', 0h
    
SECTION .text
global _start

_start:

    pop ecx
    pop eax 
    pop eax
    call atoi
    mov ebx, eax
    mov edx, eax
    
    
MinMax:
    cmp ecx, 2
    je endMinMax
    
    pop eax
    call atoi
    call iprintLF
    
    cmp ebx, eax
        jge Max
    
MaxRet:
    cmp edx, eax
    jle Min
        
MinRet:
    dec ecx
    jmp MinMax

Max:
    mov ebx, eax
    jmp MaxRet
    

Min:
    mov edx, eax
    jmp MinRet

    
endMinMax:

    mov eax, msg1
    call sprint
    mov eax, ebx
    call iprintLF
    
    mov eax, msg2
    call sprint
    mov eax, edx
    call iprintLF
    

end:

call quit
