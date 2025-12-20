class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int number_of_Column=0;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i]){
                    ++number_of_Column;break;
                }
            }
        }
        return number_of_Column;
    }
};