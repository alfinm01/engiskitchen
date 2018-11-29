void ReadTables(Tables *Table) {		// Belum kelarrrr
	/* Kamus */
	int i;

	/* Algoritma */
	while (!EndKata) {
		if ((CKata.TabKata[1] = 'T') && (CKata.TabKata[2] = 'a') &&
			(CKata.TabKata[3] = 'b') && (CKata.TabKata[4] = 'l') &&
			(CKata.TabKata[5] = 'e')) {
			ADVKATA();
			while (CKata.TabKata[1] != ';') {
				i = CKata.TabKata[1];
				if (i == 1) {								// Perlu semacam (*Table[i])
					(*Table).Number = i;
					ADVKATA();
					(*Table).Chair = strtoint(CKata.TabKata[1]);		// Perlu fungsi semacam strtoint
					ADVKATA();
					if (CKata.TabKata[1] != '0') {
						(*Table).IsFull = true;
						(*Table).Customer = Customer[i];				// Perlu ada pendeteksi customer yang mana, dan cara input tipe data ke sini
					}
					else {
						(*Table).IsFull = false;
						(*Table).Customer = NULL;
					}
					ADVKATA();
					X = strtoint(CKata.TabKata[1]);
					ADVKATA();
					Y = strtoint(CKata.TabKata[1]);
				}

				

				ADVKATA();
			}
		}
		else {
			ADVKATA();
		}
	}
}