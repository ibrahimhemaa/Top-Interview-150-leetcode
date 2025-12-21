class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int>sorted(strs.size(),0);
        int num_del=0;
        for(int i=0;i<strs[0].size();i++){
            bool del=0;
            for(int j=1;j<strs.size();j++){
              if(strs[j-1][i]>strs[j][i] && !sorted[j]){
                del=1;break;
              }
            }
            if(del){++num_del;continue;}
            for(int j=1;j<strs.size();j++){
                if(!sorted[j])sorted[j] = (strs[j-1][i]<strs[j][i]);
            }
        }
        return num_del;
    }
};