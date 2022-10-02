.model small
.stack 100h
.data
    thongbao1 db "Nhap 1 ky tu: $"
    thongbao2 db 10,13,"La ky tu so!$"
    thongbao3 db 10,13,"Khong la ky tu so!$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov ah,01h
        int 21h
        
        cmp al,48d
        jb khonglaso
        cmp al,57d
        ja khonglaso
        
        laso:
            mov ah,09h
            lea dx,thongbao2
            int 21h
            jmp thoat
        khonglaso:
            mov ah,09h
            lea dx,thongbao3
            int 21h
        thoat:
            mov ah,4ch
            int 21h        
    main endp
end main    