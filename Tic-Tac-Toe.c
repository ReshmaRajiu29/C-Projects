#include<stdio.h>

char board[10]={'o','1','2','3','4','5','6','7','8','9'};  //XO Board

int checkwin(){
	if(board[1]==board[2] && board[2]==board[3])
	   return 1;
	else if(board[4]==board[5] && board[5]==board[6])
	   return 1;
	else if(board[7]==board[8] && board[8]==board[9])
	   return 1;
	else if(board[1]==board[4] && board[4]==board[7])
	   return 1;
	else if(board[2]==board[5] && board[5]==board[8])
	   return 1;
	else if(board[3]==board[6] && board[6]==board[9])
	   return 1;
	else if(board[1]==board[5] && board[5]==board[9])
	   return 1;
	else if(board[3]==board[5] && board[5]==board[7])
	   return 1;
	else if(board[1]!='1' && board[2]!='2' && board[3]!='3' && board[4]!='4' && board[5]!='5' && board[6]!='6' && board[7]!='7' && board[8]!='8' && board[9]!='9')  //checking whether all the boxes are filled with X and O's
	   return 0;
	else  //not achieving wining
	   return -1;
}

void printboard(){
	printf("TIC TAC TOE\n");
	printf("Player1 (X) - Player2 (O) \n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
	printf("     |     |     \n");	
}

int main(){
	int player=1,i;  //i for controlling loop by checking WIN OR NOT
	int location;   //location for where to place X and O
	char mark;       //mark holds value X or O 
	do{
		printboard();
		player=(player%2)?1:2;  // By increement player values exceeds 2 therefore modulo is used
		mark=(player==1)?'X':'O';
		printf("Player %d , Enter location:",player);
		scanf("%d",&location);
		if(location==1 && board[1]=='1')
		   board[1]=mark;
		else if(location==2 && board[2]=='2')
		   board[2]=mark;
		else if(location==3 && board[3]=='3')
		   board[3]=mark;
		else if(location==4 && board[4]=='4')
		   board[4]=mark;
		else if(location==5 && board[5]=='5')
		   board[5]=mark;
		else if(location==6 && board[6]=='6')
		   board[6]=mark;
		else if(location==7 && board[7]=='7')
		   board[7]=mark;
		else if(location==8 && board[8]=='8')
		   board[8]=mark;
		else if(location==9 && board[9]=='9')
		   board[9]=mark;
		else{
			printf("Invalid Location");
			player--;
			continue;
		}
		i=checkwin();
		player++;
	}while(i==-1);
	printboard();
	if(i==1)
		printf("Player %d Won!!",--player);
	else
	    printf("Tie!!");
	return 0;  

}
