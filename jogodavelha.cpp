#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int jogada = 1;
int posicao = 0;
int escolha;
int quantidadeJogadores = 1;

int menu(){
	int escolha;
	
	printf("\nEscolha um modo");
	printf("\n1-Jogador X Jogador");
	printf("\n2-Jogador X Computador");
	printf("\n3-Sair\n");
	scanf("%d",&escolha);
	return escolha;			
}


void imprimirTabuleiro() {
	system("cls");
	printf("----------Cordenadas----------\n");
    printf("\t  7 | 8 | 9\n");
    printf("\t  ---------\n");
    printf("\t  4 | 5 | 6\n");
    printf("\t  ---------\n");
    printf("\t  1 | 2 | 3\n\n");

	printf("----------Tabuleiro----------\n\n");
    for (int i = 0; i < 3; i++) {
        printf("\t  %c | %c | %c\n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) {
            printf("\t  ---------\n");
        }
    }
    printf("\n");
}

int verificarVitoria() {
    // Verifique todas as possibilidades de vitória
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1; // Vitória na linha
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1; // Vitória na coluna
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1; // Vitória na diagonal principal
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1; // Vitória na diagonal secundária
    }
    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda há espaços vazios, o jogo não está empatado
            }
        }
    }
    return 1; // O jogo está empatado
}

int fazerJogada(int posicao) {
    int linha = (9 - posicao) / 3;
    int coluna = (posicao - 1) % 3;
    
    	if (tabuleiro[linha][coluna] == ' ') {
        	if (jogada % 2 == 1) {
           	 tabuleiro[linha][coluna] = 'X';
        	} else {
        	    tabuleiro[linha][coluna] = 'O';
       	 	}
       		 jogada++;
       	 return 1; // Jogada válida
    	} 	else {
        	return 0; // Jogada inválida
    		}
	}
void iniciarJogo(){
	int vitoria = 0;  
	    while (1) {
	    imprimirTabuleiro();
	if(quantidadeJogadores == 1){
  
        if (jogada % 2 == 1) {
            printf("Jogador X, digite a posição desejada (1-9): ");
        } else {
            printf("Jogador O, digite a posição desejada (1-9): ");
        }
        scanf("%d", &posicao);
        
    }else{
    	
    	if (jogada % 2 == 1) {
            printf("Jogador X, digite a posição desejada (1-9): ");
            scanf("%d", &posicao);
            
        } else {
        	srand(time(NULL));	
        	posicao = rand() % 9;
        		
	}      
        if (posicao < 1 || posicao > 9) {
            printf("Posição inválida! Digite um número de 1 a 9.\n");
            continue;
        }

        if (fazerJogada(posicao)) {
            imprimirTabuleiro();
            vitoria = verificarVitoria();
            if (vitoria) {
                if (jogada % 2 == 1) {
                    printf("Jogador O venceu!\n");
                } else {
                    printf("Jogador X venceu!\n");
                }
                break;
            }
            if (verificarEmpate()) {
                printf("O jogo empatou!\n");
                break;
            }
        } else {
            printf("Posição já ocupada! Tente novamente.\n");
        }
   	 }	
	}
}
	
int main() {
    setlocale(LC_ALL , "Portuguese");	
	printf("Bem-vindo ao Jogo da Velha!\n");
 
  while(escolha !=3){
	
  quantidadeJogadores = 1;
  
    switch(menu()){
    	
    	case 1:
    		iniciarJogo();
    		break;
    		
    	case 2:
			quantidadeJogadores++;
			iniciarJogo();
			break;
			
		case 3:
			abort();
			break;		
	}
 } 	
}