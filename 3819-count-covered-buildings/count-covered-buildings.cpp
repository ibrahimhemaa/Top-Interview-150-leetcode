class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int hight[n+1][2];
        int width[n+1][2];
        if(n<=2||buildings.size()<=4)return 0;
        memset(width,-1,sizeof(width));
        memset(hight,-1,sizeof(hight));
        for(auto &pair:buildings){
            int x=pair[0], y=pair[1];
            if(width[x][0]==-1){
                width[x][0]=y;
                width[x][1]=y;
            }
            else{
                width[x][0]=max(y,width[x][0]);
                width[x][1]=min(y,width[x][1]);
            }
            if(hight[y][0]==-1){
                hight[y][0]=x;
                hight[y][1]=x;
            }
            else{
                hight[y][0]=max(x,hight[y][0]);
                hight[y][1]=min(x,hight[y][1]);
            }
        }
        int ans=0;
        for(auto &pair:buildings){
            int x=pair[0], y=pair[1];
            ans+=(width[x][0]!=y && width[x][1]!=y&&hight[y][0]!=x&&hight[y][1]!=x);
        }
        return ans;
        
    }
};