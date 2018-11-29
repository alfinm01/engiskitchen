#include "kamus.h"

void Give(POINT Position, TableArray *T, TabOrder *TO, Stack *S) {
	/* Kamus */
	int NoMeja, i = 0;
	boolean found = false;
	Foods GivenFood;
	
	/* Algoritma */
	NoMeja = DetectAround(Position, true);
	if (NoMeja != 0) {
		if (strcmp((*S).TOP->Food.Name, (*T).Table[NoMeja].Customer.Order) == 0) {
			while (!found) {
				i++;
				if (((*TO).Order[i].TableNo) == NoMeja) {
					found = true;
				}
			}
			if (found) {
				PopStackList(S, &GivenFood);
				DeleteOrder(TO, i);
				(*T).Table[NoMeja].IsTableFull = false;
				(*T).Table[NoMeja].Customer.Amount = 0;
				(*T).Table[NoMeja].Customer.Order = '0';
				(*T).Table[NoMeja].Customer.QueueingTime = 999;
				(*T).Table[NoMeja].Customer.Patience = 999;			// NULL biasanya diassign ke pointer
			}
		}
	}
}

void DeleteOrder(TabOrder *TO, int IdxOrder) {
	/* Kamus */
	int i;
	
	/* Algoritma */
	for (i = IdxOrder; i < NbElmt(*TO); i++) {		// Auto mindahin ke depan
		(*TO).Order[i] = (*TO).Order[i + 1];
	}
}


void Take(POINT Position, KitchenArray K, Stack *S) {
	/* Kamus */
	int i;
	int NoMejaKitchen;
	/* Algoritma */
	NoMejaKitchen = DetectAround(Position, false);
	if (NoMejaKitchen != 0) {
		PushStackList(S, K.Kitchen[NoMejaKitchen].Food);
	}
}

void CT(Stack *S) {
    addressStackList P;

    P = Top(*S);
    DealokasiStackList(&P);
    CreateEmptyStackList(&S);
}