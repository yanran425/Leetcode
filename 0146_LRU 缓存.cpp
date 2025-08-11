
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
    list<int> v;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int capacity = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        auto tmp = m.find(key);
        if (tmp == m.end())
        {
            return -1;
        }
        else
        {
            v.erase(tmp->second.second);
            v.push_back(key);
            m[key].second = --v.end();
            return this->m[key].first;
        }
    }

    void put(int key, int value) {
        if (this->get(key) != -1)
        {
            m[key].first = value;
            return;
        }
        if (this->v.size() == this->capacity)
        {
            int tmp = v.front();
            v.pop_front();
            m.erase(tmp);
        }
        this->v.push_back(key);
        m[key] = make_pair(value, --v.end());
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    l.get(1);
    l.put(3, 3);
    l.get(2);
    l.put(4, 4);
    l.get(1);
    l.get(3);
    l.get(4);
    return 0;
}