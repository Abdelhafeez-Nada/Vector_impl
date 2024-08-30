

#include <iostream>
using namespace std;
class my_vector
{
private:
    int *arr = nullptr;
    int size = 0;

public:
    my_vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        arr = new int[size]{};
    }

    ~my_vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get(int idx)
    {
        return arr[idx];
    }

    void set(int idx, int val)
    {
        arr[idx] = val;
    }

    int find(int val)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == val)
                return i;
        return -1;
    }

    void push_back(int el)
    {
        size += 1;
        int *temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        temp[size - 1] = el;
        delete[] arr;
        arr = temp;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};