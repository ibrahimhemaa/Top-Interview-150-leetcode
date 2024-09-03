class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<vector<int>>freq1,freq2;
        map<string,vector<int>>mp1,mp2;
        for(int i=0;i<pattern.size();i++)mp1[to_string(pattern[i])].push_back(i);
        int cnt=0;
        string s2;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')s2+=s[i];
            if((i+1==s.size() || s[i]==' ') && s2.size()>0){
                mp2[s2].push_back(cnt++);
                s2.clear();
            }
           
        }
        for(auto &[x,y]:mp1)freq1.push_back(y);
        for(auto &[x,y]:mp2)freq2.push_back(y);
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};