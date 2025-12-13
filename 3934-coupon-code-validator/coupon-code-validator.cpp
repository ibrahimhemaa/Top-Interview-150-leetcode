class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        map<char,int>businessHash;
        businessHash['e']=1;
        businessHash['g']=2;
        businessHash['p']=3;
        businessHash['r']=4;
        vector<pair<int,string>>category;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(!isActive[i]||(businessLine[i]!="electronics"&&businessLine[i]!="grocery"&&businessLine[i]!="pharmacy"&&businessLine[i]!="restaurant") )continue;
            bool validword=1;
            validword&=(code[i].size()>0);
            for(int j=0;j<code[i].size();j++){
                validword&=((code[i][j]>='0'&&code[i][j]<='9')||(code[i][j]>='a'&&code[i][j]<='z')||(code[i][j]>='A'&&code[i][j]<='Z')||(code[i][j]=='_'));
            }
            if(validword){
                category.push_back({businessHash[businessLine[i][0]],code[i]});
            }
        }
        sort(category.begin(),category.end());
        vector<string>Category;
        for(auto &[hash,code]:category)Category.push_back(code);
        return Category;
    }
};