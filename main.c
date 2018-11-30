/* File : engiskitchenexpansion.c */
/* Deskripsi : Engi's Kitchen versi Dinner Dash */



#include "kamus.h"

void Game(States *State, MATRIKS *MainRoom, MATRIKS *KitchenRoom, TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Queue *QCust, Stack *FoodStack) {
	/* KAMUS */
	char command[20];
	int i;
	boolean finish = false;

	/* ALGORITMA */
	system("cls");

	PrintUI(MainRoom, (*State).IsInMain, (*State).Name, (*State).Money, (*State).Life, (*State).Time, (*State).Position, *QCust, *FoodStack, *TOrder, *T);
	do {
		printf("\n");
		uiCommand();
		printf("\n");
		printf("Command : ");
		gets(command);													// Untuk mengambil hanya nilai char dari variabel
		printf("\n");
		if (strcmp(command, "GU") == 0){
			GoUp(&(*State).Position, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GD") == 0){
			GoDown(&(*State).Position, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GR") == 0){
			GoRight(&(*State).Position, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "GL") == 0){
			GoLeft(&(*State).Position, *MainRoom, *KitchenRoom, (*State).IsInMain);
		}
		else if (strcmp(command, "ORDER") == 0){
			Order((*State).Position, *T, TOrder);
		}
		else if (strcmp(command, "TAKE") == 0){
			Take((*State).Position, *K, FoodStack);
		}
		else if (strcmp(command, "CT") == 0){
			CT(FoodStack);
		}
		else if (strcmp(command, "PLACE") == 0){
			Place((*State).Position, QCust, T);
		}
		else if (strcmp(command, "GIVE") == 0){
			Give((*State).Position, T, TOrder, FoodStack);
		}
		else if (strcmp(command, "SAVE") == 0){
			printf("Zonk hehe\n");
		}				
		else if (strcmp(command, "QUIT") == 0){
			finish = true;
			break;
		}
		else {
		        system("cls");
		        uiCommand();
		        printf("\n");
		        printf("Command salah!\n");
		        printf("Command : ");
		}
		TickCounter(&((*State).Time), QCust, *F);
		PrintUI(MainRoom, (*State).IsInMain, (*State).Name, (*State).Money, (*State).Life, (*State).Time, (*State).Position, *QCust, *FoodStack, *TOrder, *T);
	} while ((!finish) /*&& ((*State).Time < 999)*/);

	system("cls");
	printf("\n\n\n");
	printf("              CREDIT\n\n");
	printf("Name: %s\n", (*State).Name);
	printf("Life: %d\n", (*State).Life);
	printf("Time: ");
	TulisJAM(DetikToJAM((*State).Time));
	printf("\n");
	printf("Money: %d\n\n", (*State).Money);
	printf("    Terima kasih telah bermain!\n");
	printf("         Have a nice day :D\n\n");
	printf("           HELL'S KITCHEN\n");
	printf("                By\n");
	printf("Ariq Radhitama Ariasatya - 18217017\n");
	printf(" Mohammad Nathiq Ulman - 18217023\n");
	printf("          Dcp - 18217029\n");
	printf("          Silf - 1821703\n");
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
		        Load(&State, &MapMain, &MapKitchen, &MatriksMain, &MatriksKitchen, &T, 
					&F, &K, &TOrder, &FoodStack, &QCust);
		        // printf("%s\n", State.Name);
		        // printf("%d\n", State.Life);
		        // printf("%d\n", State.Money);
		        // TulisPOINT(State.Position);
		        // printf("\n");
		        // //TulisJAM(State.Time);
		        // printf("\n");
		        // printf("%d %d\n", MapMain.N, MapKitchen.M);
		        // TulisPOINT(MapMain.D);
		        // printf("\n");
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