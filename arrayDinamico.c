#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    size_t capacidade;
    size_t contagem;
}Elementos;

// Array dinamico como macro
#define push_array(xs, x)\
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
    Elementos xs = {0}; //xs pode ser lido como "Diversos"

    for (int x = 0; x < 10; x++) {
        push_array(xs,x); //usando o array dinamico
    }

    for (size_t i = 0; i < xs.contagem; i++) {
        printf("\n->%d", xs.item[i]); //items
    }

    return 0;
}
