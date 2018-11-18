/* File : stacklist.c */
/* Nama : Alfian Maulana Ibrahim */
/* NIM : 18217038 */
/* Tanggal : 31 Oktober 2018 */
/* Deskripsi : Berisi implementasi dari file header stacklist.h, stack diimplementasi dengan list linier */

#include "stacklist.h"

/***************/
/*  Prototype  */
/***************/

// Konstruktor/Kreator 
void CreateEmpty (Stack *S) {
	/* Kamus Lokal */

	/* Algoritma */
	Top(*S) = Nil;
}
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 

// Prototype manajemen memori
void Alokasi (address *P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	*P = (address) malloc (sizeof (ElmtStack));
  	if (*P != Nil) {
    	Info(*P) = X;
    	Next(*P) = Nil;
  	}
  	else {
    	*P = Nil;
  	}
}
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
void Dealokasi (address *P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmpty (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (Top(S) == Nil);
}
// Mengirim true jika Stack kosong

// Operator Dasar Stack
void Push (Stack *S, infotype X) {
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	Alokasi(&P, X);
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
void Pop (Stack *S, infotype *X) {
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	*X = Info(Top(*S));
	P = Top(*S);
	Top(*S) = Next(Top(*S));
	Dealokasi(&P);
}
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S))