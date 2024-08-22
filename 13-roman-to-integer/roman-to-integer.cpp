class Solution {
public:
    int romanToInt(string s) {
        string c[]={"I", "V", "X", "L", "C", "D", "M"};
        int cn=1;
        int ok=0;
        map<string,int>mp;
        for(int i=0;i<7;i++){
            if(!ok){
                mp[(c[i])]=cn;
                cn*=5;
            }
            else{
                mp[(c[i])]=cn;
                cn*=2;
            }
            ok=!ok;
        }
        int ans=0;
        for(auto &i:s){string x;x+=i,ans+=mp[x];}
        //IC -=2 IV -=2
        //XL -=20 XC-=20
        //CD CM-=200
        string x="IV";mp[x]=2;x="IX";mp[x]=2;x="XL";mp[x]=20;x="XC";mp[x]=20;x="CD";mp[x]=200;x="CM";mp[x]=200;
        for(int i=0;i<s.size()-1;i++){
            x="";x+=s[i];x+=s[i+1];
            ans-=mp[x];   
        }
        return ans;
    }
};