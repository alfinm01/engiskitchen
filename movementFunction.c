#include "kamus.h"

boolean BisaJalan(char arah[5], MATRIKS M, POINT P) {
    if (arah == "UP") {
        return((IsIdxValid((P.X - 1), P.Y)) && ((Elmt(M, (P.X - 1), P.Y) = ' ') || (Elmt(M, (P.X - 1), P.Y)) = 'D'));
    } else if (arah == "DOWN") {
        return((IsIdxValid((P.X + 1), P.Y)) && ((Elmt(M, (P.X + 1), P.Y) = ' ') || (Elmt(M, (P.X + 1), P.Y)) = 'D'));
    } else if (arah == "RIGHT") {
        return((IsIdxValid(P.X, (P.Y + 1)) && ((Elmt(M, P.X, (P.Y + 1)) = ' ') || (Elmt(M, P.X, (P.Y + 1)) = 'D'));
    } else if (arah == "LEFT") { 
        return((IsIdxValid(P.X, (P.Y - 1)) && ((Elmt(M, P.X, (P.Y - 1)) = ' ') || (Elmt(M, P.X, (P.Y - 1)) = 'D'));
    }
}

void GoUp(POINT *P, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("UP", M, *P)) {
        *P = PrevX(*P);
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("UP", K, *P)) {
            *P = PrevX(*P);
        } else if (IsPointPintu(*P)) {
            Main = false;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoDown(POINT *P, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("DOWN", M, *P)) {
        *P = NextX(*P);
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("DOWN", K, *P)) {
            *P = NextX(*P);
        } else if (IsPointPintu(*P)) {
            Main = true;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoRight(POINT *P, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("RIGHT", M, *P)) {
            *P = NextY(*P);
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("RIGHT", K, *P)) {
            *P = NextY(*P);
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoLeft(POINT *P, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("LEFT", M, *P)) {
            *P = PrevY(*P);
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("LEFT", K, *P)) {
            *P = PrevY(*P);
        } else {
            printf("Gabisa gerak");
        }
    }
}