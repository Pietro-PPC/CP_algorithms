#include <stdio.h>

#define MAX 1

void print_mat_int(int *m[MAX], int l, int c){
    for (int i = 0; i < l; ++i){
        for (int j = 0; j < c; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}
