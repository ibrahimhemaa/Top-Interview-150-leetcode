class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>v;
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(auto &i:nums)mp[i]++;
        vector<int>num;
        for(auto &[x,y]:mp)num.push_back(x);
        cout<<nums.size()<<' '<<mp.size()<<'\n';
        if(mp[0]>2){
            v.insert({0,0,0});
        }
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                int val=-(num[i]+num[j]);
                int cnt=mp[val];
                int target=val;
                cnt-=(num[i]==target);
                cnt-=(num[j]==target);
                if(cnt>0){
                    vector<int>v1={num[i],num[j],val};
                    sort(v1.begin(),v1.end());
                    v.insert(v1);
                }
                
            }
        }
        vector<vector<int>>v2;
        for(auto &i:v)v2.push_back(i);
        return v2;

    }
};