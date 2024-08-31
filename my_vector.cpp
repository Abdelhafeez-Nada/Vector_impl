

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
        times %= size;
        if (size < 2 || times == 0)
            return;
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

    void right_rotate_n_times_constant_memory(int times)
    {
        times %= size;
        if (size < 2 || times == 0)
            return;
        // 1-reverse the whole array
        reverse(0, size - 1);

        // 2-reverse rotation part
        reverse(0, times - 1);

        // 3-reverse shifted part
        reverse(times, size - 1);
    }

    void left_rotate_n_times_quadratic_time(int times)
    {
        // minimize times
        times %= size;
        // check edge cases
        if (size < 2 || times == 0)
            return;
        // outer loop for all rotation times
        for (int t = 0; t < times; t++)
        {
            int rotated = arr[0];
            for (int i = 1; i < size; i++)
                // left shift elements
                arr[i - 1] = arr[i];
            arr[size - 1] = rotated;
        }
    }

    void left_rotate_n_times_n_space(int times)
    {
        // minimize times
        times %= size;
        // check edge cases
        if (size < 2 || times == 0)
            return;

        // create temporary array that woll hold elements in new posistions
        int *temp = new int[capacity]{};
        int temp_itr = 0;

        // 1-insert shifted elemnts in temp array
        for (int i = times; i < size; i++)
            temp[temp_itr++] = arr[i];

        // 2-insert rotated elemnts in temp array
        for (int i = 0; i < times; i++)
            temp[temp_itr++] = arr[i];

        // 3-swap arrays
        delete[] arr;
        arr = temp;
    }

    void left_rotate_n_times_constant_space(int times)
    {
        // minimize times
        times %= size;
        // check edge cases
        if (size < 2 || times == 0)
            return;

        // 1-reverse whole array
        reverse(0, size - 1);

        // 2-reverse rotated part
        reverse(size - times, size - 1);

        // reverse shifted part
        reverse(0, size - times - 1);
    }

    int pop(int idx)
    {
        int poped = arr[idx];
        while (idx < size - 1)
            arr[idx] = arr[++idx];
        size--;
        return poped;
    }

    int find_transaposition(int val)
    {
        if (arr[0] == val)
            return 0;
        for (int i = 1; i < size - 1; i++)
        {
            if (arr[i] == val)
            {
                swap(i - 1, i);
                return i - 1;
            }
        }
        return -1;
    }

    void reverse(int start, int end)
    {
        while (start < end)
        {
            swap(start, end);
            start++;
            end--;
        }
    }

    void swap(int start, int end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
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