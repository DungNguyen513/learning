.MODEL SMALL ;KHAI BAO CHE DO BO NHO CUA CHUONG TRINH
.STACK 100H  ;KHAI BAO NGAN XEP
.DATA        ;KHAI BAO DU LIEU
    THONGBAO1 DB "Nhap so thu nhat: $"
    THONGBAO2 DB 10,13,"Nhap so thu hai: $"
    THONGBAO3 DB 10,13,"Tong hai so la: $"
    THONGBAO4 DB 10,13,"Khong the thuc hien phep cong!$"
    SOTHU1 DB ?
    TONG DB ?
.CODE        ;KHAI BAO CAC LENH XU LY
    MAIN PROC ;BAT DAU HAM MAIN
        ;KHOI TAO THANH GHI DS
        MOV AX,@DATA
        MOV DS,AX
        
        ;HIEN THI THONGBAO1
        MOV AH,09H
        LEA DX,THONGBAO1
        INT 21H
        
        ;NHAP SO THU NHAT
        MOV AH,01H
        INT 21H
        
        ;LUU SO THU NHAT
        MOV SOTHU1,AL
        
        ;HIEN THI THONGBAO2
        MOV AH,09H
        LEA DX,THONGBAO2
        INT 21H
        
        ;NHAP SO THU HAI
        MOV AH,01H
        INT 21H
        
        ;TINH TONG 2 SO
        ADD AL,SOTHU1
        SUB AL,48D
        
        ;LUU VAO TONG
        MOV TONG,AL
        
        CMP AL,57D       ;SO SANH TONG VOI SO '9'
        JA KHONGTHUCHIEN
        
        HIENTHIKETQUA:
            ;HIEN THI THONGBAO3
            MOV AH,09H
            LEA DX,THONGBAO3;
            INT 21H
            ;DI CHUYEN VAO THANH GHI DL
            MOV DL,TONG
            MOV AH,02H
            INT 21H
            JMP THOAT
        KHONGTHUCHIEN:
            ;HIEN THI THONGBAO4
            MOV AH,09H
            LEA DX,THONGBAO4
            INT 21H
        THOAT:
            ;THOAT CHUONG TRINH, TRO VE DOS
            MOV AH,4CH
            INT 21H
    MAIN ENDP ;KET THUC HAM MAIN
END MAIN      ;KET THUC CHUONG TRINH    