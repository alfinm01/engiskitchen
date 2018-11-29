#include "kamus.h"

boolean BisaJalan(char arah[5], MATRIKS M, POINT P) {
    if (arah == "UP") {
        return((IsIdxValid(P.X, (P.Y + 1))) && ((Elmt(M, P.X, (P.Y + 1)) = ' ')) || (Elmt(M, P.X, (P.Y + 1)) = 'D'));
    } else if (arah == "DOWN") {
        return((IsIdxValid(P.X, (P.Y - 1))) && ((Elmt(M, P.X, (P.Y - 1)) = ' ')) || (Elmt(M, P.X, (P.Y - 1)) = 'D'));
    } else if (arah == "RIGHT") {
        return((IsIdxValid((P.X + 1), P.Y)) && ((Elmt(M, (P.X + 1), P.Y) = ' ')) || (Elmt(M, (P.X + 1), P.Y) = 'D'));
    } else if (arah == "LEFT") { 
        return((IsIdxValid((P.X - 1), P.Y)) && ((Elmt(M, (P.X - 1), P.Y) = ' ')) || (Elmt(M, (P.X - 1), P.Y) = 'D'));
    }
}

void GoUp(POINT *P, int *J, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("UP", M, *P)) {
        *P = NextY(*P);
        *J--;
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("UP", K, *P)) {
            *P = NextY(*P);
            *J--;
        } else if (IsPointPintu(*P)) {
            Main = false;
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoDown(POINT *P, int *J, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("DOWN", M, *P)) {
        *P = PrevY(*P);
        *J--;
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("DOWN", K, *P)) {
            *P = PrevY(*P);
            *J--;
        } else if (IsPointPintu(*P)) {
            Main = true;
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoRight(POINT *P, int *J, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("RIGHT", M, *P)) {
            *P = NextX(*P);
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("RIGHT", K, *P)) {
            *P = NextX(*P);
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoLeft(POINT *P, int *J, MATRIKS M, MATRIKS K, boolean Main) {
    if (Main) {
        if (BisaJalan("LEFT", M, *P)) {
            *P = NextY(*P);
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    } else {
        if (BisaJalan("LEFT", K, *P)) {
            *P = NextY(*P);
            *J--;
        } else {
            printf("Gabisa gerak");
        }
    }
}