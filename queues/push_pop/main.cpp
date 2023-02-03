#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> numbers;
    int temp = 0;

    cout << "Pushing...\n";

    while (temp>=0)
    {
        cout << "Enter a number: ";
        cin >> temp;
        if (temp>=0)
            numbers.push(temp);
    }

    cout << "Printing...\n";
    while (numbers.size()>0)
    {
        cout << numbers.front() << endl;
        numbers.pop();
    }

    return 0;
}