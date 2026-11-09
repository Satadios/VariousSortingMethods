#include <stdio.h>
#include <time.h>

int main()
{
    int count;
    scanf("%d", &count);

    int massive[count];
    int n = count;
    for(int symbol = 0; symbol < count; symbol++){
        scanf("%d", &massive[symbol]);
    }
    int blank;
    clock_t start = clock();
    while(count != 0){
        int maxNumber = 0;
        for(int i =1 ; i < count; i++){
            if(massive[i] > massive[maxNumber]){
                maxNumber=i;
            }
        }
        blank = massive[count-1];
        massive[count-1] = massive[maxNumber];
        massive[maxNumber] = blank;
        count--;
    }
    clock_t end = clock();
    for(int symbol = 0; symbol < n; symbol++){
        printf("%d ", massive[symbol]);
    }
    printf("\n");

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(stderr, "Время сортировки: %f сек\n", seconds);

    return 0;
}
