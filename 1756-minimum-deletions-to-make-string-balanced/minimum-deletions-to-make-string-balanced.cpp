class Solution {
public:
    int minimumDeletions(string s) {
        //ab , bbb, aaa  
        int n=s.size(),mx=0;
        vector<int>cnta(n,0),cntb(n,0);
        for(int i=0;i<n;i++){
            cnta[i]+=s[i]=='a';
            cntb[n-i-1]+=s[n-i-1]=='b';
            if(i){cnta[i]+=cnta[i-1];cntb[n-i-1]+=cntb[n-i];}
        }
        mx=max(cnta[n-1],cntb[0]);
        for(int i=0;i<n-1;i++){
            mx=max(mx,cnta[i]+cntb[i+1]);
        }
        return n-mx;
    }
};