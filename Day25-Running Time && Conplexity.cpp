#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void isPrime(long long int n){
    int flag = 0;
    for(long long int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
    }
    if(flag == 0){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not prime"<<endl;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    long long int n;
    cin>>T;
    while(T--){
        cin>>n;
        isPrime(n);
    }
    return 0;
}

