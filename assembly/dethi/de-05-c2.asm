.model small
.stack 100h
.data
    thongbao1 db "Nhap 1 so: $"
    thongbao2 db 10,13,"Nho hon 5!$"
    thongbao3 db 10,13,"Bang 5!$"
    thongbao4 db 10,13,"Lon hon 5!$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov ah,01h
        int 21h
        
        cmp al,53d
        jb nhohon5
        je bang5
        ja lonhon5
        
        nhohon5:
            mov ah,09h
            lea dx,thongbao2
            int 21h
            jmp thoat
        bang5:
            mov ah,09h
            lea dx,thongbao3
            int 21h
            jmp thoat
        lonhon5:
            mov ah,09h
            lea dx,thongbao4
            int 21h
        thoat:
            mov ah,4ch
            int 21h
    main endp
end main    