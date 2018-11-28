/*  */
/*  */

#include "queueFunction.h"

void Place(States State, Customers Customer, Tables Table) {
	/* Kamus Lokal */
	int JumlahOrang, Kursi, NoMeja;
	boolean full, dekat;
	/* Algoritma */
	DekatMeja(Posisi(State), NoMeja, Kursi, full, dekat);
	if(dekat) {
		if (!full) {
			if (Amount(Customer) < Kursi) {
				//IsiMeja(Table, JumlahOrang);						// Bikin fungsi buat ngisi mejanya, ntar
				//Del(&(State.WaitingCustomer), &JumlahOrang);
				Table.IsFull = true;

			}
		}
	else {

	}
	Timer();													// Bikin fungsi timer (kurangi tick, tambah time)
	ReprintUI();
}
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk menaruh pelanggan di meja yang kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue */

void Order(States State) {
	/* Kamus Lokal */	

	/* Algoritma */
	Around(State.Position, /* Returning Nomor Meja */);
}
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain */