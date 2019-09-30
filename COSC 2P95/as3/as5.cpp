#include<iostream>
#include<math>
#include<list>
#include<array>
#include <unistd.h>
#include <cstdlib>
#include <signal.h>
#include <pthread.h>
using namespace std;
private final static char[80][20] map;
private final static char gold='G';
private final static char floor=' ';
private final static char wall='X';
private final static char kobold='K';
static const int NUMTHREADS=4;
volatile bool continuing;
pthread_mutex_t olock;
pthread_mutex_t cout_lock;
void getmap(){
	int choice;
	for(int y=0;y<20;y++){
		for(int x=0;x<80;x++){
			choice=4*Math.random()+1;
			map[x][y]=build(choice);
		}
	}
}
char build(int input){
	if(input==1){
		return gold;
	}
	if(input==2){
		return floor;
	}
	if(input==3){
		return wall;
	}
	if(input==4){
		return kobold;
	}
}
char addplayer(int playernumber){
	while(true){
		int x=Math.random()*80+1;
		int y=Math.random()*20+1;
			if(map[x][y]==''){
				placeonfloor(x,y,playernumber);
				break;
			}
	}
}
char displaymap(){
	for(int y=0;y<20;y++){
		for(int x=0;x<80;x++){
			cout<<"["<<map[x][y]<<"] ";
		}
		cout<<endl;
	}
		cout<<endl;
}
void resetmap(){
	getmap();
}
//void setwall(){
//	int randomnumber=161*Math.random();
//	while(randomnumber!=0){
//		map[81*Math.random()][21*Math.random()]='X';
//		randomnumber--;
//	}
//}
//void setplayer(){
//	player.set();
//}
void getgold(int x,int y){
	player.score=player.score+10;
	map[x][y]=='';
	respawn(1);
}
void battle(int x,int y,int playernumber){
	if(HPofkobold(player.attack)<0)
		{
			player.score=player.score+25;
			map[x][y]='';
			respawn(2);//kobold respawn
		}
	else if(HPofplayer(1)<0)
		{
			respawnplayer(playernumber);//player respawn
		}
}
int HPofkobold(int damage){
	int healthofkobold=7;
	int currentofKHP=healthofkobold-damage;
	if(currentofKHP<=0)
		return 0;
	else
		return currentofKHP;
}
int HPofplayer(int damage){
	int currentofPHP=player.hp;
	if((currentofPHP-damage)<=0)
		{
		return 0;}
	else
		{currentofPHP=currentofPHP-damage;
		return currentofPHP;}
}
void respawn(int a){
	while(true){
		int x=Math.random()*80+1;
		int y=Math.random()*20+1;
		if(map[x][y]==''){
			if(a==1)
			{
				placeonfloor(x,y,gold);
				break;
			}
			if(a==2)
			{
				placeonfloor(x,y,kobold);
				break;
			}
	}
}
void respawnplayer(int playernumber)
	if(player1.HP>0)
		int help=player1.pathcounter;
		while(player1.pathcounter>0){
			if(help==player1.pathcounter+10){
				int x=Math.random()*80+1;
				int y=Math.random()*20+1;
					if(map[x][y]==''){
							placeonfloor(x,y,playernumber);
							break;
					}
			}
			else
				help++;
		}
	else	if(player2.HP>0)
		int help=player2.pathcounter;
		while(player2.pathcounter>0){
			if(help==player2.pathcounter+10){
				int x=Math.random()*80+1;
				int y=Math.random()*20+1;
					if(map[x][y]==''){
							placeonfloor(x,y,playernumber);
							break;
					}
			}
			else
				help++;
		}
	else	if(player3.HP>0)
		int help=player3.pathcounter;
		while(player1.pathcounter>0){
			if(help==player3.pathcounter+10){
				int x=Math.random()*80+1;
				int y=Math.random()*20+1;
					if(map[x][y]==''){
							placeonfloor(x,y,playernumber);
							break;
					}
			}
			else
				help++;
		}
	else	if(player4.HP>0)
		int help=player4.pathcounter;
		while(player1.pathcounter>0){
			if(help==player4.pathcounter+10){
				int x=Math.random()*80+1;
				int y=Math.random()*20+1;
					if(map[x][y]==''){
							placeonfloor(x,y,playernumber);
							break;
					}
			}
			else
				help++;
		}
	else 
		cout<<"no player alive"<<endl;/////
}

bool checkfloor(int x,int y){
	if(map[x][y]=="")
	return true;	
}
char placeonfloor(int x,int y,char stuff){
	map[x][y]=stuff;
	return map[x][y];
}
char go(int player){
	int a=0;
	int b=0;
	for(int y=0;y<20;y++){
		for(int x=0;x<80;x++){
			if(map[x][y]==player)
				a=x;
				b=y;
		}
	}
	move(a,b,player);
}
char move(int x,int y,int player){
	int counter;
	if(player==1)
		counter=player1.pathcounter;
	else if(player==2)
		counter=player2.pathcounter;
	else if(player==3)
		counter=player3.pathcounter;
	else if(player==4)
		counter=player4.pathcounter;
	if((map[x+1][y]!='X')&&(x+1<80))
	{x=x+1;
	counter++;
	move(x,y);}
	else if((map[x][y+1]!='X')&&(y+1<20))
	{y=y+1;
	counter++;
	move(x,y);}
	else if((map[x-1][y]!='X')&&(x-1>=0))
	{x=x-1;
	counter++;
	move(x,y);}
	else if((map[x][y-1]!='X')&&(y-1>=0))
	{y=y-1;
	counter++;
	move(x,y);}
	else
		return map[x][y];
}
void displaycurr(){
	displaymap();
	cout<<"player1's score: "<<player1.score()<<"HP: "<<player1.hp<<endl;
	cout<<"player2's score: "<<player2.score()<<"HP: "<<player2.hp<<endl;
	cout<<"player3's score: "<<player3.score()<<"HP: "<<player3.hp<<endl;
	cout<<"player4's score: "<<player4.score()<<"HP: "<<player4.hp<<endl;
	cout<<"PID: "<<getpid()<<endl;
}
void* inputplayer(void* unnecessary){
	int x=1;
	pthread_mutex_lock(&cout_lock);
	addplayer(x);
	x=x+1;
	go(x);
	pthread_mutex_unlock(&cout_lock);
}
void interrupted(int sig){
	continuing = false;
}
int main (){
	srand(time(NULL));
	pthread_t ct[NUMTHREADS];
	for (int i=0;i<NUMTHREADS;i++) {
      pthread_mutex_lock(&olock);
      pthread_create(&ct[i], NULL, &inputplayer, NULL);
      pthread_mutex_unlock(&olock);//release lock
    }
	
	
	if (signal(SIGINT,interrupted)==SIG_ERR) {
		std::cout<<"STOP"<<std::endl;
		return 1;
	} 
	if(signal(SIGUSR1,interrupted)==SIG_ERR){
		displaycurr();
		return 1;
	}
	if(signal(SIGUSR2,interrupted)==SIG_ERR){
		resetmap();
		displaymap();
		cout<<"player1's score: "<<player1.score()<<"HP: "<<player1.hp<<endl;
		cout<<"player2's score: "<<player2.score()<<"HP: "<<player2.hp<<endl;
		cout<<"player3's score: "<<player3.score()<<"HP: "<<player3.hp<<endl;
		cout<<"player4's score: "<<player4.score()<<"HP: "<<player4.hp<<endl;
		cout<<"PID: "<<getpid()<<endl;
		return 1;
	}
	if(signal(SIGTERM,interrupted)==SIG_ERR){
		displaymap();
		cout<<"player1's score: "<<player1.score()<<"HP: "<<player1.hp<<endl;
		cout<<"player2's score: "<<player2.score()<<"HP: "<<player2.hp<<endl;
		cout<<"player3's score: "<<player3.score()<<"HP: "<<player3.hp<<endl;
		cout<<"player4's score: "<<player4.score()<<"HP: "<<player4.hp<<endl;
		cout<<"PID: "<<getpid()<<endl;
		return 1;
	}
}