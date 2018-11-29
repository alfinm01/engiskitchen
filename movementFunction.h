/*  */
/*  */

#ifndef _MOVEMENTFUNCTION_H_
#define _MOVEMENTFUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

// #include "./ADT/array.h"
// #include "./ADT/garis.h"
#include "./ADT/jam.h"
// #include "./ADT/matriks.h"
// #include "./ADT/mesin_kar.h"
// #include "./ADT/mesin_kata.h"
#include "./ADT/point.h"
// #include "./ADT/queue.h"
#include "./ADT/stack.h"
// #include "./ADT/stacklist.h"

boolean BisaJalan(char *arah, MATRIKS M, POINT P);

void move(char *command, POINT *P, JAM *J, MATRIKS M);

#endif