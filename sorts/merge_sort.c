#include <stdio.h>
#include <time.h>

void merge(int Mass[], int Aux[], int a, int c, int b)
{
    int i = a;
    int j = c + 1;

    for(int k = a; k <= b; k++){
        if(i > c){
            Aux[k] = Mass[j];
            j++;
        } else if(j > b){
            Aux[k] = Mass[i];
            i++;
        } else if(Mass[i] <= Mass[j]){
            Aux[k] = Mass[i];
            i++;
        } else {
            Aux[k] = Mass[j];
            j++;
        }
    }

    for(int k = a; k <= b; k++){
        Mass[k] = Aux[k];
    }
}

void mergeSort(int Mass[], int Aux[], int a, int b)
{
    if(a >= b){
        return;
    }
    int c = (a + b) / 2;
    mergeSort(Mass, Aux, a, c);
    mergeSort(Mass, Aux, c + 1, b);
    merge(Mass, Aux, a, c, b);
}

int main()
{
    int count;
    scanf("%d", &count);

    int massive[count];
    int aux[count];
    int n = count;
    for(int symbol = 0; symbol < count; symbol++){
        scanf("%d", &massive[symbol]);
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);   // старт таймера

    mergeSort(massive, aux, 0, count - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);     // конец таймера

    for(int symbol = 0; symbol < n; symbol++){
        printf("%d ", massive[symbol]);
    }
    printf("\n");

    double seconds = (end.tv_sec - start.tv_sec)
                   + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(stderr, "Время сортировки: %.6f сек\n", seconds);

    return 0;
}
