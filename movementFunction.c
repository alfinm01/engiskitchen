#include "movementFunction.h"

void move(char *command, POINT *P, JAM *J) {
    

    switch (*command)
    {
        case 'GU' :
            if (!BatasAtas(P)) {
                *P = NextY(*P);
                *J = PrevDetik(*J);
            }
            break;

        case 'GD' :
            if (!BatasBawah(P) && !IsPointPintu(*P)) {
                *P = PrevY(*P);
                *J = PrevDetik(*J);
            }
            break;

        case 'GR' :
            if (!BatasKanan(P)) {
                *P = NextX(*P);
                *J = PrevDetik(*J);
            }
            break;

        case 'GL' :
            if (!BatasKiri(P)) {
                *P = PrevY(*P);
                *J = PrevDetik(*J);
            }
            break;

        default:
            break;
    }
}