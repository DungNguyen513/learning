.model small
.stack 100h
.data
    thongbao1 db "Nhap 1 ky tu: $"
    thongbao2 db 10,13,"Ky tu lien truoc: $"
    thongbao3 db 10,13,"Ky tu lien sau: $"
    kytu db ?
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov ah,01h
        int 21h
        
        mov kytu,al
        
        mov ah,09h
        lea dx,thongbao2
        int 21h
        
        mov dl,kytu
        
        dec dl
        
        mov ah,02h
        int 21h
        
        mov ah,09h
        lea dx,thongbao3
        int 21h
        
        mov dl,kytu
        
        inc dl
        
        mov ah,02h
        int 21h
        
        mov ah,4ch
        int 21h
    main endp
end main    