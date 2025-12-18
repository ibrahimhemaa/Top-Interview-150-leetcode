class Solution {
public:
    string longestPalindrome(string s) {
        map<int,vector<int>>Char_Index;
        for(int i=0;i<s.size();i++){
            Char_Index[s[i]-'a'].push_back(i);
        }
        int longpalindrome=1;//one char;
        int mnl=0;
        for(int i=0;i<s.size();i++){
            int last_char=Char_Index[s[i]-'a'].back(),index=Char_Index[s[i]-'a'].size()-1;
            if(last_char-i+1<=longpalindrome)continue;
            while(1){
                int l=i+1,r=last_char-1;
                while(l<=r && s[l]==s[r])++l,--r;
                if(l>r){
                    longpalindrome=last_char-i+1;
                    mnl=i;
                    break;
                }
                last_char=Char_Index[s[i]-'a'][index-1];
                if(last_char-i+1<=longpalindrome)break;
                --index;
            }
        }
        return s.substr(mnl,longpalindrome);
    }
};