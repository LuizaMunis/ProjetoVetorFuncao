#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/////////////////////////// PRIMEIRA FUNÇÃO//////////////////////////////////////////

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
            printf("Altura ivalida, digite entre 1 e 2\n");
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
}while (i<1000 && strcmp(opcao, "sim")==0);
}

/////////////////////////////////////SEGUNDA FUNÇÃO//////////////////////////////////////////////////

void editarCadastro(int id[],char nome[][50], char email[][50],char sexo[][11], char endereco[][50], double altura[2],int vacina[],int tamanho){
     int posicao = -1, opcao2;
     char email_busca[100], opcao3[3], opcao4[3];

    printf("Digite o email da pessoa que deseja buscar: ");
    fgets(email_busca, 100, stdin);

    for (int i = 0; i < 1000; i++) {

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

            printf("Editar os dados dessa pessoa?");
            gets(opcao3);
            fflush(stdin);

            if (strcmp(opcao3, "sim") == 0) {
                printf("Digite o número do campo que deseja alterar:\n");
                printf("1 - Nome\n");
                printf("2 - Email\n");
                printf("3 - Sexo\n");
                printf("4 - Endereço\n");
                printf("5 - Altura\n");
                printf("6 - Vacina\n");
                scanf("%d", &opcao2);
                getchar();
        do{
        switch (opcao2) {

        case 1:
            printf("Digite o novo nome: ");
            fgets(nome[posicao], 100, stdin);
             break;
         case 2: // Alterar email
            printf("Digite o novo email: ");
            fgets(email[posicao], 100, stdin);
            break;
        case 3: // Alterar sexo
            printf("Digite o novo sexo: ");
            fgets(sexo[posicao], 10, stdin);
            break;
        case 4: // Alterar endereço
            printf("Digite o novo endereço: ");
            fgets(endereco[posicao], 100, stdin);
            break;
        case 5: // Alterar altura
            printf("Digite a nova altura: ");
            scanf("%lf", &altura[posicao]);
            break;
        case 6: // Alterar vacina
            printf("Digite a nova vacina (0 = não, 1 = sim): ");
            scanf("%d", &vacina[posicao]);
            break;
        default:
            printf("Opcao invalida.\n");
             break;
                }

        printf("Deseja editar outro dado dessa pessoa?");
        gets(opcao4);
        fflush(stdin);

        }while (strcmp(opcao4, "sim")==0);
            }
}
  if (posicao == -1){
        printf("Email nao encontrado.\n");
    }
  }
}

///////////////////////////////////TERCEIRA FUNÇÃO////////////////////////////////////

void deletarDados(int id[], char nome[][50], char email[][50], char sexo[][11], char endereco[][50], double altura[], int vacina[], int tamanho) {
    int excluir = tamanho;
    int posicao = -1;
    char email_busca[100];
    
    printf("Digite o email da pessoa que deseja excluir: ");
    fgets(email_busca, 100, stdin);
    
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(email[i], email_busca) == 0) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        printf("Email nao encontrado.\n");
        return;
    }
    
    for (int i = posicao; i < tamanho - 1; i++) {
        id[i] = id[i+1];
        strcpy(nome[i], nome[i+1]);
        strcpy(email[i], email[i+1]);
        strcpy(sexo[i], sexo[i+1]);
        strcpy(endereco[i], endereco[i+1]);
        altura[i] = altura[i+1];
        vacina[i] = vacina[i+1];
    }
    
    excluir--;
    printf("Pessoa excluida com sucesso!\n");
}
////////////////////////////////////main//////////////////////////////////////

int main() {
    int i = 0, contador;
    int id[1000], vacina[1000];
    char escolha, opcao[3], nome [1000][50], email[1000][50], sexo[1000][11], endereco[1000][50];
    double altura[1000];

    do {
        printf("Qual funcao deseja realizar?\nDigite i para incluir\nDigite d para deletar.\nDigite e para buscar e editar.\nDigite m para imprimir\nDigite r para backup e restauracao.\n");
        scanf(" %c", &escolha);
        fflush(stdin);
        if (escolha != 'i' && escolha != 'e' && escolha != 'd' && escolha != 'd'&& escolha != 'm' && escolha != 'r' ) {
            printf("Opcao invalida\n");
        }
        
    switch (escolha) {
        case 'i':printf("Funcao incluir selecionada.\n");
        printf("Quantas pessoas deseja cadastrar?");
        scanf("%d",&contador);
        fflush(stdin);
        preencherDados(id,nome,email,sexo,endereco,altura,vacina,2);
 
            break;
        case 'd':
            printf("Funcao deletar selecionada.\n");
            deletarDados(id,nome,email,sexo,endereco,altura,vacina,2);
            break;


        case 'e': printf("Funcao de busca selecionada.\n");
        editarCadastro(id,nome,email,sexo,endereco,altura,vacina,2);
            break;

        case 'm':
    ///mostra todos s dados cadastrados/////////
        for (int i = 0; i < contador; i++) {
        printf("\n");
        printf("ID : %d\t", id[i]);
        printf("Nome :%s\t",nome[i]);
        printf("Email: %s\t", email[i]);
        printf("Sexo: %s\t", sexo[i]);
        printf("Altura: %.2lf\t", altura[i]);
        printf("Endereco: %s\t", endereco[i]);
        printf("Vacina: %d\n", vacina[i]);
        printf("------------------------------------------------------------\n");
    }
        break;

        case 'r':printf("Funcao de backup e restauracao selecionada.\n");
        int id2[1000], vacina2[1000]; //variaveis pro backup
        char nome2 [1000][50], email2[1000][50], sexo2[1000][11], endereco2[1000][50];
        double altura2[1000];
        char opcao2[11], opcao3[3];

        printf("Deseja realizar backup ou restauracao?");
        gets(opcao2);
        fflush(stdin);

         if(strcmp(opcao2, "backup")==0){
            for (int i = 0; i < contador; i++){
            id2[i] = id[i];
            strcpy(nome2[i], nome[i]);
            strcpy(email2[i], email[i]);
            strcpy(sexo2[i], sexo[i]);
            strcpy(endereco2[i], endereco[i]);
            altura2[i] = altura[i];
            vacina2[i] = vacina[i];
            }
            printf("Backup concluido!\nDeseja visualizar o backup?");
            gets(opcao3);
            fflush(stdin);
            
            if(strcmp(opcao3, "sim")==0){
            for (int i = 0; i < contador; i++) {
            printf("\n");
            printf("ID : %d\t", id2[i]);
            printf("Nome :%s\t",nome2[i]);
            printf("Email: %s\t", email2[i]);
            printf("Sexo: %s\t", sexo2[i]);
            printf("Altura: %.2lf\t", altura2[i]);
            printf("Endereco: %s\t", endereco2[i]);
            printf("Vacina: %d\n", vacina2[i]);
            printf("------------------------------------------------------------\n");
            }}
         } 
         //restauracao

         if(strcmp(opcao2, "restauracao")==0){
          for (int i = 0; i < contador; i++){
            id[i] = id2[i];
            strcpy(nome[i], nome2[i]);
            strcpy(email[i], email2[i]);
            strcpy(sexo[i], sexo2[i]);
            strcpy(endereco[i], endereco2[i]);
            altura[i] = altura2[i];
            vacina[i] = vacina2[i];
          }

            printf("Restauracao concluida!\nDeseja visualizar a restauracao?");
            gets(opcao3);
            fflush(stdin);
            
            if(strcmp(opcao3, "sim")==0){
            for (int i = 0; i < contador; i++) {
            printf("\n");
            printf("ID : %d\t", id[i]);
            printf("Nome :%s\t",nome[i]);
            printf("Email: %s\t", email[i]);
            printf("Sexo: %s\t", sexo[i]);
            printf("Altura: %.2lf\t", altura[i]);
            printf("Endereco: %s\t", endereco[i]);
            printf("Vacina: %d\n", vacina[i]);
            printf("------------------------------------------------------------\n");
            } }
         }
         
        break;
           default:
            break;
    }

       printf("\nVoltar ao menu?");
       gets(opcao);
       fflush(stdin);
        i++;
        
    } while ((escolha != 'i' && escolha != 'e' && escolha != 'd') && i < 1000 && strcmp(opcao, "sim")==0);
}