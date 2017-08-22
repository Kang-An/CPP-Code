#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
    int i;
    int flag;
    int a = 0;
    for(i=2;i<num;i++){
        if(num%i==0){
            a++;  // 素数个数加1
        }
    }
    if(a==0){
        flag = 1;//是素数
    }else{
        flag = 0;//不是素数
    }
    return flag;
}

int main()
{
    int n;
    int flag;
    int i;
    printf("请输入一个整数：\n");
    scanf("%d",&n);
    for( i = 2; i <= n; i++){
        if(n % i == 0)
        {
            flag = is_prime(i);
            if(flag == 1)//该约数是素数
                printf("质约数为%d\n",i);

        }
    }
    return 0;
}
