#include <iostream>
#include "my_vector.cpp"
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{

    my_vector v(0);
    for (int i = 1; i <= 10; i++)
        v.push_back(i);
    v.print();
    v.push_back(90);
    v.print();
    v.insert(88, 2);
    v.print();
}