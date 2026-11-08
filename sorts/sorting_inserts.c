#include <stdio.h>

int main()
{
    int back;
    int value;

    int count;
    scanf("%d", &count);

    int massive[count];
    for(int symbol = 0; symbol < count; symbol++){
        scanf("%d", &massive[symbol]);
    }
    for(int symbol = 1; symbol < count; symbol++){
        value = massive[symbol];
        back = symbol - 1;

        while(back >= 0 && massive[back] > value){
            massive[back + 1] = massive[back];
            back--;
        }
        massive[back + 1] = value;
    }

    for(int symbol = 0; symbol < count; symbol++){
        printf("%d ", massive[symbol]);
    }
    printf("\n");

    return 0;
}
