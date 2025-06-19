#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída.
#include <stdlib.h> // Para abs() para cálculos de movimento (opcional, mas bom ter para clareza)

// Desafio de Xadrez - MateCheck (Atualizado com Níveis Aventureiro e Mestre)
// Este código simula a movimentação de peças de xadrez utilizando estruturas de repetição
// e funções recursivas, conforme os requisitos de avaliação de desempenho da MateCheck.

// --- Constantes para Movimentação das Peças ---
const int MOVIMENTO_BISPO = 5;  // Bispo: 5 casas na diagonal superior direita
const int MOVIMENTO_TORRE = 5;  // Torre: 5 casas para a direita
const int MOVIMENTO_RAINHA = 8; // Rainha: 8 casas para a esquerda
// Para o Cavalo, as "casas" são mais conceituais em L, não um número linear
// usaremos a quantidade de "L"s que queremos simular.

// --- Nível Mestre: Funções Recursivas para Movimentação de Peças ---

// Função recursiva para simular a movimentação do Bispo.
// Movimenta 5 casas na diagonal direita para cima.
// Parâmetros:
//   - passoAtual: Indica o passo atual da movimentação (começando de 1).
//   - limitePassos: O número total de passos a serem simulados.
void moverBispoRecursivo(int passoAtual, int limitePassos) {
    // Caso base da recursão: se o passo atual exceder o limite, para.
    if (passoAtual > limitePassos) {
        return;
    }

    // Saída para a movimentação diagonal (Cima e Direita)
    // O conceito de "loops aninhados" na movimentação do bispo se reflete na mudança
    // simultânea de linha (Cima) e coluna (Direita) em cada passo da diagonal.
    printf("Bispo - Passo %d: Cima e Direita\n", passoAtual);

    // Chamada recursiva para o próximo passo.
    moverBispoRecursivo(passoAtual + 1, limitePassos);
}

// Função recursiva para simular a movimentação da Torre.
// Movimenta 5 casas para a direita.
// Parâmetros:
//   - passoAtual: Indica o passo atual da movimentação (começando de 1).
//   - limitePassos: O número total de passos a serem simulados.
void moverTorreRecursivo(int passoAtual, int limitePassos) {
    // Caso base da recursão.
    if (passoAtual > limitePassos) {
        return;
    }

    printf("Torre - Passo %d: Direita\n", passoAtual);

    // Chamada recursiva para o próximo passo.
    moverTorreRecursivo(passoAtual + 1, limitePassos);
}

// Função recursiva para simular a movimentação da Rainha.
// Movimenta 8 casas para a esquerda.
// Parâmetros:
//   - passoAtual: Indica o passo atual da movimentação (começando de 1).
//   - limitePassos: O número total de passos a serem simulados.
void moverRainhaRecursivo(int passoAtual, int limitePassos) {
    // Caso base da recursão.
    if (passoAtual > limitePassos) {
        return;
    }

    printf("Rainha - Passo %d: Esquerda\n", passoAtual);

    // Chamada recursiva para o próximo passo.
    moverRainhaRecursivo(passoAtual + 1, limitePassos);
}


int main() {
    printf("--- Desafio de Xadrez MateCheck ---\n\n");

    // --- Nível Mestre: Movimentação de Bispo, Torre e Rainha com Funções Recursivas ---
    printf("Simulando Movimentacao de Bispo (Nivel Mestre - Recursivo):\n");
    moverBispoRecursivo(1, MOVIMENTO_BISPO);
    printf("\n");

    printf("Simulando Movimentacao de Torre (Nivel Mestre - Recursivo):\n");
    moverTorreRecursivo(1, MOVIMENTO_TORRE);
    printf("\n");

    printf("Simulando Movimentacao de Rainha (Nivel Mestre - Recursivo):\n");
    moverRainhaRecursivo(1, MOVIMENTO_RAINHA);
    printf("\n");

    // --- Nível Aventureiro: Movimentação do Cavalo (Loops Aninhados - For e While) ---
    // Mover o cavalo em L para baixo e para a esquerda.
    // Um movimento de cavalo "em L" pode ser visualizado como (2 para uma direção principal, 1 para uma direção perpendicular).
    // Aqui, 2 para baixo e 1 para a esquerda.
    printf("Simulando Movimentacao do Cavalo (Nivel Aventureiro - Loops Aninhados):\n");
    int numMovimentosL = 2; // Simular 2 movimentos completos em L do cavalo
    for (int i = 0; i < numMovimentosL; i++) {
        printf("  Movimento de Cavalo %d:\n", i + 1);
        int passosParaBaixo = 0;
        // Primeiro, 2 casas para baixo
        while (passosParaBaixo < 2) {
            printf("    Passo %d: Baixo\n", passosParaBaixo + 1);
            passosParaBaixo++;
        }
        // Em seguida, 1 casa para a esquerda
        printf("    Passo 3: Esquerda (na perpendicular)\n");
    }
    printf("\n");

    // --- Nível Mestre: Movimentação do Cavalo com Condições Avançadas (Continue e Break) ---
    // Simula uma série de tentativas de movimento do cavalo, utilizando 'continue' para pular
    // e 'break' para interromper o processo baseado em condições.
    printf("Simulando Movimentacao do Cavalo (Nivel Mestre - com 'continue' e 'break'):\n");
    int totalTentativas = 5;
    int movimentosValidosExecutados = 0;

    for (int i = 1; i <= totalTentativas; i++) {
        printf("  Tentativa de movimento de Cavalo %d: ", i);

        // Exemplo de condição para usar 'continue'
        if (i == 3) {
            printf("Posicao bloqueada ou invalida. Pulando (continue).\n");
            continue; // Pula o restante do loop para esta iteração
        }

        // Simula um movimento em L simples (1 para cima, 2 para direita - apenas para demonstração)
        printf("2 Cima, 1 Direita. ");
        movimentosValidosExecutados++;

        // Exemplo de condição para usar 'break'
        if (movimentosValidosExecutados >= 2) { // Após 2 movimentos válidos
            printf("Numero maximo de movimentos essenciais atingido. Encerrando (break).\n");
            break; // Sai do loop completamente
        }
        printf("Movimento executado.\n");
    }
    printf("Total de movimentos validos de Cavalo executados no Nivel Mestre: %d\n", movimentosValidosExecutados);
    printf("\n");

    printf("--- Desafio Concluido com Sucesso! ---\n");

    return 0; // Indica que o programa foi executado com sucesso.
}