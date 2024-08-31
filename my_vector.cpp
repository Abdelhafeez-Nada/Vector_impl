

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
        if (is_valid_idx(idx))
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

    void insert(int val, int idx)
    {
        if (is_valid_idx(idx))
        {
            check_capacity();
            for (int i = size - 1; i >= idx; i--)
                arr[i + 1] = arr[i];
            arr[idx] = val;
            size++;
        }
    }

    void right_rotate(int times)
    {
        if (size < 2)
            return;
        times %= size;
        for (int time = 0; time < times; time++)
        {
            int tmp = arr[size - 1];
            for (int i = size - 2; i >= 0; i--)
                arr[i + 1] = arr[i];
            arr[0] = tmp;
        }
    }

    void left_rotate()
    {
        if (size < 2)
            return;
        int tmp = arr[0];
        for (int i = 1; i < size; i++)
            arr[i - 1] = arr[i];
        arr[size - 1] = tmp;
    }

    void right_rotate_n_times_n_memory(int times)
    {
        if (size < 2 || times == size)
            return;
        times %= size;
        int idx = size - times;
        int *tmp = new int[capacity];
        int j = 0;
        for (int i = idx; i < size; i++)
            tmp[j++] = arr[i];

        for (int i = 0; i < idx; i++)
            tmp[j++] = arr[i];
        delete[] arr;
        arr = tmp;
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

    bool is_valid_idx(int idx)
    {
        if (idx >= size)
        {
            cout << "Index: " << idx << " out of bound for Size: " << size << "\n";
            return false;
        }
        return true;
    }
};