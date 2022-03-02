.model small
.stack 100h
.code
start: mov ax, DGROUP
mov ds, ax
mov dx, offset message
mov ah, 9
int 21h
mov ax, 4C00h
int 21h
.data
message db "Hello world", 0Dh, ,0Ah,'$'
end start

; .model tiny
; .code
; org 100h
; start: mov ah, 9
; mov dx, offset message
; int 21h
; mov dx, offset second_message
; int 21h
; ret
; message db "Hello world", 0Dh, 0Ah, '$'
; second_message db "second string", 0Dh, 0Ah,  '$'
; end start