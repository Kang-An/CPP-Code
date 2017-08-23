#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int consecutive_binary(int n); 

int main()
{

    int n;
    cin >> n;
    cout << consecutive_binary(n);


    return 0;
}

int consecutive_binary(int n)
{
    // Loop (performance over recursion)
    int curr = 0;
    int count = 0, max_count = 0;
    while(n)
    {   
        curr = n % 2;
        if (curr)
        {   
            count++;
        }   
        else
        {   
            if (count > max_count)
                max_count = count;
            count = 0;
        }   

            
        n /= 2;
    }   
        
    // last extra check
    if (count > max_count)
        max_count = count;

    return max_count;
}
