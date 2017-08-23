/*

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic{//不声明为public 编译失败
    private:
        int divisorSum(int n){
            vector<int> num;
            int sum = 0;
            for(int i = 1; i <= n; i++){
                if(n % i == 0)
                    num.push_back(i);
            }
            
            for(int i = 0; i < num.size();i++){
                sum += num[i];
            }

            return sum;
        }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}