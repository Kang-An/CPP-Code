#include <iostream>
#include <string>
using namespace std;
//��������ַ���a��b���ó�a��b�ĳ��ȣ�֮����a��b�����ַ����н��������
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
