class LRUCache {
public:
    LRUCache(int capacity)
            : cap{capacity} {}
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        q.remove(key); // O(N) ❌ 
        q.push_front(key);
        return m[key];
    }
    void put(int key, int val) {
        q.remove(key); // O(N) ❌
        while (q.size() >= cap) {
            auto del = q.back(); q.pop_back();
            m.erase(del);
        }
        q.push_front(key);
        m[key] = val;
    }
private:
    int cap;
    list<int> q;
    unordered_map<int, int> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
