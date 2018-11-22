/* Implementasi UI.h */

#include "UI.h"

int alfian = 10;

void UIMR(){
	/* Kamus */
	FILE filename;
	/* Algoritma */
	*filename = fopen('UIMainRoom.txt', r);
	STARTKATA(filename);
	fclose(filename);
}

void UIKit(){
	/* Kamus */
	FILE filename;
	/* Algoritma */
	*filename = fopen('UIKitchen.txt', r);
	
	fclose(filename);		
}