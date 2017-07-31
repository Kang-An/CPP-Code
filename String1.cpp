#include <iostream>
#include <string>
using namespace std;
//输出两个字符串a和b，得出a和b的长度，之后让a与b的首字符进行交换并输出
int main()
{
    string a,b;
    char tmp;
    cin>>a;
    cin>>b;
    cout<<a.size()<<" "<<b.size()<<endl;

    cout<<a+b<<endl;

    tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;

    cout<<a<<" "<<b<<endl;

    return 0;
}
