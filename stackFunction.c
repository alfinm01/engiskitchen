#include "kamus.h"

void Give(POINT Position, TableArray *T, TabOrder *TO, Stack *S, boolean *RightCommand) {
	/* Kamus */
	int NoMeja, i = 0;
	found = false;
	Foods GivenFood;
	
	/* Algoritma */
	NoMeja = DetectAround(Position, true);
	if (NoMeja != 0) {
		if (strcmp((*S).TOP.Food.Name, (*T).Table[NoMeja].Customer.Order) == 0) {
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
				(*T).Table[NoMeja].Customer = NULL;			// NULL biasanya diassign ke pointer
			}
		}
	}
	if (!found) {
		(*RightCommand) = false;
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


void Take(POINT Position, KitchenArray K, Stack *S, boolean *RightCommand) {
	/* Kamus */
	int i;

	/* Algoritma */
	NoMejaKitchen = DetectAround(Position, false);
	if (NoMejaKitchen != 0) {
		PushStackList(S, K[NoMejaKitchen].Food);
	}
	else {
		(*RightCommand) = false;
	}
}