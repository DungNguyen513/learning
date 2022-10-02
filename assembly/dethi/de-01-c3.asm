.model small
.stack 100h
.data
    thongbao1 db "Nhap 1 ky tu: $"
    thongbao2 db 10,13,"Chu hoa$"
    thongbao3 db 10,13,"Chu thuong$"
    thongbao4 db 10,13,"Khong la chu$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov ah,01h
        int 21h
        
        cmp al,65d
        jb khonglachu
        cmp al,90d
        jbe chuhoa
        cmp al,122d
        ja khonglachu
        cmp al,97d
        jae chuthuong
        
        chuhoa:
            mov ah,09h
            lea dx,thongbao2
            int 21h
            jmp thoat
        chuthuong:
            mov ah,09h
            lea dx,thongbao3
            int 21h
            jmp thoat
        khonglachu:
            mov ah,09h
            lea dx,thongbao4
            int 21h
        thoat:
            mov ah,4ch
            int 21h
    main endp
end main    