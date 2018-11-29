/* File : engiskitchenexpansion.c */
/* Deskripsi : Engi's Kitchen versi Dinner Dash */



#include "kamus.h"

void Game(States *State, MATRIKS *MainRoom, MATRIKS *KitchenRoom, TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Queue *QCust, Stack *FoodStack) {
	/* KAMUS */
	char *command;

	/* ALGORITMA */
	system("cls");
	PrintUI(MainRoom, (*State).IsInMain, (*State).Name, (*State).Money, (*State).Life, (*State).Time, (*State).Position, *QCust, *FoodStack, *TOrder);
	if ((*State).IsInMain) {
		PrintUI(MainRoom, (*State).IsInMain, (*State).Name, (*State).Money, (*State).Life, (*State).Time, (*State).Position, *QCust, *FoodStack, *TOrder);
	}
		uiCommand();
	do {
		printf("\n");
		printf("Command : ");
		scanf("%s", command);
		getchar();													// Untuk mengambil hanya nilai char dari variabel
		printf("\n");
		if (strcmp(command, "GU") == 0){
			GoUp(&(*State).Position, &(*State).Time, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GD") == 0){
			GoDown(&(*State).Position, &(*State).Time, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GR") == 0){
			GoRight(&(*State).Position, &(*State).Time, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GL") == 0){
			GoLeft(&(*State).Position, &(*State).Time, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "ORDER") == 0){
			Order((*State).Position, *T, TOrder);
		}
		else if (strcmp(command, "TAKE") == 0){

		}
		else if (strcmp(command, "CT") == 0){
			//CT();
		}
		else if (strcmp(command, "PLACE") == 0){

		}
		else if (strcmp(command, "GIVE") == 0){

		}
		else if (strcmp(command, "SAVE") == 0){

		}				
		else if (strcmp(command, "QUIT") == 0){

		}
		else {
		        system("cls");
		        uiCommand();
		        printf("\n");
		        printf("Command salah!\n");
		        printf("Command : ");
		}
	printUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S);
	TickCounter(&State.Time);
	} while (!exit) && (State.Time <999);;
}

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
		        New(&State, &MapMain, &MapKitchen, &MatriksMain, &MatriksKitchen, &T, 
					&F, &K, &TOrder, &FoodStack, &QCust);
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
		        // delay(3000);
		        system("cls");
		        Game(&State, &MatriksMain, &MatriksKitchen, &T, &F, &K, &TOrder, &QCust, &FoodStack);
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