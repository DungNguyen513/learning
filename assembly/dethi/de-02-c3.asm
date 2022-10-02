.MODEL SMALL
.STACK 100H
.DATA
    THONGBAO1 DB "Nhap 1 ky tu so: $"
    THONGBAO2 DB 10,13,"Khong la so$"
    THONGBAO3 DB 10,13,"So nho hon 5$"
    THONGBAO4 DB 10,13,"So bang 5$"
    THONGBAO5 DB 10,13,"So lon hon 5$"
    KYTU DB ?
.CODE
    MAIN PROC
        MOV AX,@DATA
        MOV DS,AX
        
        MOV AH,09H
        LEA DX,THONGBAO1
        INT 21H
        
        MOV AH,01H
        INT 21H
        
        MOV KYTU,AL
        
        MOV DL,KYTU
        
        CMP DL,48D
        JB KHONGLASO
        CMP DL,57D
        JA KHONGLASO
        CMP DL,53D
        JB NHOHON5
        JE BANG5
        JA LONHON5
        
        NHOHON5:
            MOV AH,09H
            LEA DX,THONGBAO3
            INT 21H
            JMP THOAT
        BANG5:
            MOV AH,09H
            LEA DX,THONGBAO4
            INT 21H
            JMP THOAT
        LONHON5:
            MOV AH,09H
            LEA DX,THONGBAO5
            INT 21H
            JMP THOAT
        KHONGLASO:
            MOV AH,09H
            LEA DX,THONGBAO2
            INT 21H
        THOAT:
            MOV AH,4CH
            INT 21H                
    MAIN ENDP
END MAIN    