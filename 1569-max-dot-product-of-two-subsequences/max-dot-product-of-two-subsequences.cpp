class Solution {
public:
    vector<vector<int>>dp;
    int sol(int index1,int index2,int &n,int &m,vector<int>& nums1, vector<int>& nums2){
        if(index1==n||index2==m)return 0;
        int &ret=dp[index1][index2];
        if(~ret)return ret;
        ret=sol(index1+1,index2+1,n,m,nums1,nums2);
        ret=max(ret,sol(index1+1,index2,n,m,nums1,nums2));
        ret=max(ret,sol(index1,index2+1,n,m,nums1,nums2));
        //take
        ret=max(ret,nums1[index1]*nums2[index2]+sol(index1+1,index2+1,n,m,nums1,nums2));
        return ret;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        dp.resize(n,vector<int>(m,-1));
        int mx= sol(0,0,n,m,nums1,nums2);
        if(mx==0){
            for(int num:nums1){
                if(!num)return 0;
            }
            for(int num:nums2){
                if(!num)return 0;
            }
            if(nums1[0]>0)return *max_element(nums2.begin(),nums2.end())*(*min_element(nums1.begin(),nums1.end()));
            else return *max_element(nums1.begin(),nums1.end())*(*min_element(nums2.begin(),nums2.end()));
        }
        return mx;
    }
};