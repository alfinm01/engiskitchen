#include "boolean.h"
#include "mesin_kar.h"
#include <stdio.h>

/* Variable Global Mesin */
char CC;
boolean EOP;

/*
  pada implementasi (mesin_kar.c), perlu ditambahkan variabel static 
  global yang menyimpan pembacaan file pita.
*/
static FILE *pita;
static int retval;

/* ******************** IMPLEMENTASI ******************** */

void START(char* filename) {
	pita = fopen(filename, "r");
	ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita

Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */

void ADV() {
	retval = fscanf(pita, "%c", &CC);
	EOP = (CC == MARK);
	if (EOP) {
		fclose(pita);
	}
}
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */

char GetCC() {
	return CC;
}
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/

boolean IsEOP() {
	return (CC == MARK);
}
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/