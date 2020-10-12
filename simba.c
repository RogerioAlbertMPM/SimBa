#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[22];
	FILE* roster;
}franquia;

void nomeTime(char *time, int escolha, franquia* f);
void printaTime(FILE *time);
void printaDuelo(franquia time1, franquia time2);


int main(){
	int opcao, time1, time2;
	char hTeam[17], aTeam[17], c;
	franquia home, away;
	printf("#####||| SimBa |||######\n ~Simulador de Basquete~\n");
	
	printf("\n[1] JOGAR\n[2] SOBRE O JOGO\n[3] SAIR\n");
	
	while(1){
		printf("\n-> Opção: ");
		scanf("%d", &opcao);
		if(opcao == 3) return 0;
		
		if(opcao == 2){
			continue;
		}
		
		printf("\nEscolha os times: \n\n");
		printf("  #CONF. OESTE\t\t\t  #CONF. LESTE\n");
		printf("(1) L.A. Lakers\t\t\t(10) Milwaukee Bucks\n(2) L.A. Clippers\t\t(11) Toronto Raptors\n(3) Denver Nuggets\t\t(12) Boston Celtics\n(4) Houston Rockets\t\t(13) Indiana Pacers\n(5) Oklahoma City Thunder\t(14) Miami Heat\n(6) Utah Jazz\t\t\t(15) Philadelphia 76ers\n(7) Dallas Mavericks\t\t(16) Orlando Magic\n(8) Portland Trail Blazers\n(9) Phoenix Suns\n");
		printf("\n-> Time da casa: ");
		scanf("%d", &time1);
		do{
			if(time2 == time1) printf("!!! Os times devem ser diferentes !!!\n");
			printf("-> Time visitante: ");
			scanf("%d", &time2);
		}while(time2 == time1);
		
		nomeTime(hTeam, time1, &home); 
		nomeTime(aTeam, time2, &away);
		
		home.roster = fopen(hTeam, "r");
		away.roster = fopen(aTeam, "r");
		
		printaDuelo(home, away);
	}
	
	fclose(home.roster);
	fclose(away.roster);
	return 0;
}

void nomeTime(char *time, int escolha, franquia* f){
	int i;
	switch (escolha){
		case 1: strcpy(time, "./Times/lakers.txt"); strcpy(f->nome, "L. A. LAKERS");break;
		case 2: strcpy(time, "./Times/clippers.txt");strcpy(f->nome, "L. A. CLIPPERS");break;
		case 3: strcpy(time, "./Times/nuggets.txt");strcpy(f->nome, "DENVER NUGGETS");break;
		case 4: strcpy(time, "./Times/rockets.txt");strcpy(f->nome, "HOUSTON ROCKETS");break;
		case 5: strcpy(time, "./Times/okc.txt");strcpy(f->nome, "OKLAHOMA CITY THUNDER");break;
		case 6: strcpy(time, "./Times/jazz.txt");strcpy(f->nome, "UTAH JAZZ");break;
		case 7: strcpy(time, "./Times/mavericks.txt");strcpy(f->nome, "DALLAS MAVERICKS");break;
		case 8: strcpy(time, "./Times/trailblazers.txt");strcpy(f->nome, "PORTLAND TRAIL BLAZERS");break;
		case 9: strcpy(time, "./Times/suns.txt");strcpy(f->nome, "PHOENIX SUNS");break;
		case 10: strcpy(time, "./Times/bucks.txt");strcpy(f->nome, "MILWAUKEE BUCKS");break;
		case 11: strcpy(time, "./Times/raptors.txt");strcpy(f->nome, "TORONTO RAPTORS");break;
		case 12: strcpy(time, "./Times/celtics.txt");strcpy(f->nome, "BOSTON CELTICS");break;
		case 13: strcpy(time, "./Times/pacers.txt");strcpy(f->nome, "INDIANA PACERS");break;
		case 14: strcpy(time, "./Times/heat.txt");strcpy(f->nome, "MIAMI HEAT");break;
		case 15: strcpy(time, "./Times/76ers.txt");strcpy(f->nome, "PHILADELPHIA 76ERS");break;
		case 16: strcpy(time, "./Times/magic.txt");strcpy(f->nome, "ORLANDO MAGIC");break;
		default: NULL;
	}
}

void printaTime(FILE *time){
	char s;
	while((s=fgetc(time))!=EOF) printf("%c",s);
}

void printaDuelo(franquia time1, franquia time2){
	char s, c;
	int i = 0, pos = 1, enter=0;
	
	printf("\n");
	
	printf("\t%s \t\tX\t", time2.nome);
	if(strlen(time2.nome) < 16) printf("\t");
	printf("%s\n\n", time1.nome);
	
	while(1){
		s = fgetc(time2.roster);
		if(s != '\n'){
			if(s == EOF) break;
			
			printf("%c", s);
			i++;
			continue;
		}
		pos++;
		printf("\t\t\t");
		if(i<16) printf("\t");
		i=0;
		c = fgetc(time1.roster);
		while(c!='\n'){	
			printf("%c", c);
			c = fgetc(time1.roster);
		}
		printf("\n");
	}
}

