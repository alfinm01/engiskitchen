#include "kamus.h"

void New(States *State, Maps *MapMain, Maps *MapKitchen, MATRIKS *MatriksMain, MATRIKS *MatriksKitchen,
		TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Stack *FoodStack, Queue *QCust) {
	/* Kamus */
	char userName[20];
	int i;

	/* Algoritma */
	system("cls");
	uiHeader();

	printf("Nama Anda (max 20 karakter): ");							/* State */
	gets(userName);
	(*State).Name = (char *) malloc (strlen(userName) * sizeof(char));
	strcpy((*State).Name, userName);
	(*State).Life = 3;
	(*State).Position.X = 4;
	(*State).Position.Y = 4;
	(*State).Money = 0;
	(*State).Time = 0;
	(*State).IsInMain = true;

	InitMap(MapMain, 'M');												/* Map */
	InitMap(MapKitchen, 'K');

	MakeMATRIKS(8, 8, MatriksMain);						/* Matriks */
	MakeMATRIKS(8, 8, MatriksKitchen);

	for (i = 1; i <= 4; i++) {											/* Table */
		InitTable(&((*T).Table[i]), i);
	}

	for (i = 1; i <= 15; i++) {											/* Food & Kitchen */
		InitFood(&((*F).Food[i]), i);
		InitKitchen(&((*K).Kitchen[i]), i, (F)->Food[i]);
	}

	MakeEmpty(TOrder);													/* TOrder */

	CreateEmptyStackList(FoodStack);									/* Stack */

	CreateEmptyQueueList(QCust);										/* Queue */

	system("cls");
	uiHeader();
	printf("Hai, %s!\n", (*State).Name);
	printf("\nSelamat bermain :D\n");
}

void InitMap(Maps *Map, char MapType) {
	/* Kamus */
	char filename[] = "GameMap.txt";

	/* Algoritma */
	STARTKATA(filename);
	ADVKATA();

	while (!EndKata) {
		if (CKata.TabKata[1] == 'N') {
			ADVKATA();
			(*Map).N = CKata.TabKata[1] - '0';
		}
		else if (CKata.TabKata[1] == 'M') {
			ADVKATA();
			(*Map).M = CKata.TabKata[1] - '0';
		}
		else if ((CKata.TabKata[1] == 'D') && (CKata.TabKata[2] == 'M')) {
			if (MapType == 'M') {
				ADVKATA();
				(*Map).D.X = CKata.TabKata[1] - '0';
				ADVKATA();
				(*Map).D.Y = CKata.TabKata[1] - '0';
			}
		}
		else if ((CKata.TabKata[1] == 'D') && (CKata.TabKata[2] == 'K')) {
			if (MapType == 'K') {
				ADVKATA();
				(*Map).D.X = CKata.TabKata[1] - '0';
				ADVKATA();
				(*Map).D.Y = CKata.TabKata[1] - '0';
			}
		}
		ADVKATA();
	}
}

void InitTable(Tables *Table, int TableCounter) {
	/* Kamus */

	/* Algoritma */
	(*Table).Number = TableCounter;
	if ((*Table).Number % 2 == 1) {
		(*Table).Chair = 4;
	}
	else if ((*Table).Number % 2 == 0) {
		(*Table).Chair = 2;
	}
	(*Table).IsTableFull = false;
	// (*Table).Customer.Number = NULL;
	if ((*Table).Number == 1) {
		(*Table).Position.X = 2;
		(*Table).Position.Y = 2;
	}
	else if ((*Table).Number == 2) {
		(*Table).Position.X = 2;
		(*Table).Position.Y = 7;
	}
	else if ((*Table).Number == 3) {
		(*Table).Position.X = 7;
		(*Table).Position.Y = 2;
	}
	else if ((*Table).Number == 4) {
		(*Table).Position.X = 7;
		(*Table).Position.Y = 7;
	}
}

void InitFood(Foods *Food, int FoodCounter) {
	/* Kamus */
	char filename[] = "GameFood.txt";
	int i = 0;

	/* Algoritma */
	STARTKATA(filename);

	while (i < FoodCounter) {
		if (CKata.TabKata[1] == '|') {
			i++;
		}
		ADVKATA();
	}

	while ((!EndKata) && (CKata.TabKata[1] != '|')) {
		if (((CKata.TabKata[1] - '0') >= 10)) {
			(*Food).Name = (char *) malloc (CKata.Length * sizeof(char));
			for (i = 1; i <= CKata.Length; i++) {
				(*Food).Name[i - 1] = CKata.TabKata[i];
			}
		}
		else if ((CKata.TabKata[1] - '0') < 10) {
			(*Food).Price = 0;
			for (i = 1; i <= CKata.Length; i++) {
				(*Food).Price = ((*Food).Price * 10) + (CKata.TabKata[i] - '0');
			}
		}
		ADVKATA();
	}
}

void InitKitchen(Kitchens *Kitchen, int KitchenCounter, Foods Food) {		// Point Kitchen masukin Food ga?
	/* Kamus */
	char filename[] = "GameKitchen.txt";
	int i = 0;

	/* Algoritma */
	STARTKATA(filename);

	while (i < KitchenCounter) {
		if (CKata.TabKata[1] == '|') {
			i++;
		}
		ADVKATA();
	}

	while ((!EndKata) && (CKata.TabKata[1] != '|')) {
		if ((CKata.TabKata[1] - '0') < 10) {
			(*Kitchen).Position.X = (CKata.TabKata[1] - '0');
			ADVKATA();
			(*Kitchen).Position.Y = (CKata.TabKata[1] - '0');
		}
		ADVKATA();
	}

	(*Kitchen).Food = Food;
	(*Kitchen).Number = KitchenCounter;
}

void Load(States *State, Maps *MapMain, Maps *MapKitchen, MATRIKS *MatriksMain, MATRIKS *MatriksKitchen,
		TableArray *T, FoodArray *F, KitchenArray *K, TabOrder *TOrder, Stack *FoodStack, Queue *QCust) {
	/* Kamus */
	int i;

	/* Algoritma */
	ReadState(State);
	InitMap(MapMain, 'M');												/* Map */
	InitMap(MapKitchen, 'K');

	MakeMATRIKS(8, 8, MatriksMain);						/* Matriks */
	MakeMATRIKS(8, 8, MatriksKitchen);

	for (i = 1; i <= 4; i++) {											/* Table */
		InitTable(&((*T).Table[i]), i);
	}

	for (i = 1; i <= 15; i++) {											/* Food & Kitchen */
		InitFood(&((*F).Food[i]), i);
		InitKitchen(&((*K).Kitchen[i]), i, (F)->Food[i]);
	}

	MakeEmpty(TOrder);													/* TOrder */

	CreateEmptyStackList(FoodStack);									/* Stack */

	CreateEmptyQueueList(QCust);										/* Queue */

	system("cls");
	uiHeader();
	printf("Hai, %s!\n", (*State).Name);
	printf("\nSelamat bermain :D\n");
}

void ReadState(States *State) {
	/* Kamus */
	char filename[] = "GameState.txt", *myrealloced_array;
	int i, HH, MM, SS, prevLength;
	boolean readingName = false;

	/* Algoritma */
	STARTKATA(filename);
	ADVKATA();

	while (!EndKata) {
		/* Read Name */
		if ((CKata.TabKata[1] == 'N') && (CKata.TabKata[2] == 'a') &&
			(CKata.TabKata[3] == 'm') && (CKata.TabKata[4] == 'e')) {
			ADVKATA();
			(*State).Name = (char *) malloc (CKata.Length * sizeof(char));				// Tambah free?
			for (i = 1; i <= CKata.Length; i++) {
				(*State).Name[i - 1] = CKata.TabKata[i];
			}
			prevLength = CKata.Length;
			readingName = true;
		}
		/* Read Name > 1 word */
		else if (!((CKata.TabKata[1] == 'L') && (CKata.TabKata[2] == 'i') &&
			(CKata.TabKata[3] == 'f') && (CKata.TabKata[4] == 'e')) && readingName) {
			myrealloced_array = realloc((*State).Name, (prevLength + CKata.Length + 1) * sizeof(char));
			(*State).Name = myrealloced_array;
			(*State).Name[prevLength] = ' ';
			for (i = prevLength + 1; i <= prevLength + CKata.Length; i++) {
				(*State).Name[i] = CKata.TabKata[i - prevLength];
			}
			prevLength = prevLength + CKata.Length + 1;
		}
		/* Read Life */
		else if ((CKata.TabKata[1] == 'L') && (CKata.TabKata[2] == 'i') &&
			(CKata.TabKata[3] == 'f') && (CKata.TabKata[4] == 'e')) {
			ADVKATA();
			(*State).Life = CKata.TabKata[1] - '0';
			readingName = false;
		}
		/* Read Position */
		else if ((CKata.TabKata[1] == 'P') && (CKata.TabKata[2] == 'o') &&
			(CKata.TabKata[3] == 's') && (CKata.TabKata[4] == 'i') &&
			(CKata.TabKata[5] == 't') && (CKata.TabKata[6] == 'i') &&
			(CKata.TabKata[7] == 'o') && (CKata.TabKata[8] == 'n')) {
			ADVKATA();
			(*State).Position.X = CKata.TabKata[1] - '0';
			ADVKATA();
			(*State).Position.Y = CKata.TabKata[1] - '0';
		}
		/* Read Position */
		else if ((CKata.TabKata[1] == 'M') && (CKata.TabKata[2] == 'o') &&
			(CKata.TabKata[3] == 'n') && (CKata.TabKata[4] == 'e') &&
			(CKata.TabKata[5] == 'y')) {
			ADVKATA();
			(*State).Money = 0;
			for (i = 1; i <= CKata.Length; i++) {
				(*State).Money = ((*State).Money * 10) + (CKata.TabKata[i] - '0');
			}
		}
		/* Read Time */																// Time dalam bentuk JAM
		/*else if ((CKata.TabKata[1] == 'T') && (CKata.TabKata[2] == 'i') &&
			(CKata.TabKata[3] == 'm') && (CKata.TabKata[4] == 'e')) {
			ADVKATA();
			HH = ((CKata.TabKata[1] - '0') * 10) + (CKata.TabKata[2] - '0');
			ADVKATA();
			MM = ((CKata.TabKata[1] - '0') * 10) + (CKata.TabKata[2] - '0');
			ADVKATA();
			SS = ((CKata.TabKata[1] - '0') * 10) + (CKata.TabKata[2] - '0');
			(*State).Time = MakeJAM(HH, MM, SS);
		}*/
		/* SaveTime ga perlu dibaca (?) */
		ADVKATA();
	}
}