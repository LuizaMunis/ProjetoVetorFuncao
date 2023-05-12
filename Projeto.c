#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int numeros_randomicos(int id[5]){
    int i=0;
    srand(time(NULL)); 
    id = 1 + rand() % 1000;
    printf("Id:%d", id[i]);
    return numeros_randomicos;
}

char preencher_nome(char nome[5]){
    int i=0;
    printf("\nDigite o nome completo: ");
    fgets(nome[i],50,stdin);
    return preencher_nome;
}

 char preencher_email(char email[5]){
    int verificar, i=0;
       do {
        printf("Digite seu email: ");
        fgets(email[i], 100, stdin);

        if (strstr(email[i], "@") == NULL) {
            printf("Inválido. Coloque o email com @.\n");
        } else if (strstr(email[i], ".com") == NULL && strstr(email[i], ".br") == NULL) {
            printf("Inválido. O email tem que terminar com (.com ou .br)\n");
        } else {
            verificar = 1;
        }
    } while (!verificar); 

    return preencher_email; 
}

char preencher_sexo(char sexo[5]){
    int i=0;
    do{
    printf("Digite o sexo.Caso nao queira identificar, digite indiferente: ");
    gets (sexo[i]);
    fflush(stdin);
    }while((strcmp(sexo[i], "feminino")!=0) && (strcmp(sexo[i], "masculino")!=0) && (strcmp(sexo[i], "indiferente")!=0));

    return preencher_sexo;
}

char preencher_endereco(char endereco[5]){
    int i=0;
    printf("Digite o endereco:");
    fgets(endereco[i],50,stdin);
   return preencher_endereco;
}

double preencher_altura(double altura[5]){
    int i=0;
    do{
        printf("Digite a altura:");
        scanf("%lf",&altura[i]);
        fflush (stdin);

    }while(altura[i]<1 || altura[i]>2);
    
    return preencher_altura;

} 

int preencher_vacina(int vacina[5]) {
    int i=0;
    do {
        printf("Esta pessoa esta vacinada? 0 para nao e 1 para sim: ");
        scanf("%d", &vacina[i]);
        fflush(stdin);

        if (vacina[4] == 0) {
            printf("Pessoa nao vacinada.\n");
        } else if (vacina[i] == 1) {
            printf("Pessoa vacinada.\n");
        } else {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (vacina[i] != 0 && vacina[i] != 1);
    return preencher_vacina;
}

int main() {
    int i = 0;
    int id[5], vacina[5];
    char escolha, opcao[3], nome[50][5],email[100][5], sexo[11][5], endereco[50][5];
    double altura[5];

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
         //numeros_randomicos(*id);
         preencher_nome(*nome);
        /* preencher_email(*email);
         preencher_sexo(*sexo);
         preencher_endereco(*endereco);
         preencher_altura(altura);
         preencher_vacina(vacina);*/
         
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


for(i=0;i<6;i++){
printf("nome ", preencher_nome(nome[i]));}
}