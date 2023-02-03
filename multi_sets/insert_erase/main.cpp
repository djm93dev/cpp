#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main(){
    multiset<int> this_set;
    int temp;

    cout << "Inserting...\n";
    while(temp>=0){
        cout << "Enter a number: ";
        cin >> temp;
        if(temp>=0)
            this_set.insert(temp);
    }

    temp=0;
    cout << "Removing...\n";
    while(temp>=0){
        cout << "Enter a number: ";
        cin >> temp;
        if(temp>=0)
            this_set.erase(temp);
    }

    cout << "Printing...\n";
    for(auto it=this_set.begin(); it!=this_set.end(); it++)
        cout << *it << " ";

    return 0;
}