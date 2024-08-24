class Solution {
public:
    int strStr(string haystack, string needle) {
         for(int i=0;i<haystack.size();i++){
            if(haystack[i]!=needle[0])continue;
            for(int j=0;j<needle.size();j++){
                if(i+j>=haystack.size() || haystack[i+j]!=needle[j])break;
                if(j+1==needle.size())return i;
            }
         }
         return -1;
    }
};