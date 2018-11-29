/*  */
/*  */
#include "queueFunction.h"
#include "./ADT/queuelist.h"

void Place(POINT P, Queue *QC, TableArray *T, JAM *J) {
	/* Kamus Lokal */
	int JumlahOrang, Kursi, NoMeja;
	boolean full, dekat;
	address Q;
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
		printf("Tidak ada meja disekitarmu!");
	}
	/*Timer();													// Bikin fungsi timer (kurangi tick, tambah time)
	ReprintUI();*/
	Q = Head(*QC);
	NoMeja = DetectAroundMain(P);
	if (NoMeja != 0) {
		if (!IsFull(T[NoMeja])) {
			while (Info(Q) != Nil) {
				if ((T[NoMeja]).Chair >= Amount(Q)) {
					DelQueueList(&Q, &C);
					T[NoMeja].IsFull = true;
					T[NoMeja].Customer = C;
					PrevDetik(*J);
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

void Order(States State) {
	/* Kamus Lokal */	

	/* Algoritma */
	Around(State.Position /* Returning Nomor Meja */);
}
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain */