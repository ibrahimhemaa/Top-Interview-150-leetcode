class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            char c=tolower(s[l]),c1=tolower(s[r]);
            cout<<c<<' '<<c1<<'\n';
            if((c<'a' || c>'z') && (c<'0' || c>'9')){
                l++;
            }
            else if((c1<'a' || c1>'z') && (c1<'0' || c1>'9')){
                r--;
            }
            else{
                if(c1!=c)return false;
                l++,r--;
            }
        }
        return true;
    }
};