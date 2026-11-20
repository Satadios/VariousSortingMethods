//
// Created by Satadios on 11/19/26.
//

#ifndef FULLLAB03_FUNC_SORTING_H
#define FULLLAB03_FUNC_SORTING_H
#include <stdlib.h>
#include <string.h>

#endif
#include <stdio.h>

void simplest_sort(int *massive, size_t index_array, size_t count) {
    for (size_t i = index_array; i < index_array + count; i++) {
        if (massive[i] > massive[i + 1]) {
            int tmp = massive[i];
            massive[i] = massive[i + 1];
            massive[i + 1] = tmp;
            i = index_array;
        }
    }
}

void second_sort(int *massive, size_t index_array, size_t count) {
    for (int forward = index_array; forward < index_array + count; forward++) {
        for (int back = forward; back > index_array; back--) {
            if (massive[back] < massive[back - 1]) {
                int shablon = massive[back];
                massive[back] = massive[back - 1];
                massive[back - 1] = shablon;
            }
        }
    }
}

void third_sort(int *massive, size_t index_array, size_t count) {
    for (int symbol = index_array; symbol < index_array + count; symbol++) {
        int value = massive[symbol];
        int back = symbol - 1;

        while (back >= index_array && massive[back] > value) {
            massive[back + 1] = massive[back];
            back--;
        }
        massive[back + 1] = value;
    }
}

void fourth_sort(int *massive, size_t index_array, size_t count) {
    while (count > 0) {
        int maxNumber = 0;
        for (int i = index_array + 1; i < index_array + count; i++) {
            if (massive[i] > massive[maxNumber]) {
                maxNumber = i;
            }
        }
        int blank = massive[count - 1];
        massive[index_array + count - 1] = massive[maxNumber];
        massive[maxNumber] = blank;
        count--;
    }
}

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
