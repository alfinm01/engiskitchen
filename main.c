/* File : engiskitchenexpansion.c */
/* Deskripsi : Engi's Kitchen versi Dinner Dash */



#include "kamus.h"

int main() {
	/* KAMUS */
	int i;
	char command;
	boolean exit;
	States State;
	Maps MapMain, MapKitchen;
	MATRIKS MatriksMain, MatriksKitchen;
	TableArray T;
	FoodArray F;
	KitchenArray K;
	TabOrder TOrder;
	Stack FoodStack;
	Queue QCust;

	/* ALGORITMA */

	// Main menu
	system("cls");
	uiMenu();
	
	exit = false;
	
	do {
		printf("\n");
		printf("Command (masukkan nomor pada opsi menu): ");
		scanf("%c", &command);
		getchar();													// Untuk mengambil hanya nilai char dari variabel
		printf("\n");
		switch (command) {
		    case '1': {
		        New(&State, &MapMain, &MapKitchen, &MatriksMain, &MatriksKitchen, &T, &F, &K, &TOrder, &FoodStack, &QCust);
		       /* printf("%s\n", State.Name);
		        for (i = 1; i <= 4; i++) {
		        	printf("Number%d Chair%d \n", T.Table[i].Number, T.Table[i].Chair);
		        	TulisPOINT(T.Table[i].Position);
		        	printf("\n");
		        }
		        for (i = 1; i <= 15; i++) {
		        	printf("Name%s Price%d \n", F.Food[i].Name, F.Food[i].Price);
		        }
		        for (i = 1; i <= 15; i++) {
		        	printf("Number%d Food%d Price%d\n", K.Kitchen[i].Number, K.Kitchen[i].Food.Name, K.Kitchen[i].Food.Price);
		        	TulisPOINT(K.Kitchen[i].Position);
		        	printf("\n");
		        }*/
		        break;
		    }
		    case '2': {
		        printf("Start Game\n");		        
		        system("cls");
		        printf("\n\n\n\n");
		        printf("       ==========\n");
		        printf("       GAME START\n");
		        printf("       ==========\n");
		        delay(3000);
		        system("cls");
		        Game();
		        break;
		    }
		    case '3': {
		        printf("Load Game\n");
		        Load(&State, &MapMain, &MapKitchen);
		        printf("%s\n", State.Name);
		        printf("%d\n", State.Life);
		        printf("%d\n", State.Money);
		        TulisPOINT(State.Position);
		        printf("\n");
		        //TulisJAM(State.Time);
		        printf("\n");
		        printf("%d %d\n", MapMain.N, MapKitchen.M);
		        TulisPOINT(MapMain.D);
		        printf("\n");
		        break;
		    }
		    case '4': {
		    	system("cls");
		    	uiHeader();
		    	printf("Sampai jumpa kembali!\n");
		    	printf("Terima kasih sudah bermain :)\n");
		        exit = true;
		        break;
		    }
		    default: {
		        system("cls");
		        uiMenu();
		        printf("\n");
		        printf("Command salah!\n");
		        printf("Masukkan opsi antara 1-4 sesuai pada main menu\n");
			}
		}
	} while (!exit);

	return 0;
}

void Game() {
	/* KAMUS */
	char[10] command;

	/* ALGORITMA */
	system("cls");
	printUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S);
	uiCommand();
	do {
		printf("\n");
		printf("Command : ");
		scanf("%s", &command);
		getchar();													// Untuk mengambil hanya nilai char dari variabel
		printf("\n");
		if (command == 'GU') {
			void GoUp(POINT *P, JAM *J, MATRIKS M, boolean Main);
		}
		else if (command == 'GD'){
			void GoDown(POINT *P, JAM *J, MATRIKS M, boolean Main) ;
		}
		else if (command == 'GR'){
			void GoRight(POINT *P, JAM *J, MATRIKS M);
		}
		else if (command == 'GL'){
			void GoLeft(POINT *P, JAM *J, MATRIKS M);
		}
		else if (command == 'ORDER'){

		}
		else if (command == 'TAKE'){

		}
		else if (command == 'CT'){

		}
		else if (command == 'PLACE'){

		}
		else if (command == 'GIVE'){

		}
		else if (command == 'SAVE'){

		}
		else if (command == 'LOAD'){

		}				
		else if (command == 'EXIT'){

		}
		else {
		        system("cls");
		        uiCommand();
		        printf("\n");
		        printf("Command salah!\n");
		        printf("Command : ");
		}
	printUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S);
	} while (!exit);
}