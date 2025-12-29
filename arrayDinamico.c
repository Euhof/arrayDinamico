#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    size_t capacidade;
    size_t contagem;
}Numeros;

// Array dinamico
#define da_append(xs, x)\
    do {\
        if (xs.contagem >= xs.capacidade) {\
            if (xs.capacidade == 0) {\
                xs.capacidade = 256;\
            }else{\
                xs.capacidade *= 2;\
            }\
            xs.item = realloc(xs.item, xs.capacidade * sizeof(xs.item));\
        }\
        xs.item[xs.contagem++] = x;\
    }while(0)
 
int main() {
    Numeros xs = {0};

    for (int x = 0; x < 10; x++) {
        da_append(xs,x); //uso do array dinamico
    }

    for (size_t i = 0; i < xs.contagem; i++) {
        printf("\n->%d", xs.item[i]);
    }

    return 0;
}
