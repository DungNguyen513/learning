.MODEL SMALL ;KHAI BAO CHE DO BO NHO CUA CHUONG TRINH
.STACK 100H  ;KHAI BAO NGAN XEP
.DATA        ;KHAI BAO DU LIEU
    THONGBAO1 DB "Nhap ky tu: $"
    THONGBAO2 DB 10,13,"La ky tu so!$"
    THONGBAO3 DB 10,13,"Khong la ky tu so!$"
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
        
        CMP AL,48D   ;SO SANH KY TU VOI KY TU '0'
        JB KHONGLASO ;NHAY DEN NHAN KHONGLASO NEU NHO HON
        CMP AL,57D   ;SO SANH KY TU VOI KY TU '9'
        JA KHONGLASO ;NHAY DEN NHAN KHONGLASO NEU LON HON
        
        LASO:
            ;HIEN THI THONGBAO2
            MOV AH,09H
            LEA DX,THONGBAO2
            INT 21H
            JMP THOAT
        KHONGLASO:
            ;HIEN THI THONGBAO3
            MOV AH,09H
            LEA DX,THONGBAO3
            INT 21H
        THOAT:
            ;THOAT CHUONG TRINH, TRO VE DOS
            MOV AH,4CH
            INT 21H
    MAIN ENDP ;KET THUC HAM MAIN
END MAIN      ;KET THUC CHUONG TRINH    