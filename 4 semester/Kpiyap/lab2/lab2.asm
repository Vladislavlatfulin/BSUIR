.model small
.stack 100h 
.code 

start: 

mov ax, @data
mov ds, ax

mov dx, offset enter_message
call output_string
call input_string
mov dx, offset enter_symbol
call output_string
mov dx, offset entered_message
call output_string
lea dx, string
call output_string

mov ax, 4C00h
int 21h


input_string PROC near
        ; mov     ax, size_string
        ; dec     ax
        mov     cx, size_string - 1
        mov     bx, offset string
move_symbol:
        mov     ah, 01h
        int     21h 
                cmp al,13
                je exit
        mov     byte ptr [bx],al
        inc     bx
        loop    move_symbol
exit:
        ret
input_string ENDP


output_string proc near 

mov ah, 09h
int 21h
ret

output_string endp

.data
size_string equ 200
string db size_string dup ("$")

enter_symbol db 0Dh, 0Ah, '$'
enter_message db "Enter your string: $"
entered_message db "Entered string: $" 
end start 