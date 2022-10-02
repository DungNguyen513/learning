.model small
.stack 100h
.data
    thongbao1 db "Nhap chuoi: $"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov cx,10
        
        mov ah,01h
        lap:
            int 21h
            cmp cx,0
            je thoat
            loop lap
        thoat:
            mov ah,4ch
            int 21h    
    main endp
end main    