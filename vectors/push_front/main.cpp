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

    cout<<"Pushing front...\n";
    while(value>=0){
        cout<<"Enter a number: ";
        cin>>value;
        if(value>=0)
            numbers.insert(numbers.begin(), value);
    }
    print(numbers);
    return 0;
}