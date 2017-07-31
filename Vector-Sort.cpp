#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v;
    int N;
    cin>>N;
    int tmp;
    for(int i = 0; i < N;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    /*
    for(std::vector<int>::iterator m = v.begin(); m!= v.end();m++)
    {
        cout<<*m<<" ";
    }
    */
    for(int i = 0; i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}