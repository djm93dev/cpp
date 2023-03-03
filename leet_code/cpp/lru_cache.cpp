#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;


class LRUCache
{
    public:
        list<pair<int,int>> l;
        unordered_map<int,list<pair<int, int>>::iterator> m;
        int size;
        LRUCache(int capacity)
        {
            size=capacity; // Set the size of the cache.
        }
        int get(int key) // Get the value of the key.
        {
            if(m.find(key)==m.end()) // If the key is not in the map.
                return -1; // Return -1.
            l.splice(l.begin(),l,m[key]); // Move the key to the front of the list.
            return m[key]->second; // Return the value of the key.
        }
        void put(int key, int value) // Put the key and value into the cache.
        {
            if(m.find(key)!=m.end()) // If the key is in the map.
            { 
                l.splice(l.begin(),l,m[key]); // Move the key to the front of the list.
                m[key]->second=value; // Set the value of the key.
                return; // Return.
            }
            if(l.size()==size) // If the list is full.
            {
                auto d_key=l.back().first; // Get the key of the last element in the list.
                l.pop_back(); // Remove the last element from the list.
                m.erase(d_key); // Remove the key from the map.
            }
            l.push_front({key,value}); // Add the key and value to the front of the list.
            m[key]=l.begin(); // Add the key and the iterator to the front of the list to the map.
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}

