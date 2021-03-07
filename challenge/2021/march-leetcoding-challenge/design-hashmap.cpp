class MyHashMap {
    int n = 10000;
    vector<list<pair<int,int>>> ret;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        ret.resize(n);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = ret[key % n];
        for (auto &p : list) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &list = ret[key % n];
        for (auto &p : list) {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = ret[key % n];
        for(auto i = list.begin(); i != list.end(); i++) {
            if(i->first == key) {
                list.erase(i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */