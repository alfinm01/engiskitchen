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

/*void move(char command[5], POINT *P, JAM *J, MATRIKS M, boolean Main) {
    switch (*command) {
        case 'GU' :
            if (BisaJalan("UP", M, *P)) {
                *P = NextY(*P);
                *J = PrevDetik(*J);
            } else {
                if(!Main && IsPointPintu(*P)) {
                    MasukMainRoom();
                    *J = PrevDetik(*J);
                } else {
                    printf("Gabisa gerak");
                }
            }
            break;

        case 'GD' :
            if (BisaJalan("DOWN", M, *P)) {
                *P = PrevY(*P);
                *J = PrevDetik(*J);
            } else {
                if (Main && IsPointPintu(*P)) {
                    MasukDapur();
                    *J = PrevDetik(*J);
                } else {
                    printf("Gabisa gerak");
                }
            }
            break;

        case 'GR' :
            if (BisaJalan("RIGHT", M, *P)) {
                *P = NextX(*P);
                *J = PrevDetik(*J);
            } else {
                printf("Gabisa gerak");
            }
            break;

        case 'GL' :
            if (BisaJalan(&command, M, *P)) {
                *P = NextY(*P);
                *J = PrevDetik(*J);
            } else {
                printf("Gabisa gerak");
            }
            break;

        default:
            break;
    }
}*/
void GoUp(POINT *P, JAM *J, MATRIKS M, boolean Main) {
    if (BisaJalan("UP", M, *P)) {
        *P = NextY(*P);
        *J = PrevDetik(*J);
    } else {
        if(!Main && IsPointPintu(*P)) {
            MasukMainRoom();
            *J = PrevDetik(*J);
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoDown(POINT *P, JAM *J, MATRIKS M, boolean Main) {
    if (BisaJalan("DOWN", M, *P)) {
        *P = PrevY(*P);
        *J = PrevDetik(*J);
    } else {
        if (Main && IsPointPintu(*P)) {
            MasukDapur();
            *J = PrevDetik(*J);
        } else {
            printf("Gabisa gerak");
        }
    }
}

void GoRight(POINT *P, JAM *J, MATRIKS M) {
    if (BisaJalan("RIGHT", M, *P)) {
        *P = NextX(*P);
        *J = PrevDetik(*J);
    } else {
        printf("Gabisa gerak");
    }
}

void GoLeft(POINT *P, JAM *J, MATRIKS M) {
    if (BisaJalan("LEFT", M, *P)) {
        *P = NextY(*P);
        *J = PrevDetik(*J);
    } else {
        printf("Gabisa gerak");
    }
}