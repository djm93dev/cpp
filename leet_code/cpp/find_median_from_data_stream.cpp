#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> decreasing; // max heap
    priority_queue<int, vector<int>, greater<int>> increasing; // min heap
    bool evn = true; // set evn to true
    MedianFinder() { // constructor
    }
    void addNum(int num) { // method addNum
        evn =!evn; // set evn to !evn
        if(!evn){ // if !evn
        decreasing.push(num); // push num to decreasing
        increasing.push(decreasing.top()); // push decreasing.top() to increasing
        decreasing.pop();} // pop decreasing
        else{ // else
              increasing.push(num); // push num to increasing
              decreasing.push(increasing.top()); // push increasing.top() to decreasing
              increasing.pop(); // pop increasing
        }
      
    }
    double findMedian() { // method findMedian
        if (!evn) return increasing.top(); // if !evn return increasing.top()
        return (decreasing.top() + increasing.top()) / 2.0; // return (decreasing.top() + increasing.top()) / 2.0
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder s;
    s.addNum(1);
    s.addNum(2);
    cout << s.findMedian() << endl;
    s.addNum(3);
    cout << s.findMedian() << endl;
    return 0;
}