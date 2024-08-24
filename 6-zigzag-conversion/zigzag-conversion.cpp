class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>s1(numRows);
        int i=0;
        if(numRows==1)return s;
        for(auto &j:s){
            s1[i].push_back(j);
            if(s1[0].size()>s1[numRows-1].size())i++;
            else i--;
        }
        s.clear();
        for(auto &i:s1)s+=i;
        return s;
    }
};