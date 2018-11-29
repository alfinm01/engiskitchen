/* Struktur Data Universal */
/* Header yang berisi fungsi-fungsi yang dibutuhkan game */

#ifndef _KAMUS_H_
#define _KAMUS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ADT/jam.h"
//#include "./ADT/array.h"
//#include "./ADT/garis.h"
#include "./ADT/point.h"
#include "./ADT/stacklist.h"
#include "./ADT/queuelist.h"
#include "./ADT/boolean.h"
#include "./ADT/matriks.h"
#include "./ADT/mesin_kata.h"

typedef struct {
	char *Name;					/* Nama pemain */
	POINT Position;				/* Posisi pemain P */
	int Life;					/* Nyawa tersisa */
	int Money;					/* Jumlah uang yang didapat */
	int Time;					/* Waktu lama bermain */
	JAM SaveTime;				/* Waktu saat melakukan Save */
	// TabInt Order;			/* Order yang diterima dari pelanggan (berisi "nama makanan, nomor meja") */
		/* Perlu ada perubahan di tipe data Array */
	// Stack FoodStack;			/* Makanan yang berada di nampan */	/* !Stack berisi infotype Foods! */
	// Queue WaitingCustomer;	/* Antrean pelanggan (berisi "jumlah pelanggan", 2 atau 4) */
	// char *Object;				/* Object yang berada di dekat player */
	int TableAround;			/* Nomor meja yang berada di dekat player */
	int KitchenAround;			/* Nomor meja dapur yang berada di dekat player */
	boolean IsInMain;			/* True jika player berada di map Main */
	int GenerateNextCust;		/* Menyimpan waktu untuk meng-generate next customer */
} States;

#define NameP(S) (S).Name
#define PositionP(S) (S).Position
#define Life(S) (S).Life
#define Money(S) (S).Money
#define Time(S) (S).Time
#define FoodStack(S) (S).FoodStack
#define Object(S) (S).Object

typedef struct {
	char Name[20];			/* Nama makanan */
	int Price;				/* Harga */
} Foods;

typedef struct {
	Foods Food[15];
} FoodArray;

#define NameF(F) (F).Name
#define Price(F) (F).Price

typedef struct {
	int N, M;				/* Ukuran N x M (8 x 8) */
	POINT D;				/* Posisi pintu dapur-restoran */
} Maps;

#define Length(M) (M).N;
#define Width(M) (M).M;
#define Door(M) (M).D;

typedef struct {
	int Number;				/* Meja nomor keberapa */
	int Chair;				/* Jumlah kursi tersedia (2 atau 4) */
	boolean IsFull;			/* Meja sudah terisi atau belum */
	Customers Customer;		/* Customer mana yang mengisi meja tersebut */
	POINT Position;
} Tables;

typedef struct {
	Tables Table[4];
} TableArray;

#define Number(T) (T).Number
#define Chair(T) (T).Chair
#define IsFull(T) (T).IsFull
#define Customer(T) (T).Customer
#define PositionT(T) (T).Position

typedef struct {
	int Number;				/* Meja dapur keberapa */
	Foods Food;				/* Makanan yang dihasilkan dari meja dapur tersebut */
	POINT Position;
} Kitchens;

typedef struct {
	Kitchens Kitchen[15];
} KitchenArray;

#define Food(K) (K).Food
#define PositionK(K) (K).Position





#endif