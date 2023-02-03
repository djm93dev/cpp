#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> back_stack;
    stack<string> forward_stack;
    string temp;

    while(temp!="exit"){
        cout << "[1] Visit a new URL    [2] Back    [3] Forward" << endl;
        cin >> temp;
        if(temp=="exit")
            break;
        if(temp=="1"){
            cout<<"Enter URL: ";
            cin>>temp;
            back_stack.push(temp);
            forward_stack = stack<string>();

        }
        else if(temp=="2"){
            cout << "Going back... \n";
            forward_stack.push(back_stack.top());
            back_stack.pop();
        }
        else if(temp=="3"){
            if(forward_stack.empty())
                cout << "No more URLs to visit forward" << endl;
            else{
                cout << "Going forward... \n";
                back_stack.push(forward_stack.top());
                forward_stack.pop();
            }
        }
        else{
            cout << "Invalid input" << endl;
        }
        if (back_stack.empty())
            break;
        cout << "\nCurrent URL: " << back_stack.top() << endl;
    }
    return 0;
}