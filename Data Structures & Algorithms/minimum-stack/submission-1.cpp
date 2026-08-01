#include <vector>
#include <algorithm> // 提供 std::min 使用

class MinStack {
private:
    std::vector<int> data;     // 主陣列
    std::vector<int> min_data; // 歷史最小值陣列（你的 min array）

public:
    MinStack() {
        // C++ 的 vector 在宣告時會自動初始化，這裡可以保持空白
    }
    
    void push(int val) {
        data.push_back(val);
        
        // 如果 min_data 是空的，當前 val 就是最小值
        // 否則，拿當前的 val 跟「之前的歷史最小值」做比較，把較小的那個推進去
        if (min_data.empty()) {
            min_data.push_back(val);
        } else {
            min_data.push_back(std::min(val, min_data.back()));
        }
    }
    
    void pop() {
        // 兩個陣列必須「同步」彈出，確保歷史時間點一致
        data.pop_back();
        min_data.pop_back();
    }
    
    int top() {
        return data.back(); // back() 直接安全取得最後一筆數據
    }
    
    int getMin() {
        return min_data.back(); // min_data 的尾端永遠是當前狀態下的最小值！
    }
};