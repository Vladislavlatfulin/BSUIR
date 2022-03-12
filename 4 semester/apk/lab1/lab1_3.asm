.model small
.stack 100h
.data

.code
start:


mov dx,3F8h ; инициализация порта
mov al,'r' ; наш символ
out dx,al ; записываем символ в порт


mov dx,2F8h ; инициализация второго порта

in al,dx ; чтение в регистр из dx
mov ah,2
mov dl,al
int 21h

mov ax,4C00h
int 21h
end start
