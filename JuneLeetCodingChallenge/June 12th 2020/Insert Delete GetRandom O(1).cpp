class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not
     *  already contain the specified element.
     */
    bool insert(int val) {
        if(hash.count(val)) return false;
        hash[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained
     *  the specified element.
     */
    bool remove(int val) {
        if(!hash.count(val)) return false;
        int idx = hash[val];
        int last = nums.back();
        // move the last element to the position of the removed element
        // we only need to do so if the element to be removed is not the last element.
        if(last != val){
            nums[idx] = last;
            hash[last] = idx;
        }
        hash.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int k = rand() % nums.size();
        return nums[k];
    }

private:
    unordered_map<int, int> hash;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
