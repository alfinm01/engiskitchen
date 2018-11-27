/* Implementasi UI.h */

#include "UI.h"

void UIGameHeader() {
/*----------------------------------------------------------------------------- .
|                                  MAIN ROOM                                  |.
 ----------------------------------------------------------------------------- .*/
	/* Kamus */

	/* Algoritma */
	printf(" ----------------------------------------------------------------------------- \n");
	// dst
}

void UIMainRoom() {
	/* Kamus */

	/* Algoritma */

}

void UIKitchen() {
	/* Kamus */

	/* Algoritma */
}

void ReadState(States *State) {
	/* Kamus */
	char filename[16] = "GameState.txt";
	int i;

	/* Algoritma */
	printf("debug1\n");
	STARTKATA(filename);

	printf("debug2\n");
	while (!EndKata) {
		if ((CKata.TabKata[1] = 'N') && (CKata.TabKata[2] = 'a') &&
			(CKata.TabKata[3] = 'm') && (CKata.TabKata[1] = 'e')) {
			ADVKATA();
			for (i = 1; i <= CKata.Length; i++) {
				(*State).Name[i] = CKata.TabKata[i];
			}
			printf("%s\n", (*State).Name);
		}
		ADVKATA();
	}
}