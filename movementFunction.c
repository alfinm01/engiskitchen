#include "movementFunction.h"
#include "./ADT/point.h"
#include "./ADT/matriks.h"

boolean BisaJalan(char *arah, MATRIKS M, POINT P) {
    switch (*arah) {
        case 'GU' :
            return((IsIdxValid(P.X, (P.Y + 1))) && (Elmt(M, P.X, (P.Y + 1)) = ' '));
            break;
        case 'GD' :
            return((IsIdxValid(P.X, (P.Y - 1))) && (Elmt(M, P.X, (P.Y - 1)) = ' '));
            break;
        case 'GR' :
            return((IsIdxValid((P.X + 1), P.Y)) && (Elmt(M, (P.X + 1), P.Y) = ' '));
            break;
        case 'GL' :
            return((IsIdxValid((P.X - 1), P.Y)) && (Elmt(M, (P.X - 1), P.Y) = ' '));
            break;
        }
    
}

void move(char *command, POINT *P, JAM *J, MATRIKS M, boolean B) {
    switch (*command) {
        case 'GU' :
            if (BisaJalan(&command, M, *P)) {
                *P = NextY(*P);
                *J = PrevDetik(*J);
            } else {
                if(IsPointPintu(*P)) {
                    MasukMainRoom();
                    *J = PrevDetik(*J);
                } else {
                    printf("Gabisa gerak");
                }
            }
            break;

        case 'GD' :
            if (BisaJalan(&command, M, *P)) {
                *P = PrevY(*P);
                *J = PrevDetik(*J);
            } else {
                if (IsPointPintu(*P)) {
                    MasukDapur();
                    *J = PrevDetik(*J);
                } else {
                    printf("Gabisa gerak");
                }
            }
            break;

        case 'GR' :
            if (BisaJalan(&command, M, *P)) {
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
}