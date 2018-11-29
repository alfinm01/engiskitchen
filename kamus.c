#include "kamus.h"


void TickCounter(States *State) {
	/* Kamus */

    /* Algoritma */
    (*State).Time++;					// Time dalam int
}

void GenerateCustomer(States State, Queue *QCust) {
    /* Kamus */
    Customers C;

    /* Algoritma */
    if (NBElmtQueueList(QCust) < 5) {
    	if ((rand() % 10) > 5) {
    		((rand() % 20) > 10) ? C.Amount = 2 : C.Amount = 4;
   			C.Order = Food[(rand() % 14) + 1].Name;
    		C.QueueingTime = 30;
    		C.Patience = (rand() % 30);
    		AddQueueList(QCust, C);
    	}
    }
}

