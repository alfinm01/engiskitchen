/* File : stack.c */
/* Nama : Alfian Maulana Ibrahim */
/* NIM : 18217038 */
/* Tanggal : 03 Oktober 2018 */
/* Deskripsi : Berisi implementasi dari file header stack.h */

#include "stack.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(StackS *S) {
  /* Kamus Lokal */

  /* Algoritma */
  Top(*S) = NilS;
}
/* I.S. Sembarang
   F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
   jadi indeksnya antara 1..MaxEl
   Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsStackEmpty(StackS S) {
  /* Kamus Lokal */

  /* Algoritma */
  return (Top(S) == NilS);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(StackS S) {
  /* Kamus Lokal */

  /* Algoritma */
  return (Top(S) == 101);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ********** Operator Dasar Stack ********* */
void PushStack(StackS *S, infotype X) {
  /* Kamus Lokal */

  /* Algoritma */
  Top(*S)++;
  InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S.
   I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
   F.S. X menjadi TOP yang baru, TOP bertambah 1 */
void PopStack(StackS *S, infotype *X) {
  /* Kamus Lokal */

  /* Algoritma */
  *X = InfoTop(*S);
  Top(*S)--;
}
/* Menghapus X dari Stack S.
   I.S. S tidak kosong
   F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */