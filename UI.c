/* Implementasi UI */

#include "kamus.h"

void printMoney(int money){
	/* Kamus */
	int i, idx, spaceLength, moneyLength, digit;
	StackS s;
	/* Algoritma */
	if (money == 0) {
		printf("    0");
	}
	else {
		CreateEmptyStack(&s);
		moneyLength = 0;
		
		do {
			digit = money%10 ;
			PushStack(&s,digit);
			moneyLength++;
			money = money / 10;
		} while ((money != 0) && (moneyLength<=5)); 
		
		spaceLength = 5 - moneyLength;
		for (i=1; i<=spaceLength; i++) {
			printf(" ");
		}
		
		for (i=1;i<=moneyLength;i++) {
			PopStack(&s, &idx);
			printf("%d", idx);
		}
	}
}

void printLife(int life){
	/* Kamus */
	int i, idx, spaceLength, lifeLength, digit;
	StackS s;
	/* Algoritma */
	if (life == 0) {
		printf(" 0");
	}
	else {
		CreateEmptyStack(&s);
		lifeLength = 0;
		
		do {
			digit = life%10 ;
			PushStack(&s,digit);
			lifeLength++;
			life = life / 10;
		} while ((life != 0) && (lifeLength<=5)); 
		
		spaceLength = 2 - lifeLength;
		for (i=1; i<=spaceLength; i++) {
			printf(" ");
		}
		
		for (i=1;i<=lifeLength;i++) {
			PopStack(&s, &idx);
			printf("%d", idx);
		}
	}
}

void printTime(int time){
	/* Kamus */
	int i, idx, spaceLength, timeLength, digit;
	StackS s;
	/* Algoritma */
	if (time == 0) {
		printf("  0");
	}
	else {
		CreateEmptyStack(&s);
		timeLength = 0;
		
		do {
			digit = time%10 ;
			PushStack(&s,digit);
			timeLength++;
			time = time / 10;
		} while ((time != 0) && (timeLength<=5)); 
		
		spaceLength = 3 - timeLength;
		for (i=1; i<=spaceLength; i++) {
			printf(" ");
		}
		
		for (i=1;i<=timeLength;i++) {
			PopStack(&s, &idx);
			printf("%d", idx);
		}
	}
}

void printNama(char *name){
	/* Kamus */
	int lengthname;
	int space, i;
	/* Algoritma */
	space = 29;
	lengthname = strlen(name);
	space = space - lengthname;
	for (i=1;i<=space;i++) {
		printf(" ");
	}
	printf("%s", name);
		
}
void AssignMatriks(MATRIKS *M, boolean Main, POINT Player, TableArray T){
	int i, j;

	/* Algoritma */
	for (i=1; i<= 8; i++){
		for (j=1; j<=8;j++) {
			Elmt(*M,i,j) = ' ';
		}	
	}
	
	if(Main) {
		if (T.Table[1].IsTableFull) {
			Elmt(*M,1,2) = 'C';
			Elmt(*M,3,2) = 'C';
			if (T.Table[1].Customer.Amount >= 4) {
				Elmt(*M,2,1) = 'C';
				Elmt(*M,2,3) = 'C';
			} else {
				Elmt(*M,2,1) = 'X';
				Elmt(*M,2,3) = 'X';
			}
		} else {
			Elmt(*M,2,1) = 'C';
			Elmt(*M,2,3) = 'C';
		}
		if (T.Table[2].IsTableFull) {
			Elmt(*M,6,2) = 'C';
			Elmt(*M,8,2) = 'C';
		} else {
			Elmt(*M,6,2) = 'X';
			Elmt(*M,8,2) = 'X';
		}
		if (T.Table[3].IsTableFull) {
			Elmt(*M,1,7) = 'C';
			Elmt(*M,3,7) = 'C';
			if (T.Table[3].Customer.Amount >= 4) {
				Elmt(*M,2,6) = 'C';
				Elmt(*M,2,8) = 'C';
			} else {
				Elmt(*M,2,6) = 'X';
				Elmt(*M,2,8) = 'X';
			}
		} else {
			Elmt(*M,1,7) = 'C';
			Elmt(*M,3,7) = 'C';
		}
		if (T.Table[4].IsTableFull) {
			Elmt(*M,6,7) = 'C';
			Elmt(*M,8,7) = 'C';
		} else {
			Elmt(*M,6,7) = 'X';
			Elmt(*M,6,7) = 'X';
		}
		Elmt(*M,2,2) = '1';
		Elmt(*M,2,7) = '2';
		Elmt(*M,7,2) = '3';
		Elmt(*M,7,7) = '4';
		Elmt(*M,8,5) = 'D';
		Elmt(*M, Player.X, Player.Y) = 'P';
	}
	
	else {
		Elmt(*M,1,1) = 'M';
		Elmt(*M,2,1) = 'M';
		Elmt(*M,3,1) = 'M';
		Elmt(*M,4,1) = 'M';
		Elmt(*M,5,1) = 'M';
		Elmt(*M,6,1) = 'M';
		Elmt(*M,7,1) = 'M';
		Elmt(*M,8,1) = 'M';
		Elmt(*M,5,4) = 'M';
		Elmt(*M,5,5) = 'M';
		Elmt(*M,8,4) = 'M';
		Elmt(*M,8,5) = 'M';
		Elmt(*M,8,6) = 'M';
		Elmt(*M,8,7) = 'M';
		Elmt(*M,8,8) = 'M';
		Elmt(*M,1,5) = 'D';
		Elmt(*M, Player.X, Player.Y) = 'P';
	}
}

void printBatas() {
	int i;

	printf(" ");
	for (i=1;i <=78 ; i++) {
		printf("-");
	}
	printf(" \n");
}

void Map(MATRIKS *M, boolean Main, POINT Player, TableArray T) {
	/* Kamus */
	int i, j;
	/* Algoritma */
	AssignMatriks(M, Main, Player, T);
	for(i = 1; i<=17; i++) {
		printf(" ");
	}
	for(i=1;i<=47;i++) {
		printf("-");
	}
	for(i=1;i<=16;i++) {
		printf(" ");
	}
	printf("\n");

	for(i=1; i<=8;i++){
		for(j=1;j<=15;j++){
			printf(" ");
		}
		printf(" |");
		for(j=1; j<=8; j++){
			printf("  ");
			printf("%c",Elmt(*M,i,j));
			printf("  |");
		}
		for(j=1;j<=15;j++){
			printf(" ");
		}
		printf("\n");
		for(j=1;j<=17;j++){
			printf(" ");
		}
		for(j=1;j<=8;j++){
			printf("----- ");
		}
		for(j=1;j<=15;j++){
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

void PrintUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S, TabOrder A, TableArray T) {
	/* Kamus */
	int i,j, infoS, lengthFoodS, SpaceS, SpaceA, lengthArrayA;
	Customers infoQ;
	Foods FoodS;
	/* Algoritma */
	printBatas();
	printf("|");							// nama ruangan
	for(i=1 ; i<= 35; i++) {
		printf(" ");
	}
	printf("MAIN ROOM");
	for(i=1; i<= 34; i++) {
		printf(" ");
	}
	printf("|\n");
	printBatas();

	printBatas();
	printf("| ");						
	printNama(name);
	
	printf(" | ");
	printf(" MONEY : ");
	printMoney(money);
	
	printf("  | ");
	printf(" LIFE : ");
	printLife(life);
	
	printf("  | ");
	printf(" TIME : ");
	printTime(time);
	
	printf("  |\n");
	printBatas();
	
	Map(M, Main, Player, T);
	
	printBatas();
	printf("|");							// judul status makanan
	printf(" WAITING CUSTOMER");
	printf("    |");
	printf(" ORDER");
	printf("                      |");
	printf(" FOOD STACK");
	printf("                ");
	printf("|\n");
	
	printBatas();
	for (j=1; j <=5 ; j++) {
	// status makanan
		printf("| ");
		if (IsEmptyQueueList(Q)) {
			printf(" ");
		}
		else {
			DelQueueList(&Q, &infoQ);
			printf("%d",infoQ);
		}
		for (i=1; i<=18; i++){
			printf(" ");
		}
		printf(" | ");					// array
		if (NbElmt(A) == 0) {
			for (i=1 ; i<=26; i++) {
				printf(" ");
			}
		}
		else {
			lengthArrayA = strlen(A.Order[j].Name);
			SpaceA = 23 - lengthArrayA;
			printf("%s, " , A.Order[j].Name);
			printf("%d", A.Order[j].TableNo);
			for (i=1 ; i<=SpaceA; i++) {
				printf(" ");
			}
		}
		printf(" | ");					// stack
		if (IsEmptyStackList(S)) {
			for (i=1; i<=25 ; i++) {
				printf(" ");
			}
		}
		else {
			PopStackList(&S, &FoodS);
			lengthFoodS = strlen(FoodS.Name);
			SpaceS = 25-lengthFoodS;
			printf("%s", FoodS.Name);
			for (i=1; i<=SpaceS ; i++) {
				printf(" ");
			}
		}
		printf(" |\n");
	}
	printBatas();

}

void uiHeader() {
	/* Kamus Lokal */

	/* Algoritma */
	printf("***** ENGI'S KITCHEN EXPANSION *****\n");
	printf("\n");
}
/* I.S. Sembarang */
/* F.S. Menampilkan header UI di main menu */

void uiMenu() {
	/* Kamus Lokal */

	/* Algoritma */
	uiHeader();
	printf("           1. New Game\n");
	printf("           2. Start Game\n");
	printf("           3. Load Game\n");
	printf("           4. Exit\n");
}
/* I.S. Sembarang */
/* F.S. Menampilkan opsi menu */

void uiCommand () {
	/* Kamus */

	/* Algoritma */
	//uiHeader();
	printf("                             GD (Go Down)\n");
	printf("                              GU (Go Up)\n");
	printf("                             GL (Go Left)\n");
	printf("                             GR (Go Right)\n");
	printf("                                ORDER\n");
	printf("                                TAKE\n");
	printf("                            CT (Clear Tray)\n");
	printf("                                PLACE\n");
	printf("                                GIVE\n");
	printf("                                SAVE\n");
	printf("                                QUIT\n");

}