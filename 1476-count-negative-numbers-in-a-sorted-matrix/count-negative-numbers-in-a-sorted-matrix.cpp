class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count_negative=0;
        for(auto &g:grid)for(auto &i:g)count_negative+=i<0;
        return count_negative;
    }
};