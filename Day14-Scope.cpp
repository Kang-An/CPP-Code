/*
When dealing with a class variable (field), 
it's always best to explicitly refer to it using the this keyword. 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    Difference(vector<int> a){
        this->elements = a;
    }

    void computeDifference(){
        //由于都是正数，找出最大值和最小值即可求得最大的绝对值
        vector<int>::iterator max = std::max_element(std::begin(elements), std::end(elements));
        vector<int>::iterator min = std::min_element(std::begin(elements), std::end(elements));

        this->maximumDifference = *max - *min;
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}