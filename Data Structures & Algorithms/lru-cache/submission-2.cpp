#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;

    // front = most recently used
    // back  = least recently used
    list<pair<int, int>> cache;

    // key -> cache 中該節點的位置
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // 找不到
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // 找到了，代表它剛被使用
        // 移到最前面
        auto it = mp[key];

        cache.splice(cache.begin(), cache, it);

        return it->second;
    }

    void put(int key, int value) {

        // key 已經存在
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];

            // 更新 value
            it->second = value;

            // 剛使用過，移到最前面
            cache.splice(cache.begin(), cache, it);

            return;
        }

        // 新 key
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // 超過容量
        if (cache.size() > capacity) {

            // 最後面 = 最久沒使用
            int oldKey = cache.back().first;

            mp.erase(oldKey);
            cache.pop_back();
        }
    }
};