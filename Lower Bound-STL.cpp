#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, element, query_num, query_value;
    vector<int> v;  
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>element;
        v.push_back(element);
    }
    cin>>query_num;
    for(int i = 0; i < query_num; i++)
    {
        cin>>query_value;
        bool is_find = false;
        for(int j = 0; j < v.size(); j++){
            if(v[j] == query_value){
                cout<<"yes "<<i+1<<endl;        
                is_find = true;
            }
        }
        if(is_find == false){
            sort(v.begin(), v.end());
            for(int j = 0; j < v.size() - 1; j++){
                if(v[j] < query_value && v[j+1] > query_value){
                    cout<<"no "<<v[j+1]<<endl;
                }
            }
        }
    } 
    return 0;
}