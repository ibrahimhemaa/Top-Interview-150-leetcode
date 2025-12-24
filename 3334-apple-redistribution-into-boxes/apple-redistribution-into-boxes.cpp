class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int numofapple=0;
        for(auto &apples:apple)numofapple+=apples;
        sort(capacity.rbegin(),capacity.rend());
        for(int i=0;i<capacity.size();i++){
            numofapple-=capacity[i];
            if(numofapple<=0)return i+1;
        }
        return -1;
    }
};