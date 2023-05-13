void editarDadosPessoa(int TAMANHO_VETOR, int id[], char nome[][100], char email[][100], char sexo[][100], char endereco[][100], double altura[], int vacina[]) {
    char email_busca[100];
    int encontrado = 0;

    // Pede o email para buscar a pessoa
    printf("Digite o email da pessoa que deseja buscar: ");
    fgets(email_busca, 100, stdin);

    // Percorre o vetor e busca pelo email
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (strcmp(email[i], email_busca) == 0) {
            // Email encontrado, permite a edição dos dados
            printf("Pessoa encontrada:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Email: %s\n", email[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("Vacina: %d\n", vacina[i]);

            // Pede quais dados o usuário deseja editar
            char opcao;
            do {
                printf("Deseja editar qual dado? (N)ome, (A)ltura, ou (S)air: ");
                scanf(" %c", &opcao);
                fflush(stdin);

                switch (opcao) {
                    case 'N':
                    case 'n':
                        printf("Digite o novo nome: ");
                        fgets(nome[i], 100, stdin);
                        printf("Nome alterado com sucesso.\n");
                        break;

                    case 'A':
                    case 'a':
                        double nova_altura;
                        printf("Digite a nova altura: ");
                        scanf("%lf", &nova_altura);
                        fflush(stdin);

                        if (nova_altura < 1.0 || nova_altura > 2.0) {
                            printf("Altura invalida. O valor deve estar entre 1 e 2 metros.\n");
                        } else {
                            altura[i] = nova_altura;
                            printf("Altura alterada com sucesso.\n");
                        }
                        break;

                    case 'S':
                    case 's':
                        printf("Saindo da edicao...\n");
                        break;

                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
            } while (opcao != 'S' && opcao != 's');

            encontrado = 1;
            break; // Termina a busca, já encontramos o email procurado
        }
    }

    // Se chegou até aqui, o email não foi encontrado
    if (!encontrado) {
        printf("Email nao encontrado.\n");
    }
}
