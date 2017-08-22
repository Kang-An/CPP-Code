#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    double meal_cost, 
    int tip_percent, tax_percent;
    cin<<meal_cost<<tip_percent<<tax_percent;

    double tip = meal_cost * (tip_percent / 100.0);
    double tax = meal_cost * (tax_percent / 100.0);

    double result = meal_cost + tip + tax;

    cout<<round(result);
    return 0;
}