class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>v;
        vector<string>c1;
        int cnt=0;
        for(auto &i:words){
            if(cnt+c1.size()+i.size()<=maxWidth){
                cnt+=i.size();
                c1.push_back(i);

            }
            else{
                if(c1.size()==1){
                    while(cnt!=maxWidth){
                        c1.back()+=' ';cnt++;
                    }
                    v.push_back(c1[0]);
                    c1.clear();
                    cnt=i.size();
                    c1.push_back(i);
                }
                else{
                    cnt=maxWidth-cnt;
                    int cn=cnt/(c1.size()-1);
                    int rem=(cnt%(c1.size()-1));
                    string s1;
                    for(int i1=0;i1<c1.size()-1;i1++){
                        s1+=c1[i1];
                        for(int j=0;j<cn;j++)s1+=' ';
                        if(rem)s1+=' ',rem--;
                    }
                    s1+=c1.back();
                    c1.clear();
                    v.push_back(s1);
                    cnt=i.size();
                    c1.push_back(i);
                }
            }
        }
        cnt=maxWidth-cnt-c1.size()+1;
        string s1;
        for(int i1=0;i1<c1.size()-1;i1++){
            s1+=c1[i1];
            s1+=' ';
            
        }    
        while(cnt--)c1.back()+=' ';
        s1+=c1.back();
        v.push_back(s1);
        return v;
    }
};