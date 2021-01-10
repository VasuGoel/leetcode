// O(1) average time getRandom() operation. Using vector to store nums and record indices in hashmap.
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> mp;
    
public:
    bool insert(int val) {
        if(mp.count(val))   return false;
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    
    // remove val from vector and hashmap in constant time using mapped index
    bool remove(int val) {
        if(!mp.count(val))  return false;
        nums[mp[val]] = nums.back();
        mp[nums.back()] = mp[val];
        
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(1) average time getRandom() operation. Using pointers in C++.
class RandomizedSet {
    unordered_set<int> s;
    
public:
    bool insert(int val) {
        if(s.count(val))    return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!s.count(val))   return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(s.begin(), rand() % s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
