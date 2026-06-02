#include <iostream>
#include "../output_writer.h"
#include "twosum.h"
#include "twosum.cpp"

using namespace std;

int main(int argc, char** argv){
    OutputCapture cap;

    int num1, num2;
    cout << "Ingresa dos numeros: " << endl;
    cin >> num1 >> num2;

    TwoSum sum1 = TwoSum(num1, num2);
    sum1.sumar();
    sum1.showRes();

    writeAllOutputs("TwoSum", cap.get());
    return 0;
}
