/* ADT print UI */

#ifndef _UI_H_
#define _UI_H_

#include "../kamus.h"
#include "string.h"
#include "stdio.h"

void printMoney(int money);
void printLife(int life);
void printTime(int time);
void printNama(char *name);
void AssignMatriks(MATRIKS *M, boolean Main, POINT Player);
void printBatas();
void Map(MATRIKS *M, boolean Main, POINT Player);
void PrintUI(MATRIKS *M, boolean Main, char *name, int money, int life, int time, POINT Player, Queue Q, Stack S, TabOrder A);

#endif