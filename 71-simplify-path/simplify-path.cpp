class Solution {
public:
    string simplifyPath(string path) {
        string s;
        string dot;
        stack<string>s1;
        for(auto &i:path){
            if(i=='/'){
                if(s.size()==1 && s[0]=='.'){
                    ;
                }
                else if(s.size()==2 && s[0]=='.' && s[1]=='.'){
                    if(s1.size())s1.pop();
                }
                else{
                    if(s.size())s1.push(s);
                }
                s.clear();
            }else{
                s+=i;
            }
        }
        if(s.size()==1 && s[0]=='.'){
            ;
        }
        else if(s.size()==2 && s[0]=='.' && s[1]=='.'){
            if(s1.size())s1.pop();
        }
        else{
            if(s.size())s1.push(s);
        }
        s.clear();
        while(!s1.empty())s='/'+s1.top()+s,s1.pop();
        if(s.size()==0)s+='/';
        return s;
    }
};