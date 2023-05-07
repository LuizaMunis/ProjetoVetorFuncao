#include<stdio.h>
#include <string.h>

int main (){
    int  i=0;
    char escolha,opcao[3];

    do{
     printf("Qual funcao deseja realizar?\n Digite i para incluir\n Digite d para deletar.\n Digite e para editar.\n");
     scanf("%c", &escolha);
     fflush (stdin);

     printf("Tem certeza?");
     gets(opcao);

        if(escolha!= 'i' || escolha!= 'e' || escolha!= 'd'){
        printf("Opcao invalida\n");}

    }while(strcmp(opcao, "nao")==0 || escolha!= 'i' || escolha!= 'e' || escolha!= 'd' && i<5);

    switch (escolha){
     case 'i':break;
     case 'd':break;
     case 'e':break;
     default:
        break;
    }
}