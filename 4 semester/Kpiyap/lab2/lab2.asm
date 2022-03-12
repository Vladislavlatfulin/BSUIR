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
mov dx, offset entered_message
call output_string
lea dx, string
call output_string

mov ax, 4C00h
int 21h




compareb MACRO second ; макрос сравнения указателя si и параметра second
    push bx

    mov bx, [si]  ; получаем значение в bx через []
    cmp bl, second

    pop bx
ENDM




print_string proc
    push dx
    push ax

    mov dx, offset test_string
    mov ah, 09h
    int 21h

    pop ax
    pop dx

    ret
print_string endp





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

end_string_loop: ; цикл прохождения до конца строки
    inc si
    inc di
    compareb 24h ; ходим по циклу пока di не $
    jne end_string_loop
    dec si

 move_right:
    mov al, [si] ; swap
    mov [di], al
    dec di
    dec si
    cmp bx, di ; цикл пока si не равен bx(в bx указатель на первый символ)
    jne move_right

last_move:
    mov al, ' ' ; swap
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




string_operation proc ; процесс нахождения чисел
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

    compareb 20h     ; 20h - код пробела

    jne check_wordIsNum     ; если не пробел

    inc si
    loop skip_spaces

    jmp end_loop

check_wordIsNum:
    mov dx, cx         ; временные переменные для хранения указателя на байт и количество символов
    mov bx, si

loop_checkWordIsNum:
    compareb 30h ; 30h - код 0
    jl check_space ; если меньше

    compareb 39h ; 39h - код 9
    jg check_space ; если больше

    inc si

    loop loop_checkWordIsNum

    jmp wordIsNum     ;закончилась строка и не было выходов из цикла - значит в конце число

check_space:
    compareb 20h
    jne wordIsNotNum    ; если не пробел - значит слово не число

wordIsNum:
   move_right_bytes
   
    jcxz end_loop

    jmp start_loop

    ;jmp end_loop

wordIsNotNum:
    mov si, bx
    mov cx, dx

loop_wordIsNotNum:
    compareb 20h

    je skip_spaces    ;если пробел

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
    cmp al,13 ; сравнение введенного символа с enter
    je end_enter_symbol ; если enter
    mov     byte ptr [bx],al ; запись в bx al
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
size_string equ 200h
current_size db 0h
string db size_string dup ("$")

enter_symbol db 0Dh, 0Ah, '$'
enter_message db "Enter your string: $"
entered_message db "Entered string: $"
newWord db 'number'
test_string db "you find a number!", 0Dh, 0Ah, '$'
end start
