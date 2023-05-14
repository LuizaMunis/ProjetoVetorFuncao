void editarCadastro(int id[],char nome[][50], char email[][50],char sexo[][11], char endereco[][50], double altura[2],int vacina[],int tamanho){
     int posicao = -1, opcao2;
     char email_busca[100], opcao3[3], opcao4[3];

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

        }while (strcmp(opcao4, "sim")==0);
            }
}
  if (posicao == -1){
        printf("Email nao encontrado.\n");
    }
  }
}







//deletar

/*void deletarDados(int id[],char nome[][50], char email[][50],char sexo[][11], char endereco[][50], double altura[2],int vacina[],int tamanho){
int excluir=0, posicao=0;
char email_busca[100];
printf("Digite o email da pessoa que deseja excluir: ");
fgets(email_busca, 100, stdin);

for(int i = 0; i < excluir; i++) {
            posicao = i;
            break;}

    for(int i = posicao; i < excluir - 1; i++) {
        id[i] = id[i+1];
        strcpy(nome[i], nome[i+1]);
        strcpy(email[i], email[i+1]);
        strcpy(sexo[i],sexo[i+1]);
        strcpy(endereco[i],endereco[i+1]);
        altura[i]=altura[i+1];
        vacina[i]=vacina[i+1];
    }
    excluir--;
    printf("Pessoa excluída com sucesso!\n");
}*/