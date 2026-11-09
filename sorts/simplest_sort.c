#include <stdio.h>
#include <time.h>

int main()
{
    int size_massive;
    if (scanf("%d", &size_massive) > 0 && size_massive > 0) {1
        int massive[size_massive];

        for (int i = 0; i < size_massive; i++) {
            scanf("%d", &massive[i]);
        }

        clock_t start = clock();

        for (int i = 0; i < size_massive - 1; i++) {
            if (massive[i] > massive[i + 1]) {
                int tmp = massive[i];
                massive[i] = massive[i + 1];
                massive[i + 1] = tmp;
                i = 0;
            }
        }

        clock_t end = clock();

        for (int i = 0; i < size_massive; i++) {
            printf("%d ", massive[i]);
        }
        printf("\n");

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(stderr, "Время сортировки: %f сек\n", seconds);
    }

    return 0;
}
