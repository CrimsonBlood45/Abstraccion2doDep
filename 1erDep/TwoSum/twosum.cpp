#include "twosum.h"

using namespace std;

TwoSum::TwoSum(double a, double b){
    num1 = a;
    num2 = b;
}
void TwoSum::sumar(){
    res = num1 + num2;
}
void TwoSum::showRes(){
    printf("%f + %f = %f\n", num1, num2, res);
}