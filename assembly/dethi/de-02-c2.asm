.MODEL SMALL
.STACK 100H
.DATA
    THONGBAO1 DB "Nhap 1 ky tu hoa: $"
    THONGBAO2 DB 10,13,"Ky tu thuong la: $"
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
        
        MOV AH,09H
        LEA DX,THONGBAO2
        INT 21H
        
        MOV DL,KYTU
        
        ADD DL,32
        
        MOV AH,02H
        INT 21H
        
        MOV AH,4CH
        INT 21H
    MAIN ENDP
END MAIN    