#include<stdio.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

int s[2];

int number(void);
void scoreboard();
 void gameDesign();

int main(){
	int i;
	gameDesign();
	printf(" Rules : \n");
	printf(" 1. This game has to be played by two players\n");
	printf(" 2. A random number will be generated you have to enter a guess\n");
	printf(" 3. If you aren't closer to the guess than the other player you won't get any point\n");
	printf(" 4. If you are closer to the guess you will get one point(+1)\n");
	printf(" 5. If you guess the number correctly you will get two points(+2)\n");
	printf("   Press any key to start the game : ");
	getch();
	system("cls");
	gameDesign();
		char name1[20],name2[20];
		printf("Enter the name of Player 1 : ");
		scanf("%s",name1);
		printf("Enter the name of Player 2 : ");
		scanf("%s",name2);
		system("cls");
	gameDesign();			
	start:
	i = 0;
	i++;
	printf("Round %d: \n",i);
	printf("Pick a number between 1 and 10\n\n");
	int no;	
	no = number();
	int p1,p2;
	printf("%s guess the number : ",name1);
	scanf("%d",&p1);
	printf("%s guess the number : ",name2);
	scanf("%d",&p2);
	
	
	printf("The number was %d\n",no);
	if(abs(no-p1) == abs(no-p2)){
		printf("You both are equally close to the number! NO ONE WINS!\n");
	}
	int min = abs(no - p1);
	if(p1 == p2){
		printf("Both Players entered the same number. NO ONE WINS! \n");
	}
	if(p1 == no){
		printf("Congratulations %s. You Guessed the right number.\n",name1);
			s[0]++;
			s[0]++;
			goto point1;
	}
	if(p2 == no){
		printf("Congratulations %s. You Guessed the right number.\n",name2);
			s[1]++;
			s[1]++;
			goto point1;
	}
	
	if(abs(no-p2)<min){
		printf("%s was closer to the number. %s WINS!\n",name2,name2);
		s[1]++;
	}
	else if(abs(no-p2)>min){
		printf("%s was closer to the number. %s WINS!\n",name1,name1);
		s[0]++;
	}
	printf("--------------------------\n");
	point1:		
	printf("Do you want to play again?\n Press Y to play again\n Press N to exit : ");
	fflush(stdin);
	char c = getch();
	if(c == 'y' || c == 'y'){
		system("cls");
		scoreboard();	
		goto start;	
	}
	if(c == 'n'|| c == 'N'){
		goto end;
	}
	if(c != 'y' ||c != 'Y' ||c != 'n' ||c != 'N'){
		system("cls");
		scoreboard();
		printf("\nPress either Y or N\n");
		
		goto point1;
	}
	end:
	system("cls");
	scoreboard();
	if(s[0]> s[1]){
		printf("\n\t %s WINS!",name1);
	}
	if(s[0] < s[1]){
		printf("\n\t%s WINS!",name2);
	}
	if(s[0] == s[1]){
		printf("NO ONE WINS");
	}
	printf("\n\n Thank You For Playing!\n    Have a Good Day!");
	getch();
return 0;
}

int number(){
	srand(time(NULL));
	 int no = (rand()%10) +1;
	return no;
}
 
 void scoreboard(){
 	printf("----------------------------------\n");
 	printf("|\t      %d - %d\t         |",s[0],s[1]);
 	printf("\n----------------------------------\n");
 	
 }
 
 void gameDesign(){
 	printf("----------------------------------\n");
 	printf("|\tNumber Guessing Game\t |");
 	printf("\n----------------------------------\n");
 }