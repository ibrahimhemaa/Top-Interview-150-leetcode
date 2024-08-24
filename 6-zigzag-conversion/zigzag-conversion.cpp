class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>s1(numRows);
        int i=0,add=1;
        if(numRows==1)return s;
        for(auto &j:s){
            s1[i].push_back(j);
            if(i==numRows-1 || (i==0 &&!~add))add*=-1;
            i+=add;
            
        }
        s.clear();
        for(auto &i:s1)s+=i;
        return s;
    }
};