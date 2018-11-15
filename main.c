/* File : engiskitchenexpansion.c */
/* Deskripsi : Engi's Kitchen versi Dinner Dash */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

void uiHeader() {
	/* Kamus Lokal */

	/* Algoritma */
	printf("***** ENGI'S KITCHEN EXPANSION *****\n");
	printf("\n");
}
/* Menampilkan header UI di main menu */

void uiMenu() {
	/* Kamus Lokal */

	/* Algoritma */
	uiHeader();
	printf("           1. New Game\n");
	printf("           2. Start Game\n");
	printf("           3. Load Game\n");
	printf("           4. Exit\n");
}
/* Menampilkan opsi menu */

int main() {
	/* KAMUS */
	char command, *userName;
	boolean exit;

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
		        break;
		    }
		    case '3': {
		        printf("Load Game\n");
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