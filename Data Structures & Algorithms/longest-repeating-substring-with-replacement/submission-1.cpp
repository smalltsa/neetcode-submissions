class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;

        int front = 0;
        int maxFreq = 0;
        int answer = 0;

        for(int rear = 0; rear < s.size(); rear++){
            count[s[rear]]++;
            maxFreq = max(maxFreq,count[s[rear]]);

            while((rear - front + 1)-maxFreq > k) {
                count[s[front]]--;
                front++;
            }
            
            answer = max(answer,rear - front +1);
        }
        return answer;
    }
};
