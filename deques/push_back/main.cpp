#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> numbers;
    int temp = 0;

    cout << "Pushing Back...\n";
    while (temp>=0)
    {
        cout << "Enter a number: ";
        cin >> temp;
        if (temp>=0)
            numbers.push_back(temp);
    }

    deque<int>::iterator it;
    cout << "Printing...\n";
    for (it=numbers.begin(); it!=numbers.end(); it++)
        cout << *it << endl;

    return 0;
}