#include <stdio.h>
#include <stdlib.h>

void estado9(){
    printf("Estado 9\n");
    printf("INSTRUCAO TIPO J\n");
    printf("PCEsc\n");
    printf("UALFontePC = 10\n\n");
}

void estado8(){
    printf("Estado 8\n");
    printf("INSTRUCAO TIPO BEQ\n");
    printf("UALFonteA   = 1\n");
    printf("UALFonteB   = 00\n");
    printf("UALOp       = 01\n");
    printf("PCEscCond\n");
    printf("FontePC     = 01\n\n");
}

void estado7(){
    printf("Estado 7\n");
    printf("RegDst      = 1\n");
    printf("EscReg\n");
    printf("MemParaReg  = 0\n\n");
}

void estado6(){
    printf("Estado 6\n");
    printf("INSTRUCAO TIPO R\n");
    printf("UALFonteA   = 1\n");
    printf("UALFonteB   = 00\n");
    printf("UALOp       = 10\n\n");
    estado7();
}

void estado5(){
    printf("Estado 5\n");
    printf("INSTRUCAO TIPO SW\n");
    printf("EscMem\n");
    printf("IouD = 1\n\n");
}

void estado4(){
    printf("Estado 4\n");
    printf("RegDst      = 0\n");
    printf("EscReg\n");
    printf("MemParaReg  = 1\n\n");
}

void estado3(){
    printf("Estado 3\n");
    printf("INSTRUCAO TIPO LW\n");
    printf("LerMem\n");
    printf("IouD = 1\n\n");
    estado4();
}

void estado2(){
    printf("Estado 2\n");
    printf("UALFonteA   = 0\n");
    printf("UALFonteB   = 11\n");
    printf("UALOp       = 00\n\n");
}

void estado1(){
    printf("Estado 1\n");
    printf("UALFonteA   = 0\n");
    printf("UALFonteB   = 11\n");
    printf("UALOp       = 00\n\n");
}

void estado0(){
    printf("Estado 0\n");
    printf("LerMem\n");
    printf("UALFonteA   = 0\n");
    printf("Ioud        = 0\n");
    printf("IREsc\n");
    printf("UALFonteB   = 01\n");
    printf("UALOp       = 00\n");
    printf("PCEsc\n");
    printf("FontePC     = 00\n\n");
}

int main(){
    char opcode[6];
    int tipo=0;
    do{
        printf("Tipo LW     -> 100011\n");
        printf("Tipo SW     -> 101011\n");
        printf("Tipo R      -> 000000\n");
        printf("Tipo BEQ    -> 000100\n");
        printf("Tipo J      -> 000101\n");
        printf("Sair -> s\n");
        scanf("%s",&opcode); printf("\n");
        if(opcode[0]=='s'){}
        else if(opcode[5]=='1'){
            estado0();
            estado1();
            if(opcode[4]=='0') // TIPO J
                estado9();
            else if(opcode[2]=='0'){ // TIPO LW
                estado2(); estado3();
            }else{ // TIPO SW
                estado2(); estado5();}
        }
        else{
            estado0();
            estado1();
            if(opcode[3]=='0')
                estado6();
            else
                estado8();
        }
        system("pause");
    } while(opcode[0]!='s');
}
