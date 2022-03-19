.model small
.stack 100h
.code
JUMPS




start:

mov ax, @data
mov ds, ax

mov dx, offset enter_message
call output_string
call input_string
mov dx, offset enter_symbol
call output_string
call string_operation
cmp current_size, 0
je empty_string_error

mov dx, offset entered_message
call output_string
lea dx, string
call output_string
call end_proc

empty_string_error proc
    mov dx, offset empty_string
    mov ah, 09h
    int 21h
    call end_proc
    ret
empty_string_error endp

compareb MACRO second
    push bx

    mov bx, [si]
    cmp bl, second

    pop bx
ENDM

end_proc proc

    mov ax, 4C00h
    int 21h
end_proc endp

move_right_bytes Macro
    push ax
    push bx
    push cx
    push dx
    push di

    mov di, bx
    mov si, bx
    mov cx, 07h
    mov dx, bx

end_string_loop:
    inc si
    inc di
    compareb 24h
    jne end_string_loop
    dec si

 move_right:
    mov al, [si]
    mov [di], al
    dec di
    dec si
    cmp bx, di
    jne move_right

last_move:
    mov al, ' '
    mov [di], al
    mov si, di
    inc bx
    loop end_string_loop

    mov cx, 06h
    lea di, newWord
    mov si, dx

    write_word:
    mov al, [di]
    mov [si], al
    inc di
    inc si
    loop write_word

    inc si
    loop_find_next_word:
    compareb 30h
    jl end_loop_move

    compareb 39h
    jg end_loop_move

    inc si

    jmp loop_find_next_word

end_loop_move:

    pop di
    pop dx
    pop cx
    pop bx
    pop ax

ENDM


string_operation proc
    push ax
    push bx
    push cx
    push si
    push di

    mov cx, offset current_size
    mov cl, current_size
    
    mov si, offset string
    jcxz end_loop

start_loop:

skip_spaces:

    compareb 20h

    jne check_wordIsNum

    inc si
    loop skip_spaces

    jmp end_loop

check_wordIsNum:
    mov dx, cx
    mov bx, si

loop_checkWordIsNum:
    compareb 30h ; 30h - код 0
    jl check_space

    compareb 39h ; 39h - код 9
    jg check_space

    inc si

    loop loop_checkWordIsNum

    jmp wordIsNum

check_space:
    compareb 20h
    jne wordIsNotNum

wordIsNum:
   move_right_bytes
   
    jcxz end_loop

    jmp start_loop

wordIsNotNum:
    mov si, bx
    mov cx, dx

loop_wordIsNotNum:
    compareb 20h

    je skip_spaces

    inc si
    
    loop loop_wordIsNotNum

    jmp end_loop

end_loop:

    pop di
    pop si
    pop cx
    pop bx
    pop ax

    ret
string_operation endp


input_string PROC
    mov     cx, size_string - 1
    mov     bx, offset string
    mov     dx, offset current_size
    mov     dl, current_size

move_symbol:
    mov     ah, 01h
    int     21h
    cmp al, 36
    je end_enter_symbol
    cmp al,13 ; сравнение введенного символа с enter
    je end_enter_symbol
    mov     byte ptr [bx],al
    inc     bx
    inc     dl
    loop    move_symbol
end_enter_symbol:
    mov current_size , dl
    ret
input_string ENDP


output_string proc

    mov ah, 09h
    int 21h
    ret

output_string endp


.data
size_string equ 200
current_size db 0
string db 950 dup ("$")

enter_symbol db 0Dh, 0Ah, '$'
enter_message db "Enter your string: $"
entered_message db "Entered string: $"
newWord db 'number'
empty_string db "your string is empty", 0Dh, 0Ah, '$'
end start
