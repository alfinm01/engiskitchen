#include "kamus.h"

void Give() {
}

void CT(Stack *S) {
    addressStackList P;

    P = Top(*S);
    DealokasiStackList(&P);
    CreateEmptyStackList(&S);
}


// void Take(Stack *S) {
//     if (SekitarMejaDapur()) {
//         Pop(&S, Food(K))
//     }

// }