/* File : array.c */
/* Deskripsi : Berisi implementasi dari file header array.h, penempatan elemen selalu rapat kiri */

#include "boolean.h"
#include "array.h"

/* ******************** IMPLEMENTASI ******************** */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabOrder *T) {
	SetNeff(T, 0);
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabOrder T) {
	return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabOrder T) {
	return (IdxMax - IdxMin + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabOrder T) {
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabOrder T) {
	return (IdxMin + NbElmt(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabOrder T, IdxType i) {
	return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabOrder Tin, TabOrder *Tout) {
	*Tout = Tin;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl (TabOrder *T, IdxType i, ElType v) {
	(*T).TI[i].Name = v.Name;
	(*T).TI[i].TableNo = v.TableNo;							// Haruskah
	if (i > NbElmt(*T)) {
		SetNeff(T, (NbElmt(*T) + 1));
	}
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabOrder *T, IdxType N) {
	(*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabOrder T, IdxType i) {
	return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabOrder T, IdxType i) {
	if ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T))) {
		return true;
	}
	return false;
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabOrder T) {
	if (NbElmt(T) == 0) {
		return true;
	}
	return false;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabOrder T) {
	if (NbElmt(T) == IdxMax) {
		return true;
	}
	return false;
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabOrder T) {
	int i;
	
	if (NbElmt(T) == 0) {
		printf("Tabel kosong\n");
	}
	else {
		for (i = IdxMin; i <= NbElmt(T); i++) {
			printf("%d:%d\n", i, T.TI[i]);
		}
	}
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [4,5,6] maka akan diprint
1:4
2:5
3:6
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */	

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabOrder PlusTab (TabOrder T1, TabOrder T2) {
	TabOrder T;
	int i;
	
	MakeEmpty(&T);
	for (i = IdxMin; i <= NbElmt(T1); i++) {
		SetEl(&T, i, (GetElmt(T1, i) + GetElmt(T2, i)));
	}
	SetNeff(&T, NbElmt(T1));
	return T;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabOrder MinusTab (TabOrder T1, TabOrder T2) {
	TabOrder T;
	int i;
	
	MakeEmpty(&T);
	for (i = IdxMin; i <= NbElmt(T1); i++) {
		SetEl(&T, i, (GetElmt(T1, i) - GetElmt(T2, i)));
	}
	SetNeff(&T, NbElmt(T1));
	return T;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabOrder T) {
	int max;
	int i;
	
	max = GetElmt(T, IdxMin);
	for (i = IdxMin; i <= NbElmt(T); i++) {
		if (GetElmt(T, i) > max) {
			max = GetElmt(T, i);
		};
	}
	
	return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabOrder T) {
	int min;
	int i;
	
	min = GetElmt(T, IdxMin);
	for (i = IdxMin; i <= NbElmt(T); i++) {
		if (GetElmt(T, i) < min) {
			min = GetElmt(T, i);
		};
	}
	
	return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabOrder T) {
	int max, index, i;
	
	index = IdxMin;
	max = GetElmt(T, IdxMin);
	for (i = IdxMin; i <= NbElmt(T); i++) {
		if (GetElmt(T, i) > max) {
			max = GetElmt(T, i);
			index = i;
		};
	}
	
	return index;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabOrder T) {
	int min, index, i;
	
	index = IdxMin;
	min = GetElmt(T, IdxMin);
	for (i = IdxMin; i <= NbElmt(T); i++) {
		if (GetElmt(T, i) < min) {
			min = GetElmt(T, i);
			index = i;
		};
	}
	
	return index;
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
