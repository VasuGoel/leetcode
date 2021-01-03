class LRUCache {
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> dict;
    int capacity;
    
public:
    LRUCache(int capacity): capacity(capacity) { cache.clear(), dict.clear(); }
    
    int get(int key) {
        // if key not present in hash table
        if(dict.find(key) == dict.end())    return -1;
        
        // otherwise, return value after deleting key-value from cache and hash table and inserting at beginning of cache
        auto itr = dict[key];
        int val = itr->second;
        cache.erase(itr), dict.erase(key);
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        // if key is already present, delete it from list and hash table
        if(dict.find(key) != dict.end()) {
            cache.erase(dict[key]), dict.erase(key);
        }
        // cache at max capacity, delete least recently used (last in list) item from cache and hash table
        else if (cache.size() == capacity) {
            int lru = cache.back().first;
            cache.erase(dict[lru]), dict.erase(lru);
        }
        
        // insert new key-value pair at the front of cache list and map key with its iterator
        cache.push_front({key, value});
        dict[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
