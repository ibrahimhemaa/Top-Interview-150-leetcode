class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int num:nums){
            if(num==2)ans.push_back(-1);
            else{
                bool flag=0;
                for(int i=9;i>=0;i--){
                    if((1<<i)&num){
                        int n=1<<i;
                        if(((num-n)|(num+1-n))==num){
                            ans.push_back(num-n);
                            flag=1;
                            break;
                        }
                    }
                }
                if(!flag){
                    if((num-1)|num==num)ans.push_back(num-1);
                    else ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};