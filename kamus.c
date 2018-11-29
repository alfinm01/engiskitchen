#include "kamus.h"

void TickCounter(States *State) {
	/* Kamus */

    /* Algoritma */
    (*State).Time++;					// Time dalam int
}

void GenerateCustomer(States State, Queue *QCust, FoodArray F) {
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

