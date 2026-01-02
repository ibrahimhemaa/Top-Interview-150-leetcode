class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       unordered_map<int,int>rep;
       for(auto &num:nums){
            if(rep.find(num)!=rep.end()){
                return num;
            }
            rep[num]++;
       } 
       return -1;
    }
};