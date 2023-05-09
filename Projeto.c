#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int numerosrandomicos(int  *id){
    srand(time(NULL)); 
    id = 1 + rand() % 1000;
    printf("Id:%d", id);
}

char preenchernome(char *nome){
    printf("\nDigite o nome completo: ");
    fgets(nome,50,stdin);
}

char preencheremail(char *email){
    int verificar;
       do {
        printf("Digite seu email: ");
        fgets(email, 100, stdin);

        if (strstr(email, "@") == NULL) {
            printf("Inválido. Coloque o email com @.\n");
        } else if (strstr(email, ".com") == NULL && strstr(email, ".br") == NULL) {
            printf("Inválido. O email tem que terminar com (.com ou .br)\n");
        } else {
            verificar = 1;
        }
    } while (!verificar); 
}

char preenchersexo(char *sexo){
    do{
    printf("Digite o sexo.Caso nao queira identificar, digite indiferente: ");
    gets (sexo);
    fflush(stdin);
    }while((strcmp(sexo, "feminino")!=0) && (strcmp(sexo, "masculino")!=0) && (strcmp(sexo, "indiferente")!=0));
}

char preencherendereco(char *endereco){
    printf("Digite o endereço");
    fgets(endereco,50,stdin);
}

int main() {
    int i = 0;
    int id[5];
    char escolha, opcao[3], nome[50][5],email[50][5], sexo[11][5], endereco[50][5];

    do {
        printf("Qual funcao deseja realizar?\nDigite i para incluir\nDigite d para deletar.\nDigite e para editar.\n");
        scanf(" %c", &escolha);
        fflush(stdin);

        if (escolha != 'i' && escolha != 'e' && escolha != 'd') {
            printf("Opcao invalida\n");
        }

        
    switch (escolha) {
        case 'i':
         printf("\nFuncao incluir selecionada.\n");
         numerosrandomicos(*id);
         preenchernome(*nome);
         preencheremail(*email);
         preenchersexo(*sexo);
         preencherendereco(*endereco);
            break;

        case 'd':
            printf("Funcao deletar selecionada.\n");
            break;

        case 'e':
            printf("Funcao editar selecionada.\n");
            break;

        default:
            break;
    }
       printf("\nDeseja continuar?");
       gets(opcao);

        i++;
    } while ((escolha != 'i' && escolha != 'e' && escolha != 'd') && i < 5 && strcmp(opcao, "sim")==0);

}
