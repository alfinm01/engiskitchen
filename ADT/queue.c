/* File : queue.c */
/* Deskripsi : Berisi implementasi dari file Header queue.h, Queue alternatif I */

#include "queue.h"

/******** IMPLEMENTASI ********/

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmpty(Queue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong */
boolean IsFull(Queue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return (Tail(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
int NBElmt(Queue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return (Tail(Q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Konstruktor *** */
void CreateEmpty(Queue *Q, int Max) {
  /* Kamus Lokal */

  /* Algoritma */
  (*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  }
  else {                                                        /* Alokasi gagal */
    MaxEl(*Q) = Nil;
  }
}
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue *Q) {
  /* Kamus Lokal */

  /* Algoritma */
  MaxEl(*Q) = Nil;
  free((*Q).T);
}
/* Proses : Mengembalikan memori Q
   I.S. Q pernah dialokasi
   F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Operator-Operator Dasar Queue *** */
void Add(Queue *Q, infotype X) {
  /* Kamus Lokal */

  /* Algoritma */
  if (IsEmpty(*Q)) {
    Head(*Q) = 1;
    Tail(*Q) = 1;
  }
  else {
    Tail(*Q)++;
  }
  InfoTail(*Q) = X;
}
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi Tail yang baru, Tail "maju" */
void Del(Queue *Q, infotype *X) {
  /* Kamus Lokal */
  address i;

  /* Algoritma */
  *X = InfoHead(*Q);
  if (Head(*Q) == Tail(*Q)) {                                  /* Set menjadi queue kosong */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  }
  else {
    for (i = 1; i <= Tail(*Q); i++) {
      *((*Q).T+i) = *((*Q).T+i+1);
    }
    Tail(*Q)--;
  }
}
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen Head pada I.S.,
        Jika Queue masih isi : Head diset tetap = 1, elemen-elemen setelah
        Head yang lama digeser ke "kiri", Tail = Tail � 1;
        Jika Queue menjadi kosong, Head = Tail = Nil. */