class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>c;
        int l=0,r=0,ans=0;
        while(r<s.size()){
            c[s[r]]++;
            while(c[s[r]]>1)c[s[l]]--,l++;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};