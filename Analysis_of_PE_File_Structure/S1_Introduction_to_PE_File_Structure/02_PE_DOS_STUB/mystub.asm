.model tiny
.code
    org 100h

start:
    mov ax, cs        
    mov ds, ax        
    mov ah, 09h
    mov dx, offset msg
    int 21h
    mov ax, 4C00h
    int 21h

msg db 'onhexgroup', 0Dh, 0Ah, '$'

end start