/*  */
/*  */

#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

#include "kamus.h"

void New(States *State, Maps *MapMain, Maps *MapKitchen, TableArray *T, FoodArray *F, KitchenArray *K);

void InitMap(Maps *Map, char MapType);

void InitTable(Tables *Table, int TableCounter);

void InitFood(Foods *Food, int FoodCounter);

void InitKitchen(Kitchens *Kitchen, int KitchenCounter, Foods Food);

void Load(States *State, Maps *MapMain, Maps *MapKitchen);

void ReadState(States *State);






#endif