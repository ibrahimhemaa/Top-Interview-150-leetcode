class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>s1(numRows);
        int n=s.size();
        for(int i=0;i<n;i++){
            int j=i;
            //top to botton
            while(j<n&&j-i<numRows){
                s1[j-i].push_back(s[j]);
                j++;
            }
            int j1=j;
            j-=2;
            int cnt=0;
            //zigza,g botton to top
            while(cnt+j1<n &&j>i){
                s1[j-i].push_back(s[j1+cnt]);
                j--;cnt++;
            }
            i=j1+cnt-1;
        }
        s.clear();
        for(auto &i:s1)s+=i;
        return s;
    }
};