class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<pair<char,string>>category;
        unordered_map<string,int>includebusinessLine;
        includebusinessLine["electronics"]=1;
        includebusinessLine["grocery"]=1;
        includebusinessLine["pharmacy"]=1;
        includebusinessLine["restaurant"]=1;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(!isActive[i]||includebusinessLine.find(businessLine[i])==includebusinessLine.end() )continue;
            bool validword=1;
            validword&=(code[i].size()>0);
            for(int j=0;j<code[i].size();j++){
                validword&=((code[i][j]>='0'&&code[i][j]<='9')||(code[i][j]>='a'&&code[i][j]<='z')||(code[i][j]>='A'&&code[i][j]<='Z')||(code[i][j]=='_'));
            }
            if(validword){
                category.push_back({businessLine[i][0],code[i]});
            }
        }
        sort(category.begin(),category.end());
        vector<string>Category;
        for(auto &[_,code]:category)Category.push_back(code);
        return Category;
    }
};