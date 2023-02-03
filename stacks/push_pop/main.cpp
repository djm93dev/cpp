#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> numbers;
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
        cout << numbers.top() << endl;
        numbers.pop();
    }

    return 0;
}