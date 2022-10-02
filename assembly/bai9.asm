.MODEL SMALL ;KHAI BAO CHE DO BO NHO CUA CHUONG TRINH
.STACK 100H  ;KHAI BAO NGAN XEP
.DATA        ;KHAI BAO DU LIEU
    THONGBAO1 DB "Nhap 1 ky tu: $"
    THONGBAO2 DB 10,13,"La ky tu hoa!$"
    THONGBAO3 DB 10,13,"La ky tu thuong!$"
    THONGBAO4 DB 10,13,"Khong la ky tu chu!$"
.CODE        ;KHAI BAO CAC LENH XU LY
    MAIN PROC ;BAT DAU HAM MAIN
        ;KHOI TAO THANH GHI DS
        MOV AX,@DATA
        MOV DS,AX
        
        ;HIEN THI THONGBAO1
        MOV AH,09H
        LEA DX,THONGBAO1
        INT 21H
        
        ;NHAP 1 KY TU
        MOV AH,01H
        INT 21H
        
        ;SO SANH
        CMP AL,65D       ;SO SANH VOI KY TU 'A'
        JB KHONGLACHU    ;NEU NHO HON -> KHONG PHAI
        CMP AL,90D       ;SO SANH VOI KY TU 'Z'
        JBE LAKYTUHOA    ;NEU NHO HON HOAC BANG -> LA CHU HOA
        CMP AL,97D       ;SO SANH VOI KY TU 'a'
        JAE LAKYTUTHUONG ;NEU LON HON HOAC BANG -> LA CHU THUONG
        
        LAKYTUHOA:
            ;HIEN THI THONGBAO2
            MOV AH,09H
            LEA DX,THONGBAO2
            INT 21H
            JMP THOAT
        LAKYTUTHUONG:
            ;HIEN THI THONGBAO3
            MOV AH,09H
            LEA DX,THONGBAO3
            INT 21H
            JMP THOAT
        KHONGLACHU:
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