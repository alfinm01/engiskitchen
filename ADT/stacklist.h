#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


/* MODUL STACK */
/* Deklarasi stack yang diimplementasi dengan list linier dengan representasi fisik pointer */

#define Nil NULL

typedef struct {
	char Name[20];			/* Nama makanan */
	int Price;				/* Harga */
} Foods;

#define NameF(F) (F).Name
#define Price(F) (F).Price

/*  Definisi Type Stack  */
typedef Foods infotype;
typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotype Food;
	address Next;
} ElmtStack;
typedef struct {
	address TOP;
} Stack;

/***************************************************** 
TOP(S) = Nil adalah stack dengan elemen kosong
Definisi stack dengan representasi berkait :
  Jika S adalah Stack maka akses elemen :
    TOP(S) adalah alamat elemen TOP
    Info(P) untuk mengakses elemen info dengan alamat P 
    Next(P) untuk mengakses elemen next dengan alamat P 
******************************************************/
#define Top(S) (S).TOP
#define Next(P) (P)->Next
#define Info(P) (P)->Food

/***************/
/*  Prototype  */
/***************/

//Konstruktor/Kreator 
void CreateEmptyStackList (Stack *S);
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 

// Prototype manajemen memori
void AlokasiStackList (address *P, Foods F);
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
void DealokasiStackList (address *P);
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 

// Predikat Untuk test keadaan KOLEKSI
boolean IsEmptyStackList (Stack S);
// Mengirim true jika Stack kosong
int NBElmtStackList (Stack S);
/* Mengirimkan banyaknya elemen Stack. Mengirimkan 0 jika Q kosong */

// Operator Dasar Stack
void PushStackList (Stack *S, Foods F);
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
void PopStackList (Stack *S, Foods *F);
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S)). 

#endif
