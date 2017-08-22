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
    int sum = 0;//质数的总数
    printf("请输入一个整数：\n");
    scanf("%d",&n);
    for( i = 2; i <= n; i++){
            flag = is_prime(i);
            if(flag == 1){
                printf("%d ", i);
                sum++;
            }
    }
    printf("\n");
    printf("总数为:%d",sum);
    return 0;
}