class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false; // if val is already in the set
        nums.emplace_back(val); // add val to the end of nums
        m[val] = nums.size() - 1; // update the index of val in nums
        return true; // return true
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false; // if val is not in the set
        int last = nums.back(); // last element in nums
        m[last] = m[val]; // update the index of last in nums
        nums[m[val]] = last; // update the index of val in nums
        nums.pop_back(); // remove last from nums
        m.erase(val); // remove val from m
        return true; // return true
    }
    
    /** Get a random element from the set. */
    int getRandom() { 
        return nums[rand() % nums.size()]; // return a random element from nums
    }
private:
    vector<int> nums; // vector of elements in the set
    unordered_map<int, int> m; // map from val to the index of val in nums
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet s;
    cout << s.insert(1) << endl;
    cout << s.remove(2) << endl;
    cout << s.insert(2) << endl;
    cout << s.getRandom() << endl;
    cout << s.remove(1) << endl;
    cout << s.insert(2) << endl;
    cout << s.getRandom() << endl;
    return 0;
}