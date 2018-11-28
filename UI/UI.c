/* Implementasi UI.h */

#include "UI.h"

void AssignMatriks(MATRIKS *M, char JenisRuang){
	/* Kamus */
	int i,j;
	/* Algoritma */
	if(JenisRuang == 'M') {
		Elmt(*M,1,2) = 'X';
		Elmt(*M,2,1) = 'X';
		Elmt(*M,2,3) = 'X';
		Elmt(*M,3,2) = 'X';
		Elmt(*M,2,6) = 'X';
		Elmt(*M,2,8) = 'X';
		Elmt(*M,7,1) = 'X';
		Elmt(*M,7,3) = 'X';
		Elmt(*M,7,6) = 'X';
		Elmt(*M,7,8) = 'X';
		Elmt(*M,6,2) = 'X';
		Elmt(*M,8,2) = 'X';
		Elmt(*M,2,2) = '1';
		Elmt(*M,2,7) = '2';
		Elmt(*M,7,2) = '3';
		Elmt(*M,7,7) = '4';
		Elmt(*M,8,5) = 'D';
	}
	
	else if (JenisRuang == 'K') {
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

void Map(MATRIKS *M, char JenisRuang) {
	/* Kamus */
	int i, j;
	
	/* Algoritma */
	if (JenisRuang == 'M') {
		AssignMatriks(M, 'M');
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
	else if (JenisRuang == 'K') {
		AssignMatriks(M, 'K');
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

}

void PrintUI(MATRIKS *M, char JenisRuang) {
	/* Kamus */
	int i,j;
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
	for (i=1; i<= 29;i++) {
		printf(" ");
	}
	printf(" | ");
	printf(" MONEY : ");
	for(i=1;i<=5;i++){
		printf("0");
	}
	printf("  | ");
	printf(" LIFE : ");
	for (i=1;i<=2;i++) {
		printf("0");
	}
	printf("  | ");
	printf(" TIME : ");
	for(i=1;i<=3;i++) {
		printf("0");
	}
	printf("  |\n");
	printBatas();
	
	if (JenisRuang == 'M'){
		Map(M, 'M');
	}
	else if (JenisRuang == 'K') {
		Map(M, 'K');
	}
	
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
	for (i=1; i <=5 ; i++) {
	// status makanan
		printf("| ");
		for (i=1; i<=19; i++){
			printf(" ");
		}
		printf(" | ");
		for (i=1 ; i<=26; i++) {
			printf(" ");
		}
		printf(" | ");
		for (i=1; i<=25 ; i++) {
			printf(" ");
		}
		printf(" |\n");
	}
	printBatas();

}