class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' ')s.pop_back();
        int cnt=0;
        while(s.size()>0&&s.back()!=' ')cnt++,s.pop_back();
        return cnt;
    }
};