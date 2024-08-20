class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>n2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        reverse(nums1.begin(),nums1.end());
        reverse(nums2.begin(),nums2.end());
       for(int i=0;i<nums1.size()&&n2.size()<m;i++){
            if(nums1[i]==0)continue;
            n2.push_back(nums1[i]);
       }
       while(n2.size()<m)n2.push_back(0);
       for(int i=0;i<nums2.size()&&n2.size()<m+n;i++){
            if(nums2[i]==0)continue;
            n2.push_back(nums2[i]);
       }
       while(n2.size()<m+n)n2.push_back(0);
        sort(n2.begin(),n2.end());
        nums1=n2;
    }
};