/*
File : point.c
Deskripsi : keterangan isi file body
Isi : realisasi/ kode program dari semua prototype
yg didefinisikan pada point.h
Untuk sebuah mesin akan mengandung deklarasi variabel
state dari mesin tsb
*/
#include <stdio.h>
#include <math.h>
#include "point.h"

#define PI (3.141592653589793)

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	float X,Y;
	scanf("%d, %d", &X, &Y);
	*P = MakePOINT(X,Y);
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
	printf("(%d, %d)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPoint (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2));
}
boolean NEQPoint (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	return (!EQPoint(P1,P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
	return EQPoint(P,MakePOINT(0,0));
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return (Absis(P)==0);
}
boolean IsPointPintu (POINT P, boolean Main) {
	if (Main) {
		return EQPoint(P, MakePOINT(5, 8));
	} else {
		return EQPoint(P, MakePOINT(5, 1));
	}
}
boolean BatasAtas(POINT P) {
	return(P.Y == 8);
}
boolean BatasBawah(POINT P) {
	return(P.Y == 1);
}
boolean BatasKanan(POINT P) {
	return(P.X == 8);
}
boolean BatasKiri(POINT P) {
	return(P.X == 1);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
	if ((Absis(P)>0) && (Ordinat(P)>0)) {
		return 1;
	} else if ((Absis(P)<0) && (Ordinat(P)>0)) {
		return 2;
	} else if ((Absis(P)<0) && (Ordinat(P)<0)) {
		return 3;
	} else if ((Absis(P)>0) && (Ordinat(P)<0)) {
		return 4;
	} else {
		return 0;
	}
}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */              
	return MakePOINT(Absis(P)+1,Ordinat(P));
}
POINT PrevX (POINT P) {
	return MakePOINT(Absis(P)-1,Ordinat(P));
}
POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
	return MakePOINT(Absis(P),Ordinat(P)+1);	
}
POINT PrevY (POINT P) {
	return MakePOINT(Absis(P),Ordinat(P)-1);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	return MakePOINT(Absis(P)+deltaX,Ordinat(P)+deltaY);
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	if (SbX) {
            if (Ordinat(P)!=0.00){
		return MakePOINT(Absis(P),Ordinat(P)*(-1));
            } else {
                return MakePOINT(Absis(P),Ordinat(P));
            }
	} else {
            if (Absis(P)!=0.00){
		return MakePOINT(Absis(P)*(-1),Ordinat(P));
            } else {
                return MakePOINT(Absis(P),Ordinat(P));
            }
	}
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	return sqrt(pow(Absis(P),2)+pow(Ordinat(P),2));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
	return sqrt(pow(Absis(P1)-Absis(P2),2)+pow(Ordinat(P1)-Ordinat(P2),2));
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	*P = PlusDelta(*P,deltaX,deltaY);
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
	*P = MakePOINT(Absis(*P),0);
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
	*P = MakePOINT(0,Ordinat(*P));
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
	*P = MirrorOf(*P,SbX);
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
	float X = Absis(*P);
	float Y = Ordinat(*P);
	Absis(*P)=X*cos((-1)*Sudut*PI/180)-Y*sin((-1)*Sudut*PI/180);
	Ordinat(*P)=X*sin((-1)*Sudut*PI/180)+Y*cos((-1)*Sudut*PI/180);
}
/*void DekatMeja (POINT P, Tables *NoMeja, int *Kursi, boolean *full, boolean *dekat){
	if(P == || P == || P ==|| P == ) {
		*dekat = true;
		*NoMeja = Tables1;
		*Kursi =  Chair(T);
		*full = IsFull(T);
	} else if(P ==|| P ==|| P ==|| P ==) {
		*dekat = true;
		*NoMeja = Number(T);
		*Kursi =  Chair(T);
		*full = IsFull(T);
	} else if(P ==|| P ==|| P ==|| P ==) {
		*dekat = true;
		*NoMeja = Number(T);
		*Kursi =  Chair(T);
		*full = IsFull(T);
	} else if(P ==|| P ==|| P ==|| P ==) {
		*dekat = true;
		*NoMeja = Number(T);
		*Kursi =  Chair(T);
		*full = IsFull(T);
	} else {
		dekat = false;
	}
}*/

int DetectAround (POINT PositionP, boolean Main) {
	if (Main) {
		if (Panjang(PositionP, MakePOINT(2, 2)) <= 2) {
			return 1;
		}
		else if (Panjang(PositionP, MakePOINT(2, 7)) <= 2) {
			return 2;
		}
		else if (Panjang(PositionP, MakePOINT(7, 2)) <= 2) {
			return 3;
		}
		else if (Panjang(PositionP, MakePOINT(7, 7)) <= 2) {
			return 4;
		}
		else {
			return 0;
		}
	} else {
		if (Panjang(PositionP, MakePOINT(1, 1)) <= 1) {
			return 1;
		}
		else if (Panjang(PositionP, MakePOINT(2, 1)) <= 1) {
			return 2;
		}
		else if (Panjang(PositionP, MakePOINT(3, 1)) <= 1) {
			return 3;
		}
		else if (Panjang(PositionP, MakePOINT(4, 1)) <= 1) {
			return 4;
		}
		else if (Panjang(PositionP, MakePOINT(5, 1)) <= 1) {
			return 5;
		}
		else if (Panjang(PositionP, MakePOINT(6, 1)) <= 1) {
			return 6;
		}
		else if (Panjang(PositionP, MakePOINT(7, 1)) <= 1) {
			return 7;
		}
		else if (Panjang(PositionP, MakePOINT(8, 1)) <= 1) {
			return 8;
		}
		else if (Panjang(PositionP, MakePOINT(5, 4)) <= 1) {
			return 9;
		}
		else if (Panjang(PositionP, MakePOINT(5, 5)) <= 1) {
			return 10;
		}
		else if (Panjang(PositionP, MakePOINT(8, 4)) <= 1) {
			return 11;
		}
		else if (Panjang(PositionP, MakePOINT(8, 5)) <= 1) {
			return 12;
		}
		else if (Panjang(PositionP, MakePOINT(8, 6)) <= 1) {
			return 13;
		}
		else if (Panjang(PositionP, MakePOINT(8, 7)) <= 1) {
			return 14;
		}
		else if (Panjang(PositionP, MakePOINT(8, 8)) <= 1) {
			return 15;
		}
		else {
			return 0;
		}
	}
}