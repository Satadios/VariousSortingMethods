#include <stdio.h>

int main()
{
    int size_massive;
    if (scanf("%d", &size_massive) > 0 && size_massive > 0) {
        int massive[size_massive];

        for (int i = 0; i < size_massive; i++) {
            scanf("%d", &massive[i]);
        }

        for (int i = 0; i < size_massive - 1; i++) {
            if (massive[i] > massive[i + 1]) {
                int tmp = massive[i];
                massive[i] = massive[i + 1];
                massive[i + 1] = tmp;
                i = 0;
            }
        }

        for (int i = 0; i < size_massive; i++) {
            printf("%d ", massive[i]);
        }
        printf("\n");
    }

    return 0;
}
