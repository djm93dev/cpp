#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& my_vector) {
    cout<<"Vector contains: { ";
    for(const int& num: my_vector)
        cout<<num<<" ";
    cout<<"}\n\n";

}

int main(){
    vector<int> numbers;
    int value=0;

    cout<<"Pushing back...\n";
    while(value>=0){
        cout<<"Enter a number: ";
        cin>>value;
        if(value>=0)
            numbers.push_back(value);
    }
    print(numbers);

    int index=0;

    cout<<"Inserting by index...\n";
    while(index>=0){
        cout<<"Enter index: ";
        cin>>index;
        if(index>=0){
            cout<<"Enter value: ";
            cin>>value;
            numbers[index] = value;
        }
    }
    print(numbers);
    return 0;
}