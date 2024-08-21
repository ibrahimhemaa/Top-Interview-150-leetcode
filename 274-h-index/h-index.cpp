class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int>freq(1001);
        for(auto &i:citations){freq[i]++;}
        int mx=0;
        for(int i=999;i>=0;i--){
            freq[i]+=freq[i+1];
            if(freq[i]>=i){mx=i;break;}
        }
        return mx;
        
        
    }
};