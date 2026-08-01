#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class TimeMap {
private:
    // key -> vector of (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // 因為 timestamp 是遞增傳入的，直接 push_back 即可維持 vector 有序
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 若 key 不存在，直接回傳空字串
        auto it = m.find(key);
        if (it == m.end()) {
            return "";
        }

        const auto& history = it->second;

        // 利用 upper_bound 找出第一個 timestamp > 目標 timestamp 的位置
        auto bound = upper_bound(
            history.begin(), 
            history.end(), 
            timestamp, 
            [](int target, const pair<int, string>& p) {
                return target < p.first;
            }
        );

        // 如果 bound 就在開頭，代表所有時間戳都大於目標 timestamp
        if (bound == history.begin()) {
            return "";
        }

        // (bound - 1) 即為 <= timestamp 中時間戳最大的紀錄
        return (bound - 1)->second;
    }
};