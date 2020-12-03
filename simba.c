#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simbafunc.h"

int main(){
	int time1, time2,opcao;
	char hTeam[17], aTeam[17];
	franquia home, away;

	
		printf("#####||| SimBa |||######\n ~Simulador de Basquete~\n");
		
		
		time1 = 0;
		time2 = -1;
			
		printf("\n[1] JOGAR\n[2] SOBRE O JOGO\n[3] SAIR\n");
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
			printf("Depois que a simulação terminar, você poderá escolher com quais times a próxima série será!\n\n");
			printf("\t\t########## LEGENDAS ##########\n\n");
			printf("\tPPG1/PPG2: Pontos por jogo do time 1/2;\n\n\tAPG1/APG2: Assistencias por jogo do time 1/2;\n\n");
			printf("\tREB1/REB2: Rebotes por jogo do time 1/2;\n\n\tTO1/TO2: Turnovers por jogo do time 1/2;\n\n");
			printf("\tSTL1/STL2: Roubos de bola por jogo do time 1/2;\n\n\tBLK1/BLK2: Tocos por jogo do time 1/2;\n\n");
			printf("\tPF1/PF2: Faltas por jogo do time 1/2;\n\n\tFGa1/FGa2: Arremessos tentados por jogo do time 1/2;\n\n");
			printf("\tFTa1/FTa2: Lances livres tentados por jogo do time 1/2;\n\n");
			printf("\tTPa1/TPa2: Arremessos de 3 pontos tentados pelo time 1/2;\n\n");
			printf("\tFGm1/FGm2: Arremessos acertados por jogo do time 1/2;\n\n");
			printf("\tFTm1/FTm2: Lances livres acertados por jogo do time 1/2;\n\n");
			printf("\tTPm1/TPm2: Arremessos de 3 pontos acertados pelo time 1/2;\n\n");
			printf("\tASSISTS1/ASSISTS2: Assistencias no jogo N do time 1/2;\n\n\tREBOUNDS1/REBOUNDS2: Rebotes no jogo N do time 1/2;\n\n");
			printf("\tTURNOVER1/TURNOVER2: Turnovers no jogo N do time 1/2\n\n\tSTEALS1/STEALS2: Roubos de bola no jogo N do time 1/2;\n\n");
			printf("\tBLOCKS1/BLOCKS2: Tocos no jogo N do time 1/2;\n\n\tFOULS1/FOULS2: Faltas no jogo N do time 1/2;\n\n");
			printf("Agora, selecione uma opção do menu, [1] para jogar ou [3] para sair.\n");
			
			printf("\n[1] JOGAR\n[3] SAIR\n");
			printf("\n-> Opção: ");
			scanf("%d", &opcao);
			if(opcao == 3) return 0;
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
		
		nomes(&home);
		nomes(&away);
			
		printaDuelo(home, away);
		gameTime(home, away);
		
		fclose(home.roster);
		fclose(away.roster);
	
	return 0;
}
