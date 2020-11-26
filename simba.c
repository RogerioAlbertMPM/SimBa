#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simbafunc.h"

typedef struct{
	char nome[30];
	int score;
}jogador;

typedef struct{
	char nome[22];
	FILE* roster;
	jogador TIME[5];	
}franquia;

void iniciaPontos(franquia *time);
void zeraString(char* s);
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
	
	//MENU SimBa
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
	}// FIM MENU SimBa
	
	fclose(home.roster);
	fclose(away.roster);
	return 0;
}

void zeraString(char* s){
	int i = 0;
	while(*(s+i)!='\0'){
		*(s+i) = '\0';
		i++;
	}
}
//INICIA PONTEIROS DOS PONTOS DE CADA JOGADOR
void iniciaPontos(franquia *time){
	int i;
	for(i=0;i<5;i++){
		time->TIME[i].score = 0;
	}
}

void nomeTime(char *time, int escolha, franquia* f){
	switch (escolha){
		case 1:strcpy(time, "./Times/lakers.txt"); 
				strcpy(f->nome, "L. A. LAKERS");
				break;
		case 2:strcpy(time, "./Times/clippers.txt");
				strcpy(f->nome, "L. A. CLIPPERS");
				break;
		case 3:strcpy(time, "./Times/nuggets.txt");
				strcpy(f->nome, "DENVER NUGGETS");
				break;
		case 4:strcpy(time, "./Times/rockets.txt");
				strcpy(f->nome, "HOUSTON ROCKETS");
				break;
		case 5:strcpy(time, "./Times/okc.txt");
				strcpy(f->nome, "OKLAHOMA CITY THUNDER");
				break;
		case 6:strcpy(time, "./Times/jazz.txt");
				strcpy(f->nome, "UTAH JAZZ");
				break;
		case 7:strcpy(time, "./Times/mavericks.txt");
				strcpy(f->nome, "DALLAS MAVERICKS");
				break;
		case 8: strcpy(time, "./Times/trailblazers.txt");
				strcpy(f->nome, "PORTLAND TRAIL BLAZERS");
				break;
		case 9:strcpy(time, "./Times/suns.txt");
				strcpy(f->nome, "PHOENIX SUNS");
				break;
		case 10:strcpy(time, "./Times/bucks.txt");
				strcpy(f->nome, "MILWAUKEE BUCKS");
				break;
		case 11:strcpy(time, "./Times/raptors.txt");
				strcpy(f->nome, "TORONTO RAPTORS");
				break;
		case 12:strcpy(time, "./Times/celtics.txt");
				strcpy(f->nome, "BOSTON CELTICS");
				break;
		case 13:strcpy(time, "./Times/pacers.txt");
				strcpy(f->nome, "INDIANA PACERS");
				break;
		case 14:strcpy(time, "./Times/heat.txt");
				strcpy(f->nome, "MIAMI HEAT");
				break;
		case 15:strcpy(time, "./Times/76ers.txt");
				strcpy(f->nome, "PHILADELPHIA 76ERS");
				break;
		case 16:strcpy(time, "./Times/magic.txt");
				strcpy(f->nome, "ORLANDO MAGIC");
				break;
		default: NULL;
	}
}

void printaTime(FILE *time){
	char s;
	rewind(time);
	while((s=fgetc(time))!=EOF) printf("%c",s);
}
// PRINTA O CONFRONTO ANTES DE COMECAR OS JOGOS
void printaDuelo(franquia time1, franquia time2){
	char s, c;
	int i = 0, pos = 1, enter=0;
	
	printf("\n");

	printf("%s\t", time2.nome);
	if(strlen(time2.nome)<16) printf("\t");
	printf("X\t%s\n\n", time1.nome);
	
	rewind(time1.roster);
	rewind(time2.roster);
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
// DISTRIBUI OS PONTOS GERADOS PACAR CADA JOGADOR
void distribPontos(int pontosPartida,franquia *team){
	int i = 0, k, pontos, j;
	char playerName[30], ppg[3], s;
	char playerFile[13];
	FILE *player;
	
	while(i < 5){
			
		zeraString(playerName);
		k = 0;
		j=0;	
		while((s=fgetc(team->roster))!= '\n'){ //pegar o nome do jogador sem espaco pra poder abrir o arquivo
		 	team->TIME[i].nome[j] = s;
		 	if(s != ' '){
				playerName[k] = s;
				k++;
			}
			j++;
		}
		
		strcpy(playerFile, "./Jogadores/");
		strcat(playerName, ".txt");
		strcat(playerFile, playerName); //colocar o nome certo pro acesso ao arquivo do jogador
		player = fopen(playerFile, "r");
		
		k=0;
		zeraString(ppg);
		while((s=fgetc(player))!= '\n'){
			ppg[k] = s;
			k++;
		}
			
		do{
			pontos = atoi(ppg) + pow(-1, rand())*(rand()%(6+1-0)+0);
			if(atoi(ppg) - 6 >= pontosPartida)pontos = 1;
		}while(pontos > pontosPartida);	

		pontosPartida -= pontos;
		team->TIME[i].score += pontos;
		if(pontosPartida == 0) return;
		
		i++;
	}
	
	rewind(team->roster);
	fclose(player);
	distribPontos(pontosPartida, team);
}
// A SIMULACAO
void gameTime(franquia time1, franquia time2){
	int game = 1,winA = 0,winH = 0,score1,score2;
	int assists1, assists2,rebote1,rebote2,turno1,turno2,steals1,steals2;
	int blocks1,blocks2,fouls1,fouls2;
	int totalPT1 = 0,totalPT2 = 0,totalAS1 = 0,totalAS2 = 0,totalREB1 = 0,totalREB2 = 0;
	int totalTURN1 = 0,totalTURN2 = 0,totalSTL1 = 0,totalSTL2 = 0,totalBLK1 = 0,totalBLK2 = 0,totalFL1 = 0,totalFL2 = 0;
	int FGa1,FGa2,TPa1,TPa2,FTa1,FTa2,FGm1 = 0,FGm2 = 0,TPm1 = 0,TPm2 = 0,FTm1 = 0,FTm2 = 0,TwoPm1 = 0,TwoPm2 = 0;
	srand(time(0));
	//GERA OS PONTOS E AS STATS
	while(winA < 4 || winH < 4){
		printf("===========================================================================================");
		printf("\n");
		printf("\t\t\t\tJOGO %d\n\n",game);
	
		score1 = rand() % (115+1-85)+85;
		score2 = rand() % (115+1-85)+85;
		
		//CASO EMPATE
		while(score1 == score2){
			printf("\t\t\t*******OVERTIME*******\n\n");
			score1 = rand() % ((score1+10) + 1 - score1) + score1;
			score2 = rand() % ((score2+10) + 1 - score2) + score2;		
		}
		
		printf("\t%s \t %d\tX   ", time2.nome, score1);
		printf("%d\t %s\n\n", score2 , time1.nome);
		
		if(score1 > score2){
			winA++;
		}else{
			winH++;
		}
		//GERA AS STATS FORA PONTOS
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
		FGa1 = 88 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);		
		FGa2 = 88 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
		FTa1 = 22 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
		FTa2 = 22 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
		TPa1 = (FGa1*38)/100;		
		TPa2 = (FGa2*38)/100;
		
		printf("OPAAAA\n");		
		while(TwoPm1*2 + TPm1*3 + FTm1 <= score1){
			FGm1 = 41 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
			FTm1 = 17 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
			TPm1 = (FGm1*28)/100;
			TwoPm1 = FGm1 - TPm1;
		} 
		printf("OPAAAAA2\n");
		while(TwoPm2*2 + TPm2*3 + FTm2 <= score2){
			FGm2 = 41 + pow(-1,rand())*(rand() % (4 + 1 - 0) + 0);
			FTm2 = 17 + pow(-1,rand())*(rand() % (2 + 1 - 0) + 0);
			TPm2 = (FGm2*28)/100;
			TwoPm2 = FGm2 - TPm2;
		} 		
		if(((TwoPm1*2 + TPm1*3 + FTm1)-score1) % 10 == 0){			
			TwoPm1 -= (((TwoPm1*2 + TPm1*3 + FTm1)-score1)/10) * 2;
			TPm1 -= (((TwoPm1*2 + TPm1*3 + FTm1)-score1)/10) * 2;			
		}else{
			FTm1 -= ((TwoPm1*2 + TPm1*3 + FTm1)-score1) - (10 * (((TwoPm1*2 + TPm1*3 + FTm1)-score1)/10));
			TwoPm1 -= (((TwoPm1*2 + TPm1*3 + FTm1)-score1)/10) * 2;
			TPm1 -= (((TwoPm1*2 + TPm1*3 + FTm1)-score1)/10) * 2;
		}
		if(((TwoPm2*2 + TPm2*3 + FTm2)-score2) % 10 == 0){			
			TwoPm2 -= (((TwoPm2*2 + TPm2*3 + FTm2)-score2)/10) * 2;
			TPm2 -= (((TwoPm2*2 + TPm2*3 + FTm2)-score2)/10) * 2;			
		}else{
			FTm2 -= ((TwoPm2*2 + TPm2*3 + FTm2)-score2) - (10 * (((TwoPm2*2 + TPm2*3 + FTm2)-score2)/10));
			TwoPm2 -= (((TwoPm2*2 + TPm2*3 + FTm2)-score2)/10) * 2;
			TPm2 -= (((TwoPm2*2 + TPm2*3 + FTm2)-score2)/10) * 2;
		}
		printf("\tASSISTS1 = %d\t\t ASSISTS2 = %d\n\n",assists1,assists2);
		printf("\tREBOUNDS1 = %d\t\t REBOUNDS2 = %d\n\n",rebote1,rebote2);
		printf("\tTURNOVER1 = %d\t\t TURNOVER2 = %d\n\n",turno1,turno2);
		printf("\tSTEALS1 = %d\t\t STEALS2 = %d\n\n",steals1,steals2);
		printf("\tBLOCKS1 = %d\t\t BLOCKS2 = %d\n\n",blocks1,blocks2);
		printf("\tFOULS1 = %d\t\t FOULS2 = %d\n\n",fouls1,fouls2);
		printf("\tFGA1 = %d\t\t FGA2 = %d\n\n",FGa1,FGa2);
		printf("\tFTa1 = %d\t\t FTa2 = %d\n\n",FTa1,FTa2);
		printf("\tTPa1 = %d\t\t TPa2 = %d\n\n",TPa1,TPa2);
		printf("\tFGm1 = %d\t\t FGm2 = %d\n\n",FGm1,FGm2);
		printf("\t2Pm1 = %d\t\t 2Pm2 = %d\n\n",TwoPm1,TwoPm2);
		printf("\tFTm1 = %d\t\t FTm2 = %d\n\n",FTm1,FTm2);
		printf("\t3Pm1 = %d\t\t 3Pm2 = %d\n\n",TPm1,TPm2);
		
		//RESETA PONTEIRO DOS ARQUIVOS DOS TIMES
		rewind(time1.roster);
		rewind(time2.roster);
		//INICIA PARA CONTAGEM DE PONTOS INDIVIDUAIS
		iniciaPontos(&time1);
		iniciaPontos(&time2);
		//DRISTRIBUIR OS PONTOS ENTRE OS JOGADORES
		distribPontos(score1, &time1);
		distribPontos(score2, &time2);
		
		for(int r = 0; r<5;r++) printf("\t%s --- %d\tPONTOS\t%s --- %d\n", time1.TIME[r].nome, time1.TIME[r].score, time2.TIME[r].nome, time2.TIME[r].score);
		
		//ACOMPANHAMENTO DAS STATS JOGO POR JOGO
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
		 
		//CONDICAO DE VITORIA + STATS GERAIS
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

