/* ADT print UI */

#ifndef _UI_H_
#define _UI_H_

#include "../kamus.h"
#include "string.h"
#include "stdio.h"

void AssignMatriks(MATRIKS *M, char JenisRuang);
void printBatas();
void Map(MATRIKS *M, char JenisRuang);
void PrintUI(MATRIKS *M, char JenisRuang, char *name, int money, int life, int time);

#endif