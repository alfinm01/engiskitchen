/* File : engiskitchenexpansion.c */
/* Deskripsi : Engi's Kitchen versi Dinner Dash */

#include "kamus.h"
#include "./UI/UI.h"
#include "UIFunction.h"

// void NewGame(char *userName) {
// 	/* Kamus Lokal */

// 	/* Algoritma */
// 	system("cls");
// 	uiHeader();
//     printf("Nama Anda (max 20 karakter): ");
//     userName = (char *) malloc (20 * sizeof (char));
//     scanf("%s", &userName);
//     system("cls");
//     uiMenu();
//     printf("\n");
//     printf("Nama Anda: %s\n", &userName);
//     printf("Masukkan opsi antara 1-4 sesuai pada main menu\n");
// }
// /* Prosedur New Game */

int main() {
	/* KAMUS */
	char command, *userName;
	boolean exit;
	States State;
	Maps MapRestaurant, MapMain;
	Tables Table1, Table2, Table3, Table4;

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
		        printf("Nama Anda (max 20 karakter): ");
		        userName = (char *) malloc (20 * sizeof (char));
		        scanf("%s", &userName);
		        break;
		    }
		    case '2': {
		        printf("Start Game\n");
		        
		        //system("cls");

		        break;
		    }
		    case '3': {
		        printf("Load Game\n");
		        //ReadState(&State);
		        printf("%s\n", State.Name);
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