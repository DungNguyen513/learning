.MODEL SMALL ;KHAI BAO CHE DO BO NHO CUA CHUONG TRINH
.STACK 100H  ;KHAI BAO NGAN XEP
.DATA        ;KHAI BAO DU LIEU
    THONGBAO1 DB 'NHAP 1 KY TU: $'
    THONGBAO2 DB 13,10,'KY TU VUA NHAP LA: $'
    KYTU DB ?
.CODE         ;KHAI BAO CAC LENH XU LY
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
        
        ;LUU TRU KY TU
        MOV KYTU,AL
        
        ;HIEN THI THONGBAO2
        MOV AH,09H
        LEA DX,THONGBAO2
        INT 21H
        
        ;DI CHUYEN KY TU VAO THANH GHI DL
        MOV DL,KYTU
        
        ;XUAT KY TU
        MOV AH,02H
        INT 21H
        
        ;THOAT CHUONG TRINH, TRO VE DOS
        MOV AH,4CH
        INT 21H
    MAIN ENDP ;KET THUC HAM MAIN
    END MAIN  ;KET THUC CHUONG TRINH