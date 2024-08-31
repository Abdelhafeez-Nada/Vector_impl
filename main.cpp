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
    // int arr[5]{1, 2, 3, 4, 5};
    // int start = 0, end = 4;
    // while (start < end)
    // {
    //     std::swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }
    // printArr(arr, 5);
    // my_vector v(0);
    // for (int i = 1; i <= 10; i++)
    //     v.push_back(i);
    // v.print();
    // v.push_back(90);
    // v.print();
    // v.insert(88, 2);
    // v.print();
    // v.right_rotate_n_times_n_memory(16);
    // v.print();
    // v.left_rotate();
    // v.print();
}