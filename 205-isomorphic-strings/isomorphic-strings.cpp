class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<vector<int>>freq1,freq2;
        map<char,vector<int>>mp1,mp2;
        for(int i=0;i<s.size();i++)mp1[s[i]].push_back(i);
        for(int i=0;i<t.size();i++)mp2[t[i]].push_back(i);
        for(auto &[x,y]:mp1)freq1.push_back(y);
        for(auto &[x,y]:mp2)freq2.push_back(y);
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};