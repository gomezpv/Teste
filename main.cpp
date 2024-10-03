#include <stdio.h>
#include <cstdlib>
#include <ctype.h>
#include <stdbool.h> 

int main() {
    char fila;
    int coluna;
    int assento; 
    char filasValidas[] = {'A', 'B', 'C', 'D', 'E'}; 
    char continuar = 'S';
    int classe;
    char mapaAssentos[5][5] = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
    while (continuar == 'S') {
        int linha = 1;
        bool onibusCheio = true; 
        int filaValida = 0;

        printf("\n=================================================");
        printf("\n       MAPA DE ASSENTOS");
        printf("\n      A  B  C  D  E");
        printf("\n");
        
        for (int i = 0; i < 5; ++i) {
            printf("%i", linha);
            printf("  |");
            linha++;
            for (int j = 0; j < 5; ++j) {
                if (mapaAssentos[i][j] != 'X') {
                    onibusCheio = false;
                }
                printf(" %c ", mapaAssentos[i][j]);
            }
            printf("\n");
        }
        printf("\n Assento ocupado: X | Assento livre: 0");
        printf("\n===================================================");
        
        if (onibusCheio) {
            printf("\n O ônibus está lotado. Tente mais tarde.\n");
            break;
        }

        printf("\n Escolha a classe: 1 - Executiva (até 3 assentos) | 2 - Econômica (apenas 1 assento, não janela): ");
        scanf("%d", &classe);
        
        if (classe != 1 && classe != 2) {
            printf("\n Classe inválida! Escolha entre 1 (Executiva) ou 2 (Econômica).\n");
            continue;
        }

        printf("\n Escolha uma fila (A-E): ");
        scanf(" %c", &fila);
        fila = toupper(fila);
        
        for (int i = 0; i < 5; i++) { 
            if (fila == filasValidas[i]) {
                filaValida = 1;
                break;
            }
        }

        if (!filaValida) {
            system("clear");
            printf("\n Fila inválida. Por favor, escolha uma fila entre A e E\n");
            continue;
        }

        switch (fila) {
            case 'A': coluna = 0; break;
            case 'B': coluna = 1; break;
            case 'C': coluna = 2; break;
            case 'D': coluna = 3; break;
            case 'E': coluna = 4; break;
        }

        printf("\n Escolha um assento (1-5): "); 
        scanf("%d", &assento);
        assento -= 1; 

        if (classe == 2 && (coluna == 0 || coluna == 4)) {
            system("clear");
            printf("\n Na classe econômica, não é permitido reservar assentos na janela. Escolha outro.\n");
            continue;
        }

        int numAssentos = 1;
        if (classe == 1) {
            printf("\n Quantos assentos deseja na classe executiva (1-3): ");
            scanf("%d", &numAssentos); 
            if (numAssentos < 1 || numAssentos > 3) { 
                system("clear");
                printf("\n Quantidade inválida. Na classe executiva, pode-se reservar entre 1 e 3 assentos.\n");
                continue;
            }
        }

        system("clear");
        bool assentosOcupados = false;
        for (int i = 0; i < numAssentos; ++i) {
            if (mapaAssentos[assento][coluna + i] == 'X') {
                assentosOcupados = true;
                break;
            }
        }

        if (assentosOcupados) { 
            printf("\n Um ou mais dos assentos selecionados já estão ocupados. Escolha outros.\n");
        } else {
            for (int i = 0; i < numAssentos; ++i) {
                mapaAssentos[assento][coluna + i] = 'X';
                printf("\n Assento %c%i reservado com sucesso!\n", fila, assento + 1);
            }
        }
    }
    
    return 0;
}
