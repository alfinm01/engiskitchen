#include "stacklist.h"

/***************/
/*  Prototype  */
/***************/

// Konstruktor/Kreator 
void CreateEmptyStackList (Stack *S) {
	/* Kamus Lokal */

	/* Algoritma */
	Top(*S) = Nil;
}
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 

// Prototype manajemen memori
void AlokasiStackList (address *P, Foods F) {
	/* Kamus Lokal */

	/* Algoritma */
	*P = (address) malloc (sizeof (ElmtStack));
  	if (*P != Nil) {
    	Info(*P) = F;
    	Next(*P) = Nil;
  	}
  	else {
    	*P = Nil;
  	}
}
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
void DealokasiStackList (address *P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmptyStackList (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (Top(S) == Nil);
}
// Mengirim true jika Stack kosong
int NBElmtStackList (Stack S) {
	/* Kamus Lokal */
	int count = 0;
	address P;

	/* Algoritma */
	if (!IsEmptyStackList(S)) {
		P = Top(S);
		while (P != Nil) {
			count++;
			P = Next(P);
		}
	}
	return count;
}
/* Mengirimkan banyaknya elemen Stack. Mengirimkan 0 jika Q kosong */

// Operator Dasar Stack
void PushStackList (Stack *S, Foods F) {
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	Alokasi(&P, F);
	if (P != Nil) {
		if (!IsEmpty(*S)) {
			Next(P) = Top(*S);
		}
		Top(*S) = P;
	}
}
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
void PopStackList (Stack *S, Foods *F) {
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	*F = Info(Top(*S));
	P = Top(*S);
	Top(*S) = Next(Top(*S));
	Dealokasi(&P);
}
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S))