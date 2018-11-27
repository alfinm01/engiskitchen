/* ADT print UI */
#include "matriks.h"
#include "stdio.h"

#ifndef _UI_H_
#define _UI_H_

#include "../kamus.h"
//#include "../ADT/mesin_kata.h"
void AssignMatriks(MATRIKS *M, char JenisRuang);
void printBatas();
void Map(MATRIKS *M, char JenisRuang);
void PrintUI(MATRIKS *M, char JenisRuang);

void ReadState(States *State);

#endif