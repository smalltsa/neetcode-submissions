class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector <int> st;
        heights.push_back(0);

        for (int i = 0 ;i < heights.size();i++){
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int h = heights[st.back()];
                st.pop_back();
                int w = st.empty() ? i : (i - st.back() - 1);

                maxArea = max(maxArea,h*w);
            }
            st.push_back(i);
        }

        return maxArea;
    }
};
