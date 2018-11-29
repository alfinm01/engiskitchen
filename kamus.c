#include "kamus.h"

void TickCounter(int *Time, Queue *QCust, FoodArray F) {
	/* Kamus */

    /* Algoritma */
    *Time++;					// Time dalam int
	GenerateCustomer(QCust, F);
}

void GenerateCustomer(Queue *QCust, FoodArray F) {
    /* Kamus */
    Customers C;

    /* Algoritma */
    if (NBElmtQueueList(*QCust) < 5) {
    	if ((rand() % 10) > 5) {
    		if ((rand() % 20) > 10) {
				C.Amount = 2;
			}
			else {
				C.Amount = 4;
			}
   			C.Order = F.Food[(rand() % 14) + 1].Name;
    		C.QueueingTime = 30;
    		C.Patience = (30 + rand() / (RAND_MAX / (20 - 60 + 1) + 1));
    		AddQueueList(QCust, C);
    	}
    }
}

void minLife (States *State) {
	/* Kamus */
	
	/* Algoritma */
	(*State).Life--;
}

