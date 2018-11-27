/*  */
/*  */

#include "queueFunction.h"

void Place(States State, Customers Customer, Tables Table) {
	/* Kamus Lokal */
	int JumlahOrang;

	/* Algoritma */
	Around(State.Position, /* Returning Nomor Meja */, /* boolean Adakah objek? */);	// Bikin fungsi Around, di mana kalo ada objek di sekitar P bisa diidentifikasi
	if (!Table.IsFull) {
		Del(&(State.WaitingCustomer), &JumlahOrang);
		Table.IsFull = true;
		// if (JumlahOrang < Table.Chair) {
			IsiMeja(Table, JumlahOrang);						// Bikin fungsi buat ngisi mejanya, ntar
		// }
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