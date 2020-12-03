//TAD das funcoes do SimBa
typedef struct{
	char nome[30];
	int score, assists, rebounds, steals, blocks, turnovers;
}jogador;

typedef struct{
	char nome[22];
	FILE* roster;
	jogador TIME[5];	
}franquia;
int opcao;
//FUNCOES QUE VAO FICAR RODANDO
void menu();
void menu2(franquia time1,franquia time2,int game,int totalPT1,int totalPT2,int totalAS1,int totalAS2,int totalREB1,int totalREB2,int totalTURN1,int totalTURN2,int totalSTL1,int totalSTL2,int totalBLK1,int totalBLK2,int totalFL1,int totalFL2,int totalFGa1,int totalFGa2,int totalFTa1,int totalFTa2,int totalTPa1,int totalTPa2,int totalFGm1,int totalFGm2,int totalFTm1,int totalFTm2,int totalTPm1,int totalTPm2);
void distribBloqueios(int bloqueiosPartida,franquia *team);
void distribTurns(int turnosPartida,franquia *team);
void distribRebotes(int rebotesPartida,franquia *team);
void iniciaPontos(franquia *time);
void zeraString(char* s);
void distribRoubos(int roubosPartida,franquia *team);
void distribPontos(int pontosPartida,franquia *team);
void distribAssistencias(int assitenciasPartida,franquia *team);
void nomeTime(char *time, int escolha, franquia* f);
void printaTime(FILE *time);
void printaDuelo(franquia time1, franquia time2);
void gameTime(franquia time1, franquia time2);
//FUNCOES PARA ESTATISTICAS ESPECIFICAS
float FieldGoalMade(int shotsmade, int totalgames);
float FieldGoalAtp(int shots, int totalgames);
float FieldGoalPercent(int shotsmade, int fga);
float ThreePointers(int threepointmade, int totalgames);
float ThreePointAtp(int threepoint, int totalgames);
float ThreePointPercent(int threepointmade, int tpa);
float FreeThrowsMade(int ftmade, int totalgames);
float FreeThrowAtp(int fts, int totalgames);
float FreeThrowPercent( int ftmade,int fta);
float Assists(int assist, int totalgames);
float Rebounds(int reb, int totalgames);
float Turnovers(int turnov,int totalgames);
float Steals(int steal, int totalgames);
float Blocks(int block, int totalgames);
float TeamFouls(int fouls, int totalgames);
