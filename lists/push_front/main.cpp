#include <iostream>
#include <list>

using namespace std;

void print(const list<int>& my_list) {
    cout<<"list contains: { ";
    for(const int& num: my_list)
        cout<<num<<" ";
    cout<<"}\n\n";

}

int main(){
    list<int> numbers;
    int value=0;

    cout<<"Pushing front...\n";
    while(value>=0){
        cout<<"Enter a number: ";
        cin>>value;
        if(value>=0)
            numbers.push_front(value);
    }
    print(numbers);
    return 0;
}