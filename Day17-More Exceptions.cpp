#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Calculator{
    protected:
        int n;
        int p;
    public:
        int power(int n, int p){
            if(n < 0 || p < 0){
                throw invalid_argument("n and p should be non-negative");
            }

                return pow(n,p);
            
        }
};
/*
int main(){
    int T,n, p;
    cin>>T;
    Calculator cal = new Calculator();
    while(T--){
        cin>>n>>p;
        try{
            int result = cal.power(n,p);
            cout<<result;
        }catch(const char* msg){
            cerr << msg << endl;
        }

    }
    return 0;
}
*/
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}