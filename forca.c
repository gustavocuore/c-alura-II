#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

// C:\Users\gusta\Documents\Alura\Linguagem C\forca.exe

//variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {

	printf("****************************\n");
	printf("*       JOGO DE FORCA      *\n");
	printf("****************************\n\n");
}

void chuta() {
	char chute;
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;

}

void desenhaforca() {

	int erros = chuteserrados();

	printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c   \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 6 ? '/' : ' '), (erros >= 7 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

	for(int i = 0; i < strlen(palavrasecreta); i++) {
		
		int achou = jachutou(palavrasecreta[i]);
		if(achou) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}

	printf("\n");
}

void adicionapalavra() {
	
	char quer;
	
	printf("Você deseja adicionar uma nova palavra no jogo? (S/N)");
	scanf(" %c", &quer);

	if(quer == 'S') {

		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra?");
		scanf("%s", novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "r+"); //fopen diz qual arquivo eu quero abrir -> r é para apenas ler ; r+ é para ler e escrever
		if(f==0) {
			printf("Desculpe, banco de dados não disponível.\n\n");
			exit(1);
		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET); //fseek serve para posicionar a cabeça do arquivo daonde ele vai começar a ler ou escrever
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END); //SEEK SET -> ESCREVER NO COMEÇO DO ARQUIVO     SEEK END -> ESCREVER NO FINAL DO ARQUIVO
		fprintf(f, "\n%s", novapalavra); //IGUAL PRINTF mas recebe arquivo no começo

		fclose(f);
	}
}

void escolhepalavra() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f==0) {
		printf("Desculpe, banco de dados não disponível.\n\n");
		exit(1);
	}

	int qtddepalavras;
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavrasecreta);
	}


	fclose(f);
}

int acertou() {
	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}

	return 1;
}

int chuteserrados() {
	int erros = 0;
	
	for(int i = 0; i < chutesdados; i++) {
		int existe = 0;

		for(int j = 0; j < strlen(palavrasecreta); j++) {
			if(chutes[i] == palavrasecreta[j]) {
				existe = 1;
				break;
			}
		}

		if(!existe) erros++;
	}

	return erros;
}

int enforcou() {

	return chuteserrados() >= 7;
}

int jachutou(char letra) {
	int achou = 0;

	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

int main() {

	escolhepalavra();
	abertura();

	do {
		
		desenhaforca();
		chuta();

	} while(!acertou() && !enforcou());

	if(acertou()) {
		printf("\nParabéns, você ganhou!\n\n");

		printf("       ____________     \n");
		printf("       '._==_==_=_.'    \n");
		printf("       .-\\:      /-.   \n");
		printf("      | (|:.     |) |   \n");
		printf("       '-|:.     |-'    \n");
		printf("         \\::.    /     \n");
		printf("          '::.  .'      \n");
		printf("            ) (         \n");
		printf("            ' '         \n");
		printf("          -'   '-       \n");
		printf("         '-------'      \n\n");

	} else {
		printf("\nPuxa, você foi enforcado!\n");
		printf("A palavra era **%s**\n\n", palavrasecreta);

		printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
	}

	adicionapalavra();
	
}