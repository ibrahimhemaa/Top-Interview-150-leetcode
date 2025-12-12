class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<pair<pair<int,char>,int>>event;

        for(int i=0;i<events.size();i++){
            event.push_back({{stoi(events[i][1]),events[i][0][2]},i});
        }
        sort(event.begin(),event.end());
        map<int,int>offlinetime;
        vector<int>ans(numberOfUsers,0);
        for(auto &ev:event){
            int time=ev.first.first;
            int index=ev.second;
            if(events[index][0]=="OFFLINE"){
                int userId=stoi(events[index][2]);
                offlinetime[userId]=time+60;

            }
            else{
                map<int,int>users;
                string s="",userIds=events[index][2];
                if(userIds!="HERE"&&userIds!="ALL"){
                    for(char &c:userIds){
                        if(c>='0'&&c<='9')s+=c;
                        else{
                            if(s.size())users[stoi(s)]++;
                            s="";
                        }
                    }
                    if(s.size())users[stoi(s)]++;
                }
                for(int i=0;i<numberOfUsers;i++){
                    if(userIds=="ALL") ans[i]++;
                    else if(userIds=="HERE"){
                         if(offlinetime.find(i)!=offlinetime.end())ans[i]+=(offlinetime[i]<=time);
                         else ans[i]++;
                    }
                    else{
                        ans[i]+=users[i];
                    }
                }
            }
            
        }
        return ans;
        
    }
};