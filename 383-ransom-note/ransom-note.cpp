class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int l=0,r=0;
        while(l<ransomNote.size() && r<magazine.size()){
            if(ransomNote[l]==magazine[r])l++,r++;
            else r++;
        }
        return l==ransomNote.size();
    }
};