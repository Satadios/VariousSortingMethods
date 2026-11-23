#include <stdio.h>
//1.6 Слиянием
void merge_sort(int *a, int *b, int l,int r) {
    if (l < r) {
        int c = (l + r) / 2;
        merge_sort(b, a,l,c);
        merge_sort(b,a,c+1,r);
        int i = l;
        int j = c + 1;
        int k = l;
        while (i <= c && j <= r) {
            if (b[i] < b[j]) {
                a[k++] = b[i++];
            } else {
                a[k++] = b[j++];
            }
        }
        while (i <= c) { a[k++] = b[i++]; }
        while (j <= r) { a[k++] = b[j++]; }

    }
}

void MergeSort(int *a, int n) {
    int *b = (int *)malloc(n * sizeof(int));
    memcpy(b, a,n * sizeof(int));
    merge_sort(a , b,0,n - 1);
    free(b);
}

int main()
{
    int a[] = {1,0,2,3,4,5,7,6,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    MergeSort(a, n);
    for (int i = 0; i < 9; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
