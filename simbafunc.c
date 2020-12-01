#include <stdio.h>
#include "simbafunc.h"

//Total made shots oth­er than free throws divid­ed by games played.
float FieldGoalMade(int shotsmade, int totalgames){
	return (shotsmade*1.0)/totalgames;
}
//Total shots attempt­ed oth­er than free throws divid­ed by games played .
float FieldGoalAtp(int shots, int totalgames){
	return (shots*1.0)/totalgames;
}
//Total shots made oth­er than free throws divid­ed by field goal attempts.
float FieldGoalPercent(int shotsmade, int fga){
	return (shotsmade/fga)*100;
}
//Total 3-point­ers made divid­ed by games played.
float ThreePointers(int threepointmade, int totalgames){
	return (threepointmade*1.0)/totalgames;
}
//Total 3-point­ers attempt­ed divid­ed by games played.
float ThreePointAtp(int threepoint, int totalgames){
	return (threepoint*1.0)/totalgames;
}
//Total 3-point shots made divid­ed by 3-point field goal attempts.
float ThreePointPercent(int threepointmade, int tpa){
	return (threepointmade/tpa)*100;
}
//Total free throws made divid­ed by games played.
float FreeThrowsMade(int ftmade, int totalgames){
	return (ftmade*1.0)/totalgames;
}
//Total free throws attempt­ed divid­ed by games played.
float FreeThrowAtp(int fts, int totalgames){
	return (fts*1.0)/totalgames;
}
//Total free throws attempt­ed divid­ed by games played.
float FreeThrowPercent( int ftmade,int fta){
	return (ftmade/fta)*100;
}
//Total number of assists divided by games played
float Assists(int assist, int totalgames){
	return (assist*1.0)/totalgames;
}
//Total number of rebounds divided by games played.
float Rebounds(int reb, int totalgames){
	return (reb*1.0)/totalgames;
}
//Total numer of turnovers divided by games played.
float Turnovers(int turnov,int totalgames){
	return (turnov*1.0)/totalgames;
}//Total steals divided by games played.
float Steals(int steal, int totalgames){
	return (steal*1.0)/totalgames;
}
//Total blocks divided by games played.
float Blocks(int block, int totalgames){
	return (block*1.0)/totalgames;
}
//Total team fouls divided by games played.
float TeamFouls(int fouls, int totalgames){
	return (fouls*1.0)/totalgames;
}
