#include <iostream>
#include "../output_writer.h"
#include "holamundo.h"
#include "holamundo.cpp"

using namespace std;

int main(int argc, char** argv){
    OutputCapture cap;

    HolaMundo obj1 = HolaMundo();
    obj1.saludar();

    writeAllOutputs("HolaMundo", cap.get());
    return 0;
}
