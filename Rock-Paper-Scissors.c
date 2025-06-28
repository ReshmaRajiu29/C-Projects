#include<stdio.h>
#include<string.h>

enum RPC {
	Rock=0,Paper=5,Scissors=2  //used enum because p1 and p2 can hold only these three values
};

enum RPC getvalues(char arr[])   // to convert string into enum type
{
	if(strcmp(arr,"Rock")==0)
	return Rock;
	else if(strcmp(arr,"Paper")==0)
	return Paper;
	else if(strcmp(arr,"Scissors")==0)
	return Scissors;
	else return -1;
	
}
int main() {
	enum RPC p1;
	enum RPC p2;
	char p11[10];
	char p22[10];
	int rounds,p1count=0,p2count=0;
	printf("Enter no. of rounds:");
	scanf("%d",&rounds);
	int i=1;
	while(i<=rounds) {
		printf("Person 1 (Rock/Paper/Scissors):");
		scanf("%s",p11);
		p1=getvalues(p11);
		printf("Person 2 (Rock/Paper/Scissors):");
		scanf("%s",p22);
		p2=getvalues(p22);
		if(p1==-1 || p2==-1){
		printf("Invalid choice");
		i--;
		continue;
	    }
		if(p1==Rock && p2==Scissors || p1==Scissors && p2==Paper || p1==Paper && p2==Rock)
		p1count++;
		else if(p2==Rock && p1==Scissors || p2==Scissors && p1==Paper || p2==Paper && p1==Rock)
		p2count++;
		else
		continue;
		i++;
	}
	if(p1count>p2count){
	printf("Person 1 is Winner!!");
	printf("Won by %d points",p1count);
}
	else if(p1count<p2count){
	printf("Person 2 is Winner!!");
	printf("Won by %d points",p2count);
}
	else
	printf("It is tie!!");
	return 0;
	
}
