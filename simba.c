#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nomeTime(char *time, int escolha);
void printaTime(FILE *time);
void printaDuelo(FILE *time1, FILE *time2);

int main(){
	int opcao, time1, time2;
	char hTeam[17], aTeam[17];
	FILE *home, *away;
	printf("#####||| SimBa |||######\n ~Simulador de Basquete~\n");
	
	printf("\n[1] JOGAR\n[2] SOBRE O JOGO\n[3] SAIR\n");
	
	while(1){
		printf("\n-> Opção: ");
		scanf("%d", &opcao);
		if(opcao == 3){
			printf("\n\nOBRIGADO POR JOGAR SIMBA!!!! AGRADECEMOS SEU FEEDABACK!!!!\n\n");
			return 0;
		}
		if(opcao == 2){
			printf("### Criado por Rogerio Albert e Victor Ferraz ###\n\nO SimBa ira simular uma serie melhor de 7 entre 2 times de basquete da NBA de sua escolha.\n");
			printf("Primeiro, escolha os times e veja a magica acontecer! O SimBa ira mostrar todas a base de dados ");
			printf("de cada time escolhido no decorrer da serie.\nHighlights surpresa que podem acontecer de maneira aleatoria.\n");
			printf("Depois que a simulacao terminar, voce podera escolher com quais times a proxima serie sera!\n");
			printf("Agora, selecione uma opcao do menu (1) para jogar ou (3) para sair\n\n");
			
			continue;
		}
		
		printf("\nEscolha os times: \n\n");
		printf("  #CONF. OESTE\t\t\t  #CONF. LESTE\n");
		printf("(1) L.A. Lakers\t\t\t(10) Milwaukee Bucks\n(2) L.A. Clippers\t\t(11) Toronto Raptors\n(3) Denver Nuggets\t\t(12) Boston Celtics\n(4) Houston Rockets\t\t(13) Indiana Pacers\n(5) Oklahoma City Thunder\t(14) Miami Heat\n(6) Utah Jazz\t\t\t(14) Philadelphia 76ers\n(7) Dallas Mavericks\t\t(15) Orlando Magic\n(8) Portland Trail Blazers\n(9) Phoenix Suns\n");
		printf("\n-> Time da casa: ");
		scanf("%d", &time1);
		do{
			if(time2 == time1) printf("!!! Os times devem ser diferentes !!!\n");
			printf("-> Time visitante: ");
			scanf("%d", &time2);
		}while(time2 == time1);
		
		nomeTime(hTeam, time1); 
		nomeTime(aTeam, time2);
		
		home = fopen(hTeam, "r");
		away = fopen(aTeam, "r");
		
		printaDuelo(home, away);
	}
	
	fclose(home);
	fclose(away);
	return 0;
}
void nomeTime(char *time, int escolha){
	switch (escolha){
		case 1: strcpy(time, "./Times/lakers.txt");break;
		case 2: strcpy(time, "./Times/clippers.txt");break;
		case 3: strcpy(time, "./Times/nuggets.txt");break;
		case 4: strcpy(time, "./Times/rockets.txt");break;
		case 5: strcpy(time, "./Times/okc.txt");break;
		case 6: strcpy(time, "./Times/jazz.txt");break;
		case 7: strcpy(time, "./Times/mavericks.txt");break;
		case 8: strcpy(time, "./Times/trailblazers.txt");break;
		case 9: strcpy(time, "./Times/suns.txt");break;
		case 10: strcpy(time, "./Times/bucks.txt");break;
		case 11: strcpy(time, "./Times/raptors.txt");break;
		case 12: strcpy(time, "./Times/celtics.txt");break;
		case 13: strcpy(time, "./Times/pacers.txt");break;
		case 14: strcpy(time, "./Times/heat.txt");break;
		case 15: strcpy(time, "./Times/76ers.txt");break;
		case 16: strcpy(time, "./Times/magic.txt");break;
		default: NULL;
	}
}

void printaTime(FILE *time){
	char s;
	while((s=fgetc(time))!=EOF) printf("%c",s);
}

void printaDuelo(FILE *time1, FILE *time2){
	char s, c;
	int i = 0;
	
	while(1){
		s = fgetc(time2);
		if(s != '\n'){
			if(s == EOF) break;
			printf("%c", s);
			i++;
			continue;
		}
		printf("\t\t\t");
		if(i<16) printf("\t");
		i=0;
		c = fgetc(time1);
		while(c!='\n'){	
			printf("%c", c);
			c = fgetc(time1);
		}
		printf("\n");
	}
}

