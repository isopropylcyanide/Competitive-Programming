#include <stdio.h>
#include <stdlib.h>
#define mod 1000000009

int* performOps(int *A, int len, int *blen) {
    int i;
    *blen = len * 2;
    int *B = (int *)malloc((*blen) * sizeof(int));
    for (i = 0; i < len; i++) {
        B[i] = A[i];
        B[i + len] = A[(len - i) % len];
    }
    return B;
}


int main()
 {
     int blen;
     int A[] = {5,10,2,1};
     int *B = performOps(A,  4, &blen);
     int i;
     for (i = 0; i < blen; i++) {
         printf("%d ", B[i]);
     }

 }
