#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// primeira funcao

void preencherDados(int id[],char nome[][50], char email[][50],char sexo[][11], char endereco[][50], double altura[2],int vacina[],int tamanho){
 int i=0;
 char opcao[3];
 //numeros randomicos
 do{
    srand(time(NULL));

        id[i] = 1 + rand() % 1000;
       
    printf("\nDigite o nome completo: ");
    fgets(nome[i],50,stdin);
    fflush(stdin);
 // email
    int verificar=0;
    do {
      printf("Digite seu email: ");
      fgets(email[i], 100, stdin);
      fflush(stdin);

      if (strstr(email[i], "@") == NULL) {
        printf("Invalido. Coloque o email com @.\n");
      } 
      else if (strstr(email[i], ".com") == NULL && strstr(email[i], ".br") == NULL) {
        printf("Invalido. O email tem que terminar com (.com ou .br)\n");
      }
      else {
        verificar = 1;
      }
    } while (!verificar);

 // sexo
     do{
    printf("Digite o sexo.Caso nao queira identificar, digite indiferente: ");
    gets (sexo[i]);
    fflush(stdin);
    }while((strcmp(sexo[i], "feminino")!=0) && (strcmp(sexo[i], "masculino")!=0) && (strcmp(sexo[i], "indiferente")!=0));

     printf("Digite o endereco:");
     fgets(endereco[i],50,stdin);

       do{
        printf("Digite a altura:");
        scanf("%lf",&altura[i]);
        fflush (stdin);

        if(altura[i]<1 || altura[i]>2){
            printf("Altura ivalida, digite entre 1 e 2:");
        }
       }while(altura[i]<1 || altura[i]>2);
   //vacina
       do {
        printf("Esta pessoa esta vacinada? 0 para nao e 1 para sim: ");
        scanf("%d", &vacina[i]);
        fflush(stdin);
        if (vacina[i] == 0) {
            printf("Pessoa nao vacinada.\n");
        } else if (vacina[i] == 1) {
            printf("Pessoa vacinada.\n");
        } else {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (vacina[i] != 0 && vacina[i] != 1);
        
       printf("Deseja realizar outra inclusao?");
       gets(opcao);
       fflush(stdin);
       i++;
}while (i<2 && strcmp(opcao, "sim")==0);

}



int main() {
    int i = 0;
    int id[2], vacina[2];
    char escolha, opcao[3], nome [2][50], email[2][50], sexo[2][11], endereco[2][50];
    double altura[2];

    do {
        printf("Qual funcao deseja realizar?\nDigite i para incluir\nDigite d para deletar.\nDigite e para buscar e editar.\nDigite m para imprimir\n");
        scanf(" %c", &escolha);
        fflush(stdin);
        if (escolha != 'i' && escolha != 'e' && escolha != 'd' && escolha != 'd') {
            printf("Opcao invalida\n");
        }
        
    switch (escolha) {
        case 'i':printf("Funcao incluir selecionada.\n");
        preencherDados(id,nome,email,sexo,endereco,altura,vacina,2);
 
            break;
        case 'd':
            printf("Funcao deletar selecionada.\n");
            break;

        case 'e':

    printf("Funcao de busca selecionada.\n");
    int posicao = -1, opcao2;
    char email_busca[100], opcao3[3];
    printf("Digite o email da pessoa que deseja buscar: ");
    fgets(email_busca, 100, stdin);

    for (int i = 0; i < 2; i++) {
        if (strcmp(email[i], email_busca) == 0) {
            posicao = i;
            printf("Pessoa encontrada:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Email: %s\n", email[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("Vacina: %d\n", vacina[i]);

            printf("Voce quer editar dados dessa pessoa?");
            gets(opcao3);
            fflush(stdin);

            if (strcmp(opcao3, "sim") == 0) {
                printf("Digite o número do campo que deseja alterar:\n");
                printf("1 - Nome\n");
                scanf("%d", &opcao2);
                getchar();

                switch (opcao2) {
                    case 1: // Alterar nome
                        printf("Digite o novo nome: ");
                        fgets(nome[posicao], 100, stdin);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
            }
            break;
        }
    }

    if (posicao == -1) {
        printf("Email nao encontrado.\n");
    }            break;

        case 'm':
        break;

           default:
            break;
    }
       printf("\nDeseja continuar?");
       gets(opcao);
        i++;
    } while ((escolha != 'i' && escolha != 'e' && escolha != 'd') && i < 5 && strcmp(opcao, "sim")==0);

printf("ID\tNome\tEmail\t\tSexo\tEndereco\tAltura\tVacina");
    for (int i = 0; i < 2; i++) {
        printf("\n");
        printf("ID : %d\n", id[i]);
        printf("Nome :%s\n",nome[i]);
        printf("Email: %s\t", email[i]);
        printf("Sexo: %s\t", sexo[i]);
        printf("Altura: %.2lf\t", altura[i]);
        printf("Endereco: %s\t", endereco[i]);
        printf("Vacina: %d\t", vacina[i]);

    }

}