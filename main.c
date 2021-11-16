#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int op;

void titlePrint();
void menuPrint();
void menuFinal();
void renewIP();
void restartSpool();
void limpaSpool();

int main()
{
    do{
        system("cls");  // Limpa a tela
        titlePrint();   // Imprime o titulo
        menuPrint();    // Imprime o menu

        switch(op){
            case 1:
                renewIP();
                break;
            case 2:
                restartSpool();
                break;
            case 3:
                limpaSpool();
                break;
            case 4:
                system("exit");
                break;
            default:
               printf("Selecione uma opcao valida!\n");
               break;
        }

    }while(op != 4);

    return 0;
}

void titlePrint(){ //Função contendo os dados do titulo que será exibido nas telas
    printf("\n================ TagaNet Informatica ================");
    printf("\n******** Ferramentas de solucao de problemas ********\n");
} // Fim titlePrint()

void menuFinal(){ // Função contendo o menu para ser chamado no fim das funções
    printf("\nDigite 4 para sair ou");
    printf("\nQualquer outro numero para voltar: ");
    scanf("%d", &op);
} // Fim menuFinal()

void menuPrint(){ // Função contendo o menu para ser chamado
  printf("\n************************* Menu *************************\nDigite o numero correspondente a opcao desejada");
  printf("\n1 - Renovar IP ( use caso sua conexao apresente problemas");
  printf("\n2 - Reiniciar spooler ( use caso sua impressora apresente problemas");
  printf("\n3 - Limpar Spooler ( Use para cancelar impressoes e reparar o Spooler");
  printf("\n4 - Sair");
  printf("\n");
  printf("\n1 - Renovar IP ( use caso sua conexao apresente problemas");
  printf("\nDigite o numero correspondente a opcao desejada: ");
  scanf("%d", &op);
} // Fim menuPrint()

void renewIP(){
    system("cls");  // Limpa a tela
    titlePrint();   // Imprime o titulo

    printf("\n******** Iremos tentar renovar o numero de IP ********");

    printf("\nDispensando conexao atual");
    system("ipconfig /release");

    printf("\nTentando renovar a conexao!");
    system("ipconfig /renew");

    getchar();
    menuFinal();
};
void restartSpool(){
    system("cls");  // Limpa a tela
    titlePrint();   // Imprime o titulo

    printf("\nParando o servico de impressao");
    system("net stop spooler");

    printf("\nReiniciando o servico de impressao!");
    system("net start spooler");

    getchar();
    menuFinal();
};


void limpaSpool(){
    system("cls");  // Limpa a tela
    titlePrint();   // Imprime o titulo

    printf("\nParando o servico de impressao\n");
    system("net stop spooler");

    printf("\nLocalizando impressões pendentes\n");
    system("echo on");
    system("chdir %systemroot%/system32/spool/PRINTERS");
    system("dir");
    system("del /f /s *.shl");
    system("del /f /s *.spl");
    system("dir");

    printf("\nReiniciando o servico de impressao!");
    system("net start spooler");

    getchar();
    menuFinal();
};
