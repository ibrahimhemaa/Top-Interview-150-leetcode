class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<array<int,2>>v;
        vector<int>ans(n),vis(n);
        for(int i=0;i<n;i++){
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        int st=1,sum=0;
        for(int i=0;i<n;i++){
            int get1=0,get2=0;
            if(v[i][1]-1>=0){
                if(ratings[v[i][1]-1]<ratings[v[i][1]]){
                    get1=ans[v[i][1]-1]+1;
                }
                else{
                    get1=1;
                }
            }
            if(v[i][1]+1<n){
                if(ratings[v[i][1]+1]<ratings[v[i][1]]){
                    get2=ans[v[i][1]+1]+1;
                }
                else{
                    get2=1;
                }
            }
            ans[v[i][1]]=max({get1,get2,1});
            sum+=ans[v[i][1]];
        }
        return sum;
    }
};