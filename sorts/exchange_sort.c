#include <stdio.h>

int main()
{
    int size_massive;
    if (scanf("%d", &size_massive) > 0 && size_massive > 0) {
        int massive[size_massive];

        for (int i = 0; i < size_massive; i++) {
            scanf("%d", &massive[i]);
        }

        for (int forward = 1;forward < size_massive;forward++) {
            for(int back = forward;back > 0;back--){
                if (massive[back] < massive[back - 1]) {
                    int shablon = massive[back];
                    massive[back] = massive[back - 1];
                    massive[back - 1] = shablon;
                }
            }
        }

        for (int i = 0; i < size_massive; i++) {
            printf("%d ", massive[i]);
        }
        printf("\n");
    }

    return 0;
}
