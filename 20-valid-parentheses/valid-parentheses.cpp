class Solution {
public:
    bool isValid(string s) {
        stack<char>c;
        map<char,int>mp;
        mp['(']=')';
        mp['[']=']';
        mp['{']='}';
        for(auto i:s){
            if(c.empty() || mp[c.top()]!=i)c.push(i);
            else c.pop();
        }
        return c.size()==0;
    }
};