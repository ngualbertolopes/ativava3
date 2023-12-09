#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

Produto estoque[MAX_PRODUTOS];
int num_produtos = 0;

void inicializar_estoque() {
    num_produtos = 0;
}

void adicionar_produto() {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("O estoque está cheio.\n");
        return;
    }

    Produto p;
    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);
    printf("Digite a descrição do produto: ");
    scanf("%s", p.descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &p.valor);

    estoque[num_produtos] = p;
    num_produtos++;

    printf("Produto adicionado com sucesso.\n");
}

void imprimir_relatorio() {
    printf("Código | Descrição | Quantidade | Valor\n");
    for (int i = 0; i < num_produtos; i++) {
        Produto p = estoque[i];
        printf("%d | %s | %d | %.2f\n", p.codigo, p.descricao, p.quantidade, p.valor);
    }
}

void pesquisar_produto() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < num_produtos; i++) {
        Produto p = estoque[i];
        if (p.codigo == codigo) {
            printf("Código | Descrição | Quantidade | Valor\n");
            printf("%d | %s | %d | %.2f\n", p.codigo, p.descricao, p.quantidade, p.valor);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void remover_produto() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < num_produtos; i++) {
        Produto p = estoque[i];
        if (p.codigo == codigo) {
            for (int j = i; j < num_produtos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            num_produtos--;
            printf("Produto removido com sucesso.\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

int main() {
    int opcao = 0;
    while (opcao != 5) {
        printf("\nSistema de Controle de Estoque\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Imprimir relatório\n");
        printf("3 - Pesquisar produto\n");
        printf("4 - Remover produto\n");
        printf("5 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                imprimir_relatorio();
                break;
            case 3:
                pesquisar_produto();
                break;
            case 4:
                remover_produto();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
