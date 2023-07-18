#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> timeline;
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        auto &p = cache[key];
        timeline.erase(p.second);
        timeline.push_front(key);
        p.second = timeline.begin();
        return p.first;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            auto &p =cache[key];
            p.first = value;
            timeline.erase(p.second);
            timeline.push_front(key);
            p.second = timeline.begin();
            return;
        }
        timeline.push_front(key);
        cache[key] = {value, timeline.begin()};
        if(cache.size() > capacity){
            int p = timeline.back();
            cache.erase(p);
            timeline.pop_back();
        }
    }
};
