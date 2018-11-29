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
	TableArray T;
	FoodArray F;
	KitchenArray K;

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
		        New(&State, &MapMain, &MapKitchen, &T, &F, &K);
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
		        
		        //system("cls");

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
		        //printf("%s\n", State.Object);
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