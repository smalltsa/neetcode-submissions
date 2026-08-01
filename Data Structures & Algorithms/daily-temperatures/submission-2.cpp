class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<pair<int,int>> stack;
        for (int i = 0; i < temperatures.size(); ++i){
            while(!stack.empty() && temperatures[i] > stack.top().first){
                int prevIdx = stack.top().second;
                res[prevIdx] = i - prevIdx;
                stack.pop();
            }

            stack.push({temperatures[i],i});
        }
        return res;
    }
};
