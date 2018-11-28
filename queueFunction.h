/*  */
/*  */

#ifndef _QUEUEFUNCTION_H_
#define _QUEUEFUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
/* Modul lain yang digunakan : */
#include "./ADT/queue.h"
#include "kamus.h"


void Place(POINT P, Queue *QC, Tables *T, JAM *J);
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue */

void Order(States S);
/* I.S. --- */
/* F.S. --- */
/* Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain */

#endif