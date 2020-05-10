#include <iostream>

using namespace std;

class LRUCache {
    
    int capacity;
    
    list <pair<int, int>> lruCache;
    unordered_map <int, list<pair<int,int>>::iterator> hash;        // Key stored both in List and Hash.
    
    void updateUse(int key, int value)
    {
        lruCache.erase(hash[key]);                      // pop out the element
        lruCache.push_front(make_pair(key, value));     // insert at front
        hash[key] = lruCache.begin();                   // Update Hash map
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;                                  // Element not in cache - Return
        
        updateUse(key, (*hash[key]).second);
        return ((*hash[key]).second);
        
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end())
            updateUse(key, value);                      // Element in cache, do not add, only move it front
        else
        {
            lruCache.push_front(make_pair(key, value)); // Add the element to cache
            hash[key] = lruCache.begin();               // Update hash map
            if (hash.size() > capacity)
            {
                hash.erase(lruCache.back().first);
                lruCache.pop_back();
            }   
        }
    }
};

int main ()
{

 LRUCache* obj = new LRUCache(capacity);
 int param_1 = obj->get(key);
 obj->put(key,value);

return 0;
}
