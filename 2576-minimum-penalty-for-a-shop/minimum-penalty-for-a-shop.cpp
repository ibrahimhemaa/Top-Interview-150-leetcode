class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int ans=n,No=0;
        vector<int>customercome(n+1,0);
        for(int i=n-1;i>=0;i--){
            customercome[i]=customers[i]=='Y';
            if(i!=n-1)customercome[i]+=customercome[i+1];
        }
        if(customercome[0]==n){
            return n;
        }
        for(int i=0;i<=n;i++){
            //stop
            ans=min(ans,customercome[i]+No);
            if(i!=n)
                No+=customers[i]=='N';
        }
        No=0;
        for(int i=0;i<=n;i++){
            //stop
            if(ans==No+customercome[i]){
                return i;
            }
            if(i!=n)
                No+=customers[i]=='N';
        }
        return 0;
    }
};