#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-- constantes globais
#define MAX_TERRITORIO 5
#define TAM_STRING 50

//--- iniciando a struct
struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    char nomeExercito[TAM_STRING];
    int tropas;
};

//--- limpeza do Buffer de entrada
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//--- programa principal
int main() {
    struct Territorio Areaterritorio[MAX_TERRITORIO];
    int totalTerritorio = 0;
    int opcao;

    //--- exibindo menu de opções do jogo ---
    do {
        printf("==================================\n");
        printf("    Bem vindo ao Desafio War\n");
        printf("==================================\n");
        printf("1 - Cadastrar um Novo Territorio\n");
        printf("2 - Listar todos os Territorios\n");
        printf("3 - Sair\n");
        printf("----------------------------------\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        LimparBufferEntrada(); // limpa o '\n' do scanf

        switch (opcao) {
        case 1:
            printf("\n--- Cadastro de Novo Exercito ---\n\n");

            if (totalTerritorio < MAX_TERRITORIO) {
                printf("Nome do Territorio: ");
                fgets(Areaterritorio[totalTerritorio].nome, TAM_STRING, stdin);

                printf("Nome do Exercito: ");
                fgets(Areaterritorio[totalTerritorio].nomeExercito, TAM_STRING, stdin);

                printf("Cor do Exercito (Ex.: Azul, Verde): ");
                fgets(Areaterritorio[totalTerritorio].cor, TAM_STRING, stdin);

                printf("Numero das Tropas: ");
                scanf("%d", &Areaterritorio[totalTerritorio].tropas);
                LimparBufferEntrada();

                // remove o \n das strings
                Areaterritorio[totalTerritorio].nome[strcspn(Areaterritorio[totalTerritorio].nome, "\n")] = '\0';
                Areaterritorio[totalTerritorio].cor[strcspn(Areaterritorio[totalTerritorio].cor, "\n")] = '\0';
                Areaterritorio[totalTerritorio].nomeExercito[strcspn(Areaterritorio[totalTerritorio].nomeExercito, "\n")] = '\0';

                totalTerritorio++;
                printf("\n=== Exercito cadastrado com Sucesso! ===\n\n");

            } else {
                printf("Cadastro Esgotado! :( Nao e possivel cadastrar mais territorios.\n");
            }
            break;

        case 2: //--- Listagem dos Exercitos
            printf("\n--- Lista de Exercitos ---\n\n");
            if (totalTerritorio == 0) {
                printf("-- Nenhum Exercito cadastrado --\n");
            } else {
                for (int i = 0; i < totalTerritorio; i++) {
                    printf("===============================\n");
                    printf("Exercito %d\n", i + 1);
                    printf("Nome do Territorio: %s\n", Areaterritorio[i].nome);
                    printf("Nome do Exercito: %s\n", Areaterritorio[i].nomeExercito);
                    printf("Cor do Exercito: %s\n", Areaterritorio[i].cor);
                    printf("Numero das Tropas: %d\n", Areaterritorio[i].tropas);
                }
                printf("===============================\n");
            }
            printf("\n-- Pressione Enter para continuar --");
            getchar();
            break;

        case 3: //-- Sair
            printf("Saindo do Jogo War...\n");
            break;

        default: //-- Opcao Invalida
            printf("Opcao Invalida! Tente Novamente.\n");
            printf("Pressione Enter para continuar...");
            getchar();
            break;
        }
    } while (opcao != 3);

    return 0;
}
