#include <stdio.h>
#include <string.h>

#define TOTAL_ATRIBUTOS 4

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao;              // em milhões
    int area;                   // em mil km²
    int pib;                    // em bilhões de dólares
    int densidade_demografica; // pessoas por km²
} Carta;

// Função para mostrar os atributos disponíveis
void mostrarAtributosDisponiveis(int escolhido) {
    printf("Escolha um atributo:\n");
    if (escolhido != 1) printf("1. População\n");
    if (escolhido != 2) printf("2. Área\n");
    if (escolhido != 3) printf("3. PIB\n");
    if (escolhido != 4) printf("4. Densidade Demográfica\n");
}

// Função para obter valor de atributo de uma carta
int obterAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade_demografica;
        default: return -1;
    }
}

// Função para mostrar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213, 8516, 1445, 25};
    Carta carta2 = {"Japão", 126, 378, 4937, 347};

    int atributo1, atributo2;
    int valor1_c1, valor2_c1, valor1_c2, valor2_c2;
    int soma_c1, soma_c2;

    // Escolha do primeiro atributo
    do {
        mostrarAtributosDisponiveis(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > TOTAL_ATRIBUTOS) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > TOTAL_ATRIBUTOS);

    // Escolha do segundo atributo
    do {
        mostrarAtributosDisponiveis(atributo1);
        printf("Digite o número do segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > TOTAL_ATRIBUTOS || atributo2 == atributo1) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > TOTAL_ATRIBUTOS || atributo2 == atributo1);

    // Obtenção dos valores
    valor1_c1 = obterAtributo(carta1, atributo1);
    valor2_c1 = obterAtributo(carta1, atributo2);
    valor1_c2 = obterAtributo(carta2, atributo1);
    valor2_c2 = obterAtributo(carta2, atributo2);

    // Exibição dos dados
    printf("\n===== COMPARAÇÃO DAS CARTAS =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("%s: %d\n", nomeAtributo(atributo1), valor1_c1);
    printf("%s: %d\n", nomeAtributo(atributo2), valor2_c1);

    printf("\nCarta 2: %s\n", carta2.nome);
    printf("%s: %d\n", nomeAtributo(atributo1), valor1_c2);
    printf("%s: %d\n", nomeAtributo(atributo2), valor2_c2);

    // Comparação por atributo (maior vence, exceto Densidade)
    int pontos_c1 = 0, pontos_c2 = 0;

    // Primeiro atributo
    if (atributo1 == 4) {
        valor1_c1 < valor1_c2 ? pontos_c1++ : (valor1_c1 > valor1_c2 ? pontos_c2++ : 0);
    } else {
        valor1_c1 > valor1_c2 ? pontos_c1++ : (valor1_c1 < valor1_c2 ? pontos_c2++ : 0);
    }

    // Segundo atributo
    if (atributo2 == 4) {
        valor2_c1 < valor2_c2 ? pontos_c1++ : (valor2_c1 > valor2_c2 ? pontos_c2++ : 0);
    } else {
        valor2_c1 > valor2_c2 ? pontos_c1++ : (valor2_c1 < valor2_c2 ? pontos_c2++ : 0);
    }

    // Soma total para desempate
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\n===== RESULTADO FINAL =====\n");
    printf("Soma dos atributos:\n");
    printf("%s: %d\n", carta1.nome, soma_c1);
    printf("%s: %d\n", carta2.nome, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
