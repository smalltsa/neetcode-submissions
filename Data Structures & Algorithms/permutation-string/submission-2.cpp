class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }

        vector<int> target(26,0);
        vector<int> window(26,0);
        int windowSize = s1.size();
        for (char c : s1){
            target[c - 'a']++;
        }
        for (int i = 0 ; i < windowSize; i++){
            window[s2[i]-'a']++;
        }
        if (target == window){
            return true;
        }
        for(int rear = windowSize;rear < s2.size(); rear++){
            int front = rear - windowSize;

            window[s2[front]-'a']--;
            window[s2[rear] -'a']++;
            if(target==window){
                return true;
            }
        }
        return false;
    }
};
