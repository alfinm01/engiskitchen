/*  */
/*  */
#include "queueFunction.h"

void Place(POINT P, Queue *QC, Tables *T, JAM *J) {
	/* Kamus Lokal */
	int JumlahOrang, Kursi, NoMeja;
	boolean full, dekat;
	
	/* Algoritma */
	DekatMeja(P, &NoMeja, &Kursi, &full, &dekat);
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