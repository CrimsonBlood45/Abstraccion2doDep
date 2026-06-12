#include "twosum.h"
#include <iostream>

using namespace std;

TwoSum::TwoSum(double a, double b){
    num1 = a;
    num2 = b;
}
void TwoSum::sumar(){
    res = num1 + num2;
}
void TwoSum::showRes(){
    cout << num1 << " + " << num2 << " = " << res << endl;
}
