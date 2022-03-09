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

string_operation proc ; процесс нахождения чисел
        push ax
        push bx
        push cx
        push dx
        push si
        push di

        mov bx, offset string
    mov cl, current_size
    mov ch, 00h

        mov si, offset string

        jcxz end_loop  ; пока cx != 0

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
        jb check_space ; если больше

        inc si

        loop loop_checkWordIsNum

        jmp wordIsNum     ;закончилась строка и не было выходов из цикла - значит в конце число

check_space:
    compareb 20h
        jne wordIsNotNum    ; если не пробел - значит слово не число

wordIsNum:
        ; сюда алгоритм сдвига вправо и вставки слова слова number

        jcxz end_loop

    jmp start_loop

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
        pop dx
        pop cx
        pop bx
        pop ax

        ret
string_operation endp


input_string PROC near
        mov     cx, size_string - 1
        mov     bx, offset string
move_symbol:
        mov     ah, 01h
        int     21h
                cmp al,13 ; сравнение введенного символа с enter
                je end_enter_symbol ; если enter
        mov     byte ptr [bx],al ; запись в bx al
        inc     bx
        inc     current_size
        loop    move_symbol
end_enter_symbol:
        ret
input_string ENDP

output_string proc

mov ah, 09h
int 21h
ret

output_string endp

.data
size_string equ 200
current_size db (0)
string db size_string dup ("$")

enter_symbol db 0Dh, 0Ah, '$'
enter_message db "Enter your string: $"
entered_message db "Entered string: $"
test_string db "you find a number!", 0Dh, 0Ah, '$'
end start 
