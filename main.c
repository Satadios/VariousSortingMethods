#include <stdio.h>

#include "func_sorting.h"


int main(void) {
    int a[] = {1,0,2,3,4,5,7,6,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    MergeSort(a, n);
    for (int i = 0; i < 9; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
