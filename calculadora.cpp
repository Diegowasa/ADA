
#include <iostream>
using namespace std;
// Code B
// User type to simplify the declaration

float Addition(float x, float y) {
    return x + y;
}
float Substraction(float x, float y) {
    return x - y;
}
float Multiplication(float x, float y) {
    return x * y;
}
float Division(float x, float y) {
    return x / y;
}
int main()
{
    typedef float (*lpfnOperation)(float, float);
    // CVector of pointer to functions
    lpfnOperation vpf[4] = { &::Addition, &::Substraction,
    &::Multiplication, &::Division };
    float a, b, c;
    int opt;
    // enter the operands
    cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    cout << c << endl;
}
