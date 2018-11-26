/* Struktur Data Universal */
/* Header yang berisi fungsi-fungsi yang dibutuhkan game */

#ifndef _KAMUS_H_
#define _KAMUS_H_

/* Modul lain yang digunakan : */
#include "UIFunction.h"
#include "movementFunction.h"
#include "stackFunction.h"
#include "queueFunction.h"

typedef struct {
	char *Name;				/* Nama pemain */
	POINT Position;			/* Posisi pemain P */
	int Life;				/* Nyawa tersisa */
	int Money;				/* Jumlah uang yang didapat */
	JAM Time;				/* Waktu lama bermain */
	// TabInt Order;			/* Order yang diterima dari pelanggan (berisi "nama makanan, nomor meja") */
		/* Perlu ada perubahan di tipe data Array */
	Stack FoodStack;		/* Makanan yang berada di nampan */
	// Queue WaitingCustomer;	/* Antrean pelanggan (berisi "jumlah pelanggan", 2 atau 4) */
} States;

typedef struct {
	int N, M;				/* Ukuran N x M (8 x 8) */
	POINT D;				/* Posisi pintu dapur-restoran */
} Maps;

typedef struct {
	int Chair;				/* Jumlah kursi tersedia (2 atau 4) */
	boolean IsFull;			/* Meja sudah terisi atau belum */
	POINT Position;
} Tables;

typedef struct {
	int Amount;				/* Jumlah orang (2 atau 4) */
	char *Order;			/* Makanan yang ingin dipesan */
	int QueueingTime;		/* Waktu kesabaran ketika mengantre (30 tick) */
	int Patience;			/* Waktu kesabaran ketika menunggu di meja */
} Customers;					/* Customer di-generate secara random */

extern States State;
extern Maps MapKitchen, MapMain;
extern Tables Table1, Table2, Table3, Table4;

#endif

