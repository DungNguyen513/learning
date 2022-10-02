.model small
.stack 100h
.data
    thongbao1 db "Nhap so thu 1: $"
    thongbao2 db 10,13,"Nhap so thu 2: $"
    thongbao3 db 10,13,"Tong 2 so: $"
    thongbao4 db 10,13,"Khong the thuc hien phep cong!$"
    sothu1 db ?
    tong db ?
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,09h
        lea dx,thongbao1
        int 21h
        
        mov ah,01h
        int 21h
        
        mov sothu1,al
        
        mov ah,09h
        lea dx,thongbao2
        int 21h
        
        mov dl,sothu1
        
        mov ah,01h
        int 21h
        
        add al,dl
        sub al,48d
        
        mov tong,al
        
        cmp al,57d
        ja khongthuchien
        
        thuchien:
            mov ah,09h
            lea dx,thongbao3
            int 21h
            mov dl,tong
            mov ah,02h
            int 21h
            jmp thoat
        khongthuchien:
            mov ah,09h
            lea dx,thongbao4
            int 21h    
        thoat:
            mov ah,4ch
            int 21h
    main endp
end main    