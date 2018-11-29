/*  */
/*  */

#include "kamus.h"

void Place(POINT P, Queue *QC, TableArray *T) {
	/* Kamus Lokal */
	int JumlahOrang, Kursi, NoMeja;
	boolean full, dekat;
	addressQueueList Q;
	Customers C;

	/* Algoritma */
	/*DekatMeja(P, &NoMeja, &Kursi, &full, &dekat);
	if(dekat) {
		if (!full) {
			if (Amount(InfoHead(*QC)) < Kursi) {
				//IsiMeja(Table, JumlahOrang);						// Bikin fungsi buat ngisi mejanya, ntar
				//Del(&(State.WaitingCustomer), &JumlahOrang);
				Customer(*T) = (*QC).Customer
				IsFull(*T) = true;
				PrevDetik(*J);
				Del(*QC, )
			} else {
				printf("Meja Sudah Terisi!");
			}	
		} else {
			printf("Meja Penuh!");
		}
	} else {
		printf("Tidak ada meja di sekitarmu!");
	}
	/*Timer();													// Bikin fungsi timer (kurangi tick, tambah time)
	ReprintUI();*/
	Q = Head(*QC);
	NoMeja = DetectAround(P, true);
	if (NoMeja != 0) {
		if (!((*T).Table[NoMeja].IsTableFull)) {
			while (Info(Q).Amount != Nil) {
				if ((*T).Table[NoMeja].IsTableFull >= InfoHead(*QC).Amount) {
					DelQueueList(&Q, &C);
					(*T).Table[NoMeja].IsTableFull = true;
					(*T).Table[NoMeja].Customer = C;
					printf("Penempatan Berhasil!\n");
				} else {
					Q = Next(Q);
				}
			}
		} else {
			printf("Meja Penuh!\n");
		}
	} else {
		printf("Tidak ada meja disekitar!\n");
	}
}
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk menaruh pelanggan di meja yang kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue */

void Order(POINT Position, TableArray T, TabOrder *TO) {
	/* Kamus Lokal */	
	TabOrder OrderTemp;

	/* Algoritma */
	OrderTemp.Order[1].Name = T.Table[DetectAround(Position, true)].Customer.Order;
	OrderTemp.Order[1].TableNo = T.Table[DetectAround(Position, true)].Customer.Amount;

	// Memasukkan order ke ArrayOrder
	SetEl(TO, (GetLastIdx(*TO) + 1), OrderTemp);
}
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain */