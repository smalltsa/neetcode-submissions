class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector <pair<int,int>> cars(n);
        for (int i  = 0;i < n ; i++) {
            cars[i] = {position[i],speed[i]};
        }
        sort(cars.rbegin(),cars.rend());

        vector<double> st;
        for (auto& car : cars) {
            double time =(double) (target - car.first) / car.second;
            if (st.empty() || time > st.back()){
                st.push_back(time);
            }
        }
        return st.size();
    }
};
