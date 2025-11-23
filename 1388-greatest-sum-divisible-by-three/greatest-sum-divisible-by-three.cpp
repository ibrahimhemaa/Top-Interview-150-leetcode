class Solution {
public:
    vector<int>dp,num;
    int mx=0;
    int solve(int ind,int sum){
        if(ind>=num.size()){
            if(sum%3==0)mx=max(mx,sum);
            return mx;
        }
        int &ret=dp[ind];
        // if(~ret)return ret;
        if(num[ind]%3==0){
            ret=solve(ind+1,sum+num[ind]);
        }
        else 
            ret=max(solve(ind+1,sum+num[ind]),solve(ind+1,sum));
        return ret;
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        priority_queue<int>mn1,mn2;
        for(auto &i:nums){
            sum+=i;
            if((i%3)==1){
                mn1.push(i);
            }
            else if((i%3)==2){
                mn2.push(i);
            
            }
        }
        int rem1=mn1.size()%3;
        int rem2=mn2.size()%3;
        if(rem1==0){
            if(mn1.size()>=3)rem1=3;
        }
        if(rem2==0){
            if(mn2.size()>=3)rem2=3;   
        }
        if(mn1.size()>=rem1+3)rem1+=3;
        if(mn2.size()>=rem2+3)rem2+=3;
        while(mn1.size()>rem1)mn1.pop();
        while(mn2.size()>rem2)mn2.pop();
        while(mn1.size()){sum-=mn1.top();num.push_back(mn1.top());mn1.pop();}
        while(mn2.size()){sum-=mn2.top();
        num.push_back(mn2.top());
        mn2.pop();}
        dp.resize(num.size()+1,-1);
        return sum+solve(0,0);
    }
};