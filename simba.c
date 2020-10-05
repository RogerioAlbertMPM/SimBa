#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nomeTime(char *time, int escolha);
void printaTime(FILE *time);
void printaDuelo(FILE *time1, FILE *time2);

int main(){
	int opcao, time1, time2;
	char hTeam[17], aTeam[17], c;
	FILE *home, *away;
	printf("#####||| SimBa |||######\n~Simulador de Basquete~\n");
	
	printf("\n[1] JOGAR\n[2] SOBRE O JOGO\n[3] SAIR\n");
	
	while(1){
		printf("\n-> Opção: ");
		scanf("%d", &opcao);
		if(opcao == 3) return 0;
		
		if(opcao == 2){
			continue;
		}
		
		printf("Escolha os times: \n\n");
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
		case 1: strcpy(time, "lakers.txt");break;
		case 2: strcpy(time, "clippers.txt");break;
		case 3: strcpy(time, "nuggets.txt");break;
		case 4: strcpy(time, "rockets.txt");break;
		case 5: strcpy(time, "okc.txt");break;
		case 6: strcpy(time, "jazz.txt");break;
		case 7: strcpy(time, "mavericks.txt");break;
		case 8: strcpy(time, "trailblazers.txt");break;
		case 9: strcpy(time, "suns.txt");break;
		case 10: strcpy(time, "bucks.txt");break;
		case 11: strcpy(time, "raptors.txt");break;
		case 12: strcpy(time, "celtics.txt");break;
		case 13: strcpy(time, "pacers.txt");break;
		case 14: strcpy(time, "heat.txt");break;
		case 15: strcpy(time, "76ers.txt");break;
		case 16: strcpy(time, "magic.txt");break;
		default: NULL;
	}
}

void printaTime(FILE *time){
	char s;
	while((s=fgetc(time))!=EOF) printf("%c",s);
}

void printaDuelo(FILE *time1, FILE *time2){
	char s, c;
	
	while(1){
		if(s == EOF) break;
		s = fgetc(time2);
		if(s != '\n'){
			printf("%c", s);
			continue;
		}
		printf("\t\t\t\t");
		c = fgetc(time1);
		while(c!='\n'){	
			printf("%c", c);
			c = fgetc(time1);
		}
		printf("\n");
	}
}



























