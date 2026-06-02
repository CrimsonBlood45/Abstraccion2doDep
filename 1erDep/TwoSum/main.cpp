#include <iostream>
#include "twosum.h"
#include "twosum.cpp"

using namespace std;

int main(int argc, char** argv){
    int num1, num2;
    cout << "Ingresa dos numeros: " << endl;
    cin >> num1;
    cin >> num2;
    TwoSum sum1 = TwoSum(num1, num2);
    sum1.sumar();
    sum1.showRes();
}