#include <iostream>
#include "my_vector.cpp"
using namespace std;

int main()
{
    my_vector v(10);
    for (int i = 1; i <= 10; i++)
        v.set(i - 1, i);
    v.print();
    v.push_back(90);
    v.print();
}