#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
int main()
{
    int n;
    printf("输入一个整数：\n");
    scanf("%d", &n);

    int i;
    for( i = 1; i <= n; i++){
        if(n % i == 0)
        {
            printf("约数为%d\n", i);

        }
    }

    return 0;
}
