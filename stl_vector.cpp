#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> numbers;

    for (int i = 0; i <= 9; i++)
    {
        numbers.push_back(i);
    }

    for (int num : numbers)
    {
        cout << num << "\n";
    }

    // vector<int>::iterator itr_begin = numbers.begin();
    cout << "---------------------------------------" << "\n";
    for (auto itr = numbers.begin(); itr < numbers.end(); itr++)
    {
        cout << *itr << "\n";
    }
}