class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>v;
        string s1;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                int j=i;
                while(j<n&&s[j]!=' ')s1+=s[j],j++;
                i=j;
                v.push_back(s1);
                s1.clear();
            }
        }
        reverse(v.begin(),v.end());
        n=v.size();

        for(int i=0;i<n;i++){
            s1+=v[i];
            if(i+1!=n)s1+=" ";
        }
        return s1;
    }
};