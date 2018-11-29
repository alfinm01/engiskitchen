/* Struktur Data Universal */
/* Header yang berisi fungsi-fungsi yang dibutuhkan game */

#ifndef _KAMUS_H_
#define _KAMUS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ADT/boolean.h"
#include "./ADT/jam.h"
#include "./ADT/array.h"
//#include "./ADT/garis.h"
#include "./ADT/point.h"
#include "./ADT/stack.h"
#include "./ADT/stacklist.h"
#include "./ADT/queuelist.h"
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
	Foods Food[15];
} FoodArray;

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
	boolean IsTableFull;			/* Meja sudah terisi atau belum */
	Customers Customer;		/* Customer mana yang mengisi meja tersebut */
	POINT Position;
} Tables;

typedef struct {
	Tables Table[4];
} TableArray;

#define Number(T) (T).Number
#define Chair(T) (T).Chair
#define IsTableFull(T) (T).IsTableFull
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

/***** MOVEMENT FUNCTION *****/

boolean BisaJalan(char arah[5], MATRIKS M, POINT P);
/*void move(char *command, POINT *P, JAM *J, MATRIKS M, boolean B);
*/
void GoUp(POINT *P, MATRIKS M, MATRIKS K, boolean Main);
void GoDown(POINT *P, MATRIKS M, MATRIKS K, boolean Main);
void GoRight(POINT *P, MATRIKS M, MATRIKS K, boolean Main);
void GoLeft(POINT *P, MATRIKS M, MATRIKS K, boolean Main);

/***** QUEUE FUNCTION *****/

void Place(POINT P, Queue *QC, TableArray *T);
void Order(POINT Position, TableArray T, TabOrder *TO);

/***** STACK FUNCTION *****/

void Give(POINT Position, TableArray *T, TabOrder *TO, Stack *S);
void DeleteOrder(TabOrder *TO, int IdxOrder);
void Take(POINT Position, KitchenArray K, Stack *S);
void CT(Stack *S);

/***** UI FUNCTION *****/

void printMoney(int money);
void printLife(int life);
void printTime(int time);
void printNama(char *name);
void AssignMatriks(MATRIKS *M, boolean Main, POINT Player, TableArray T);
void printBatas();
void Map(MATRIKS *M, boolean Main, POINT Player, TableArray T);
void PrintUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S, TabOrder A, TableArray T);
void uiHeader();
void uiMenu();
void uiCommand();

/***** INITIALIZATION FUNCTION *****/

void New(States *State, Maps *MapMain, Maps *MapKitchen, MATRIKS *MatriksMain, MATRIKS *MatriksKitchen,
		TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Stack *FoodStack, Queue *QCust);
void InitMap(Maps *Map, char MapType);
void InitTable(Tables *Table, int TableCounter);
void InitFood(Foods *Food, int FoodCounter);
void InitKitchen(Kitchens *Kitchen, int KitchenCounter, Foods Food);
void Load(States *State, Maps *MapMain, Maps *MapKitchen);
void ReadState(States *State);

/***** OTHER FUNCTION *****/
void TickCounter(int *Time, Queue *QCust, FoodArray F);
void GenerateCustomer(Queue *QCust, FoodArray F);
void Game(States *State, MATRIKS *MainRoom, MATRIKS *KitchenRoom, TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Queue *QCust, Stack *FoodStack);
void minLife (States *State);
#endif