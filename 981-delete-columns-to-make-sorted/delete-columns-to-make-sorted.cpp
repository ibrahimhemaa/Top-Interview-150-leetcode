class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int number_of_Column=0;
        int n=strs.size(),m=strs[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(strs[j][i]<strs[j-1][i]){
                    ++number_of_Column;break;
                }
            }
        }
        return number_of_Column;
    }
};