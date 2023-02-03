#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    map<int, string> this_map;
    int temp;
    string str;
    pair<int, string> p;

    cout << "Inserting...\n";
    while(temp>=0){
        cout << "Enter a number: ";
        getline(cin, str);
        temp = stoi(str);
        if(temp>=0){
            p.first = temp;
            cout << "Enter a string: ";
            getline(cin, str);
            p.second = str;
            this_map.insert(p);
        }
    }

    cout << "Printing...\n";
    for(auto it=this_map.begin(); it!=this_map.end(); it++)
        cout << it->first << ":" << it->second << "  ";
        
    cout << endl;

    temp=0;
    cout << "Removing...\n";
    while(temp>=0){
        cout << "Enter a number: ";
        getline(cin, str);
        temp = stoi(str);
        if(temp>=0)
            this_map.erase(temp);
    }

    cout << "Printing...\n";
    for(auto it=this_map.begin(); it!=this_map.end(); it++)
        cout << it->first << ":" << it->second << "  ";


    return 0;

}