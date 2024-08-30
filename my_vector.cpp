

#include <iostream>
using namespace std;
class my_vector
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity = 0;

public:
    my_vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        capacity = size + 5;
        arr = new int[capacity]{};
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
        if (idx >= size)
        {
            cout << "Index: " << idx << " out of bound for Size: " << size << "\n";
            return;
        }

        arr[idx] = val;
    }

    int find(int val)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == val)
                return i;
        return -1;
    }

    void push_back(int val)
    {

        check_capacity();
        arr[size] = val;
        size++;
    }

    void check_capacity()
    {
        if (size == capacity)
            expand_capacity();
    }

    void expand_capacity()
    {
        cout << "\nexpand_capacity\n";
        capacity *= 2;
        int *temp = new int[capacity]{};
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
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