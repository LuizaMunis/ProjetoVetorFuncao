#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TAMANHO 1000
#define TAMANHO_STRING 50

/////////////////////////struct//////////////////////////////////////////////////////////////

struct Dados{
    int id;
    char nome[TAMANHO_STRING];
    char email[TAMANHO_STRING];
    char sexo [TAMANHO_STRING];
    char endereco[TAMANHO_STRING];
    double altura;
    int vacina;
};

struct Dados_Backup{
    int id;
    char nome[TAMANHO_STRING];
    char email[TAMANHO_STRING];
    char sexo [TAMANHO_STRING];
    char endereco[TAMANHO_STRING];
    double altura;
    int vacina;
};

//////////////////////////PRIMEIRA FUNÇÃO/////////////////////////////////////////////

void preencherDados(struct Dados cadastro[]){
    int i =0;
    char opcao[3];

 do{
    //numeros randomicos
    srand(time(NULL));
    cadastro[i].id = 1 + rand() % TAMANHO;

    //nome/  
    printf("\nDigite o nome completo: ");
    fgets(cadastro[i].nome,TAMANHO_STRING,stdin);
    fflush(stdin);

    // email
    int verificar=0;
    do {
      printf("Digite seu email: ");
      fgets(cadastro[i].email, TAMANHO_STRING, stdin);
      fflush(stdin);

      if (strstr(cadastro[i].email, "@") == NULL) {
        printf("Invalido. Coloque o email com @.\n");
      } 
      else if (strstr(cadastro[i].email, ".com") == NULL && strstr(cadastro[i].email, ".br") == NULL) {
        printf("Invalido. O email tem que terminar com (.com ou .br)\n");
      }
      else {
        verificar = 1;
      }
     } while (!verificar);

     // sexo
     do{
     printf("Digite o sexo.Caso nao queira identificar, digite indiferente: ");
     gets (cadastro[i].sexo);
     fflush(stdin);
     }while((strcmp(cadastro[i].sexo, "feminino")!=0) && (strcmp(cadastro[i].sexo, "masculino")!=0) && (strcmp(cadastro[i].sexo, "indiferente")!=0));

     // endereço
     printf("Digite o endereco:");
     fgets(cadastro[i].endereco,TAMANHO_STRING,stdin);
     
     //altura
       do{
        printf("Digite a altura:");
        scanf("%lf",&cadastro[i].altura);
        fflush (stdin);

        if(cadastro[i].altura<1 || cadastro[i].altura>2){
            printf("Altura ivalida, digite entre 1 e 2\n");
        }
       }while(cadastro[i].altura<1 || cadastro[i].altura>2);

     //vacina
       do {
            printf("Esta pessoa esta vacinada? 0 para nao e 1 para sim: ");
            scanf("%d", &cadastro[i].vacina);
            fflush(stdin);
            if (cadastro[i].vacina == 0) {
            printf("Pessoa nao vacinada.\n");
            } else if (cadastro[i].vacina == 1) {
            printf("Pessoa vacinada.\n");
            } else {
            printf("Valor invalido. Tente novamente.\n");
            }
        } while (cadastro[i].vacina != 0 && cadastro[i].vacina != 1);

       printf("Deseja realizar outra inclusao?");
       gets(opcao);
       fflush(stdin);
       i++;

    }while (i<TAMANHO && strcmp(opcao, "sim")==0);
}

/////////////////////////////////////SEGUNDA FUNÇÃO//////////////////////////////////////////////////

void editarCadastro(struct Dados cadastro[]){
     int posicao = -1, opcao2;
     char email_busca[TAMANHO_STRING], opcao3[3], opcao4[3];

    printf("Digite o email da pessoa que deseja buscar: ");
    fgets(email_busca, TAMANHO_STRING, stdin);

    for (int i = 0; i < TAMANHO; i++) {

        if (strcmp(cadastro[i].email, email_busca) == 0) {
            posicao = i;
            printf("Pessoa encontrada:\n");
            printf("ID: %d\n", cadastro[i].id);
            printf("Nome: %s\n", cadastro[i].nome);
            printf("Email: %s\n", cadastro[i].email);
            printf("Sexo: %s\n", cadastro[i].sexo);
            printf("Endereco: %s\n", cadastro[i].endereco);
            printf("Altura: %.2f\n", cadastro[i].altura);
            printf("Vacina: %d\n", cadastro[i].vacina);

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
            fgets(cadastro[posicao].nome, TAMANHO_STRING, stdin);
             break;
         case 2: // Alterar email
            printf("Digite o novo email: ");
            fgets(cadastro[posicao].email, TAMANHO_STRING, stdin);
            break;
        case 3: // Alterar sexo
            printf("Digite o novo sexo: ");
            fgets(cadastro[posicao].sexo, 10, stdin);
            break;
        case 4: // Alterar endereço
            printf("Digite o novo endereço: ");
            fgets(cadastro[posicao].endereco, TAMANHO_STRING, stdin);
            break;
        case 5: // Alterar altura
            printf("Digite a nova altura: ");
            scanf("%lf", &cadastro[posicao].altura);
            break;
        case 6: // Alterar vacina
            printf("Digite a nova vacina (0 = não, 1 = sim): ");
            scanf("%d", &cadastro[posicao].vacina);
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

void deletarDados(struct Dados cadastro[]) {
    int excluir = TAMANHO;
    int posicao = -1;
    char email_busca[100];
    
    printf("Digite o email da pessoa que deseja excluir: ");
    fgets(email_busca, TAMANHO_STRING, stdin);
    
    for (int i = 0; i < TAMANHO; i++) {
        if (strcmp(cadastro[i].email, email_busca) == 0) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        printf("Email nao encontrado.\n");
        return;
    }
    
    for (int i = posicao; i < TAMANHO - 1; i++) {
        cadastro[i]=cadastro[i+1];
    }
    
    excluir--;
    printf("Pessoa excluida com sucesso!\n");
}

////////////////////////////QUARTA FUNÇÃO///////////////////////////////////////////

void imprimirdados(struct Dados *cadastro,int contador){

        for (int i = 0; i < contador; i++) {
        printf("\n");
        printf("ID : %d\t", cadastro[i].id);
        printf("Nome :%s\t",cadastro[i].nome);
        printf("Email: %s\t", cadastro[i].email);
        printf("Sexo: %s\t", cadastro[i].sexo);
        printf("Altura: %.2lf\t", cadastro[i].altura);
        printf("Endereco: %s\t", cadastro[i].endereco);
        printf("Vacina: %d\n", cadastro[i].vacina);
        printf("------------------------------------------------------------\n");
    }
}

////////////////////////////////QUINTA FUNÇÃO////////////////////////////////////////

void backupRestauracao(struct Dados cadastro[], struct Dados_Backup sos[], int contador){
    char opcao2[11];

        printf("Deseja realizar backup ou restauracao?");
        gets(opcao2);
        fflush(stdin);

         if(strcmp(opcao2, "backup")==0){
            for (int i = 0; i < contador; i++){
            sos[i].id = cadastro[i].id;
            strcpy(sos[i].nome, cadastro[i].nome);
            strcpy(sos[i].email, cadastro[i].email);
            strcpy(sos[i].sexo, cadastro[i].sexo);
            strcpy(sos[i].endereco, cadastro[i].endereco);
            sos[i].altura = cadastro[i].altura;
            sos[i].vacina =cadastro[i].vacina;
            }
            printf("Backup concluido!");
         } 
         //restauracao

         if(strcmp(opcao2, "restauracao")==0){
          for (int i = 0; i < contador; i++){
            cadastro[i].id = sos[i].id;
            strcpy(cadastro[i].nome, sos[i].nome);
            strcpy(cadastro[i].email, sos[i].email);
            strcpy(cadastro[i].sexo, sos[i].sexo);
            strcpy(cadastro[i].endereco, sos[i].endereco);
            cadastro[i].altura = sos[i].altura;
           cadastro[i].vacina = sos[i].vacina;
          }

            printf("Restauracao concluida!");
         }
}

//////////////////////////////////MAIN//////////////////////////////////////////////

int main() {
    int i = 0, contador;
    char escolha, opcao[3];
    struct Dados cadastro[TAMANHO];
    struct Dados_Backup sos[TAMANHO];

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
        preencherDados(cadastro);
        break;

        case 'd':
        printf("Funcao deletar selecionada.\n");
        deletarDados(cadastro);
        break;

        case 'e': printf("Funcao de busca selecionada.\n");
        editarCadastro(cadastro);
        break;

        case 'm': printf("Funcao de imprimir selecionada.\n");
        imprimirdados(cadastro, contador);
        break;

        case 'r':printf("Funcao de backup e restauracao selecionada.\n");
        backupRestauracao(cadastro,sos,contador);
        break;

        default:
        break;
     }
       printf("\nVoltar ao menu?");
       gets(opcao);
       fflush(stdin);
       
        i++;
        
    } while ((escolha != 'i' && escolha != 'e' && escolha != 'd') && i < TAMANHO && strcmp(opcao, "sim")==0);
    
} 