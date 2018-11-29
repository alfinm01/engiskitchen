#include "kamus.h"

boolean BisaJalan(char arah[5], MATRIKS M, POINT P) {
    if (arah == "UP") {
        return((IsIdxValid(P.X, (P.Y + 1))) && (Elmt(M, P.X, (P.Y + 1)) = ' '));
    } else if (arah == "DOWN") {
        return((IsIdxValid(P.X, (P.Y - 1))) && (Elmt(M, P.X, (P.Y - 1)) = ' '));
    } else if (arah == "RIGHT") {
        return((IsIdxValid((P.X + 1), P.Y)) && (Elmt(M, (P.X + 1), P.Y) = ' '));
    } else if (arah == "LEFT") { 
        return((IsIdxValid((P.X - 1), P.Y)) && (Elmt(M, (P.X - 1), P.Y) = ' '));
    }
}

void GoUp(POINT *P, int *J, MATRIKS M, boolean Main) {
    if (BisaJalan("UP", M, *P)) {
        *P = NextY(*P);
        *J--;
    } else {
        if(!Main && IsPointPintu(*P)) {
            MasukMainRoom();
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoDown(POINT *P, int *J, MATRIKS M, boolean Main) {
    if (BisaJalan("DOWN", M, *P)) {
        *P = PrevY(*P);
        *J--;
    } else {
        if (Main && IsPointPintu(*P)) {
            MasukDapur();
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoRight(POINT *P, int *J, MATRIKS M) {
    if (BisaJalan("RIGHT", M, *P)) {
        *P = NextX(*P);
        *J--;
    } else {
        printf("Gabisa gerak");
    }
}

void GoLeft(POINT *P, int *J, MATRIKS M) {
    if (BisaJalan("LEFT", M, *P)) {
        *P = NextY(*P);
        *J--;
    } else {
        printf("Gabisa gerak");
    }
}