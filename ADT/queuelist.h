/* File : queuelist.h */

#ifndef _QUEUELIST_H
#define _QUEUELIST_H

#include "boolean.h"
#include <stdlib.h>

#define Nil NULL

// typedef struct tCust * infotypeQ;
typedef struct {
	// int Number;				/* Customer keberapa */
	int Amount;				/* Jumlah orang (2 atau 4) */
	char *Order;			/* Makanan yang ingin dipesan */
	int QueueingTime;		/* Waktu kesabaran ketika mengantre (30 tick) */
	int Patience;			/* Waktu kesabaran ketika menunggu di meja */
} Customers;					/* Customer di-generate secara random */

#define Amount(C) (C).Amount
#define QueueingTime(C) (C).QueueingTime
#define Patience(C) (C).Patience

/* Deklarasi infotypeQ */
typedef Customers infotypeQ;
/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * addressQueueList;
typedef struct tElmtQueue {
	infotypeQ Info;
	addressQueueList Next;
} ElmtQueue;
/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressQueueList HEAD; /* alamat penghapusan */
	addressQueueList TAIL; /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
/* Prototype manajemen memori */
void AlokasiQueueList (addressQueueList *P, infotypeQ X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
 Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void DealokasiQueueList (addressQueueList *P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmptyQueueList (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NBElmtQueueList (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQueueList(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void AddQueueList (Queue * Q, infotypeQ X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
 jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQueueList (Queue * Q, infotypeQ * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
 elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
#endif