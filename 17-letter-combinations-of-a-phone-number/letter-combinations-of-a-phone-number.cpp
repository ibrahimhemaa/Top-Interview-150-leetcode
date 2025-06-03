class Solution {
public:
    vector<string>s={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(string digits,vector<string>&ans,string ss="",int i=0){
        if(i==digits.size()){
            ans.push_back(ss);
            return;
        }
        int x=digits[i]-'0';
        x-=2;
        string digit=s[x];
        for(int j=0;j<digit.size();j++){
            ss+=digit[j];
            backtrack(digits,ans,ss,i+1);
            ss.pop_back();
        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return {};
        vector<string>ans;
        backtrack(digits,ans);
        return ans;
    }
};