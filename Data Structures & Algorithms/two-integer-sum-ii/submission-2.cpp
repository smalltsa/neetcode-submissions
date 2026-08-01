class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0, rear=numbers.size()-1;
        vector <int> ans;
        while(rear > front){
            int total = numbers[rear] + numbers[front];
            if (total == target){
                ans.push_back(front+1);
                ans.push_back(rear+1);
                return ans;
            }else if (total < target){
                front++;
            }else if (total > target){
                rear--;
            }
        }
    }
};
