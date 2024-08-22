class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0,subtot=0,ind=0;
        for(int i=0;i<gas.size();i++){
            tot+=(gas[i]-cost[i]);
            subtot+=(gas[i]-cost[i]);
            if(subtot<0)subtot=0,ind=i+1;
        }
        return (tot>=0?ind:-1);
    }
};