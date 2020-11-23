#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simbafunc.h"

typedef struct{
	char nome[22];
	FILE* roster;
}franquia;

void nomeTime(char *time, int escolha, franquia* f);
void printaTime(FILE *time);
void printaDuelo(franquia time1, franquia time2);
void gameTime(franquia time1, franquia time2);
int main(){
	int opcao, time1, time2;
	char hTeam[17], aTeam[17];
	franquia home, away;
	printf("#####||| SimBa |||######\n ~Simulador de Basquete~\n");
	
	printf("\n[1] JOGAR\n[2] SOBRE O JOGO\n[3] SAIR\n");
	
	while(1){
		printf("\n-> Opção: ");
		scanf("%d", &opcao);
		if(opcao == 3){
			printf("\nOBRIGADO POR JOGAR SimBa!!!! AGRADECEMOS SEU FEEDABACK!!!!\n\n");
			return 0;
		}
		if(opcao == 2){
			printf("\n### Criado por Rogerio Albert e Victor Ferraz ###\n\nO SimBa irá simular uma série melhor de 7 entre 2 times de basquete da NBA de sua escolha.\n");
			printf("Primeiro, escolha os times e veja a mágica acontecer!\nO SimBa irá mostrar todas a base de dados ");
			printf("de cada time escolhido no decorrer da série.\nHighlights surpresa que podem acontecer de maneira aleatória.\n");
			printf("Depois que a simulação terminar, você poderá escolher com quais times a próxima série será!\n");
			printf("Agora, selecione uma opção do menu, [1] para jogar ou [3] para sair.\n");
			
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
		gameTime(home, away);
		break;
	}
	
	fclose(home.roster);
	fclose(away.roster);
	return 0;
}

void nomeTime(char *time, int escolha, franquia* f){
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

	printf("%s\t", time2.nome);
	if(strlen(time2.nome)<16) printf("\t");
	printf("X\t%s\n\n", time1.nome);
	
	while(1){
		s = fgetc(time2.roster);
		if(s != '\n'){
			if(s == EOF) break;		
			printf("%c", s);
			i++;
			continue;
		}
		printf("\t");
		if(i<16) printf("\t");
		i=0;
		
		switch(pos){
			case 1: printf("SG\t");break;
			case 2: printf("PG\t");break;
			case 3: printf("SF\t");break;
			case 4: printf("PF\t");break;
			case 5: printf("C\t");break;
			default: NULL;
		}
		pos++;
		
		c = fgetc(time1.roster);
		while(c!='\n'){	
			printf("%c", c);
			c = fgetc(time1.roster);
		}
		printf("\n");
	}
}
void gameTime(franquia time1, franquia time2){
	//char s, c;
	//int i = 0, pos = 1, enter=0;
	int game = 1,winA = 0,winH = 0,score1,score2;
	int assists1, assists2,rebote1,rebote2,turno1,turno2,steals1,steals2;
	int blocks1,blocks2,fouls1,fouls2;
	int totalPT1 = 0,totalPT2 = 0,totalAS1 = 0,totalAS2 = 0,totalREB1 = 0,totalREB2 = 0;
	int totalTURN1 = 0,totalTURN2 = 0,totalSTL1 = 0,totalSTL2 = 0,totalBLK1 = 0,totalBLK2 = 0,totalFL1 = 0,totalFL2 = 0;
	
	srand(time(0));
	
	while(winA < 4 || winH < 4){
		printf("===========================================================================================");
		printf("\n");
		printf("\t\t\t\tJOGO %d\n\n",game);
	
		score1 = rand() % (115+1-85)+85;
		score2 = rand() % (115+1-85)+85;
	
		while(score1 == score2){
			printf("\t\t\t*******OVERTIME*******\n\n");
			score1 = rand() % ((score1+10) + 1 - score1) + score1;
			score2 = rand() % ((score2+10) + 1 - score2) + score2;		
		}
		printf("\t%s \t %d\tX   ", time2.nome, score1);
		
		//if(strlen(time2.nome) < 16) printf("\t");
		printf("%d\t %s\n\n", score2 , time1.nome);
		
		if(score1 > score2){
			winA++;
		}else{
			winH++;
		}
		assists1 = 24 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
		assists2 = 24 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
		rebote1 = 45 + pow(-1,rand())*(rand() % (6 + 1 - 0) + 0);
		rebote2 = 45 + pow(-1,rand())*(rand() % (6 + 1 - 0) + 0);
		turno1 = 15 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		turno2 = 15 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		steals1 = 8 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		steals2 = 8 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		blocks1 = 5 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		blocks2 = 5 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
		fouls1 = 21 + pow(-1,rand())*(rand() % (3 + 1 - 0) + 0);
		fouls2 = 21 + pow(-1,rand())*(rand() % (3 + 1 - 0) + 0);
		
		printf("\tASSISTS1 = %d\t\t ASSISTS2 = %d\n\n",assists1,assists2);
		printf("\tREBOUNDS1 = %d\t\t REBOUNDS2 = %d\n\n",rebote1,rebote2);
		printf("\tTURNOVER1 = %d\t\t TURNOVER2 = %d\n\n",turno1,turno2);
		printf("\tSTEALS1 = %d\t\t STEALS2 = %d\n\n",steals1,steals2);
		printf("\tBLOCKS1 = %d\t\t BLOCKS2 = %d\n\n",blocks1,blocks2);
		printf("\tFOULS1 = %d\t\t FOULS2 = %d\n\n",fouls1,fouls2);
		
		totalPT1 += score1;
		totalPT2 += score2; 
		totalAS1 += assists1; 
		totalAS2 += assists2; 
		totalREB1 += rebote1; 
		totalREB2 += rebote2; 
		totalTURN1 += turno1; 
		totalTURN2 += turno2; 
		totalSTL1 += steals1; 
		totalSTL2 += steals2; 
		totalBLK1 += blocks1; 
		totalBLK2 += blocks2; 
		totalFL1 += fouls1; 
		totalFL2 += fouls2; 
		 
		
		if(winA == 4){
			printf("===========================================================================================\n");
			printf("\t\t%s GANHOU (%d-%d)\n",time2.nome,winA,winH);
			
			printf("\tPPG1: %.1f\t\t PPG2: %.1f\n\n",(totalPT1*1.0)/game,(totalPT2*1.0)/game);
			printf("\tAPG1: %.1f\t\t APG2: %.1f\n\n",Assists(totalAS1,game),Assists(totalAS2,game));
			printf("\tREB1: %.1f\t\t REB2: %.1f\n\n",Rebounds(totalREB1,game),Rebounds(totalREB2,game));
			printf("\tTO1: %.1f\t\t TO2: %.1f\n\n",Turnovers(totalTURN1,game),Turnovers(totalTURN2,game));
			printf("\tSTL1: %.1f\t\t STL2: %.1f\n\n",Steals(totalSTL1,game),Steals(totalSTL2,game));
			printf("\tBLK1: %.1f\t\t BLK2: %.1f\n\n",Blocks(totalBLK1,game),Blocks(totalBLK2,game));
			printf("\tPF1: %.1f\t\t PF2: %.1f\n\n",TeamFouls(totalFL1,game),TeamFouls(totalFL2,game));
			printf("===========================================================================================\n");
			break;
		}else if(winH == 4){
			printf("===========================================================================================\n");
			printf("\t\t%s GANHOU (%d-%d)\n",time1.nome,winH,winA);
			
			printf("\tPPG1: %.1f\t\t PPG2: %.1f\n\n",(totalPT1*1.0)/game,(totalPT2*1.0)/game);
			printf("\tAPG1: %.1f\t\t APG2: %.1f\n\n",Assists(totalAS1,game),Assists(totalAS2,game));
			printf("\tREB1: %.1f\t\t REB2: %.1f\n\n",Rebounds(totalREB1,game),Rebounds(totalREB2,game));
			printf("\tTO1: %.1f\t\t TO2: %.1f\n\n",Turnovers(totalTURN1,game),Turnovers(totalTURN2,game));
			printf("\tSTL1: %.1f\t\t STL2: %.1f\n\n",Steals(totalSTL1,game),Steals(totalSTL2,game));
			printf("\tBLK1: %.1f\t\t BLK2: %.1f\n\n",Blocks(totalBLK1,game),Blocks(totalBLK2,game));
			printf("\tPF1: %.1f\t\t PF2: %.1f\n\n",TeamFouls(totalFL1,game),TeamFouls(totalFL2,game));
			printf("===========================================================================================\n");
			break;	
		}
		game++;
		
	}
}
// 54.7field goals attempt per game
// 28.7 field goals made per game
// == 52.4% shots made
// 34.1 3-point attempt
// 12.2 3-point made
// == 35.8% 3-point
// 23.1 free throw attempt
// 17.9 free throw made
// 77.3% free throw made
// 44.8 reb per game - finished
// 24.4 assists per game - finished
// 14.5 turnover per game - finished
// 7.6 steals per game - finished
// 4.9 blocks per game - finished
// 20.8 team fouls per game - finished

// caracteristica geral individual: Dividir jogo a jogo pra cada jogador
// usar recursividade + arquivo pra cada jogador



























