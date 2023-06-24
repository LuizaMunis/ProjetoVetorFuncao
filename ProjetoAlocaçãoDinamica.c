#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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
	struct Dados *proximo;
}*cadastro;

///////////////////////////////////////////////////////////////////////////////////////
struct Dados* inicializar(){
	return NULL; 
}
//////////////////////////PRIMEIRA FUNÇÃO/////////////////////////////////////////////

struct Dados* preencherDados(struct Dados* cadastro){
    int i =0;
    char opcao[3];

	struct Dados* novo = (struct Dados*) malloc(sizeof(cadastro));

 do{
    //numeros randomicos
    srand(time(NULL));
    novo->id = 1 + rand() % 1000;

    //nome/  
    printf("\nDigite o nome completo: ");
    fgets(novo->nome,TAMANHO_STRING,stdin);
    fflush(stdin);

    // email
    int verificar=0;
    do {
      printf("Digite seu email: ");
      fgets(novo->email, TAMANHO_STRING, stdin);
      fflush(stdin);

      if (strstr(novo->email, "@") == NULL) {
        printf("Invalido. Coloque o email com @.\n");
      } 
      else if (strstr(novo->email, ".com") == NULL && strstr(novo->email, ".br") == NULL) {
        printf("Invalido. O email tem que terminar com (.com ou .br)\n");
      }
      else {
        verificar = 1;
      }
     } while (!verificar);

     // sexo
     do{
     printf("Digite o sexo.Caso nao queira identificar, digite indiferente: ");
     gets (novo->sexo);
     fflush(stdin);
     }while((strcmp(novo->sexo, "feminino")!=0) && (strcmp(novo->sexo, "masculino")!=0) && (strcmp(novo->sexo, "indiferente")!=0));

     // endereço
     printf("Digite o endereco:");
     fgets(novo->endereco,TAMANHO_STRING,stdin);
     
     //altura
       do{
        printf("Digite a altura:");
        scanf("%lf",&novo->altura);
        fflush (stdin);

        if(novo->altura<1 || novo->altura>2){
            printf("Altura ivalida, digite entre 1 e 2\n");
        }
       }while(novo->altura<1 || novo->altura>2);

     //vacina
       do {
            printf("Esta pessoa esta vacinada? 0 para nao e 1 para sim: ");
            scanf("%d", &novo->vacina);
            fflush(stdin);
            if (novo->vacina == 0) {
            printf("Pessoa nao vacinada.\n");
            } else if (novo->vacina == 1) {
            printf("Pessoa vacinada.\n");
            } else {
            printf("Valor invalido. Tente novamente.\n");
            }
        } while (novo->vacina != 0 && novo->vacina != 1);

       printf("Deseja realizar outra inclusao?");
       gets(opcao);
       fflush(stdin);
       i++;

    }while (strcmp(opcao, "sim")==0);

}
/////////////////////////////////////SEGUNDA FUNÇÃO//////////////////////////////////////////////////

struct Dados* editarCadastro(struct Dados* cadastro){
	struct Dados*auxiliar;
     int opcao2;
     char email[TAMANHO_STRING], opcao3[3], opcao4[3];
	 int contador=0, tamanho=0;

    printf("Digite o email da pessoa que deseja buscar: ");
    fgets(email, TAMANHO_STRING, stdin);

    for(auxiliar=cadastro;auxiliar!=NULL;auxiliar=auxiliar->proximo) {
	tamanho++;

        if (auxiliar->email==email) {
            printf("Pessoa encontrada:\n");
            printf("ID: %d\n", auxiliar->id);
            printf("Nome: %s\n", auxiliar->nome);
            printf("Email: %s\n", auxiliar->email);
            printf("Sexo: %s\n", auxiliar->sexo);
            printf("Endereco: %s\n", auxiliar->endereco);
            printf("Altura: %.2f\n", auxiliar->altura);
            printf("Vacina: %d\n", auxiliar->vacina);

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
            fgets(auxiliar->nome, TAMANHO_STRING, stdin);
			fflush(stdin);
             break;

      	   case 2: // Alterar email
            printf("Digite o novo email: ");
            fgets(auxiliar->email, TAMANHO_STRING, stdin);
			fflush(stdin);
            break;

      	  case 3: // Alterar sexo
            printf("Digite o novo sexo: ");
            fgets(auxiliar->sexo, 10, stdin);
			fflush(stdin);
            break;

      	  case 4: // Alterar endereço
            printf("Digite o novo endereço: ");
            fgets(auxiliar->endereco, TAMANHO_STRING, stdin);
			fflush(stdin);
            break;

      	  case 5: // Alterar altura
            printf("Digite a nova altura: ");
            scanf("%lf", &auxiliar->altura);
            break;

      	  case 6: // Alterar vacina
            printf("Digite a nova vacina (0 = não, 1 = sim): ");
            scanf("%d", &auxiliar->vacina);
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
		}else contador++;
  }
        if (tamanho == contador){
      	  printf("Email nao encontrado.\n");
		  }
       return cadastro;
}

///////////////////////////////////TERCEIRA FUNÇÃO////////////////////////////////////

struct Dados* deletarDados(struct Dados* cadastro) {
 
    struct Dados* anterior;  //ponteiro que guarda a posição anterior
 	struct Dados* auxiliar; //lista auxiliar para busca do cad
	char email[TAMANHO_STRING];

    printf("Digite o email da pessoa que deseja excluir: ");
    fgets(email,TAMANHO_STRING, stdin);
    
    for (anterior=NULL,auxiliar=cadastro;auxiliar!=NULL&&auxiliar->email!=email;anterior=auxiliar,auxiliar=auxiliar->proximo) {

    }

		if(auxiliar==NULL){
        printf("\nPessoa não cadastrado!");
		return cadastro;
	}

	if(anterior==NULL){
		cadastro=auxiliar->proximo;
		free(auxiliar);
	}
	
	else{
		anterior->proximo=auxiliar->proximo;
		free(auxiliar);
	}


    printf("Pessoa excluida com sucesso!\n");
	return cadastro;
}

////////////////////////////QUARTA FUNÇÃO///////////////////////////////////////////

void imprimirDados(struct Dados* cadastro){
	struct Dados* auxiliar;
	for(auxiliar=cadastro;auxiliar!=NULL;auxiliar=auxiliar->proximo){
		    printf("Pessoa encontrada:\n");
            printf("ID: %d\n", auxiliar->id);
            printf("Nome: %s\n", auxiliar->nome);
            printf("Email: %s\n", auxiliar->email);
            printf("Sexo: %s\n", auxiliar->sexo);
            printf("Endereco: %s\n", auxiliar->endereco);
            printf("Altura: %.2f\n", auxiliar->altura);
            printf("Vacina: %d\n", auxiliar->vacina);

	}
}


//////////////////////////////////MAIN//////////////////////////////////////////////

int main() {
    int i = 0;
    char escolha, opcao[3];

	cadastro=inicializar();

    do {
        printf("Qual funcao deseja realizar?\nDigite i para incluir\nDigite d para deletar.\nDigite e para buscar e editar.\nDigite m para imprimir\n");
        scanf(" %c", &escolha);
        fflush(stdin);
        if (escolha != 'i' && escolha != 'e' && escolha != 'd' && escolha != 'd'&& escolha != 'm' && escolha != 'r' ) {
            printf("Opcao invalida\n");
        }

     switch (escolha) {

        case 'i':printf("Funcao incluir selecionada.\n");
        cadastro= preencherDados(cadastro);
        break;

        case 'd':
        printf("Funcao deletar selecionada.\n");
        cadastro= deletarDados(cadastro);
        break;

        case 'e': printf("Funcao de busca selecionada.\n");
        cadastro=editarCadastro(cadastro);
        break;

        case 'm': printf("Funcao de imprimir selecionada.\n");
        imprimirDados(cadastro);
        break;

        default:
        break;
     }
       printf("\nVoltar ao menu?");
       gets(opcao);
       fflush(stdin);
       
        i++;
        
    } while ((escolha != 'i' && escolha != 'e' && escolha != 'd' && escolha != 'm') && strcmp(opcao, "sim")==0);
    
} 