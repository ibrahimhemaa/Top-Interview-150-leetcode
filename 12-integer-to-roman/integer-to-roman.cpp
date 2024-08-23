class Solution {
public:
    string intToRoman(int num) {
    string c[]={"I", "V", "X", "L", "C", "D", "M"};
    map<int,string>mp;
    int cn=1;
    int ok=0;
    for(int i=0;i<7;i++){
        if(!ok){
            mp[cn]=c[i];
            cn*=5;
        }
        else{
            mp[cn]=c[i];
            cn*=2;
        }
        ok=!ok;
    }
    mp[4]="IV",mp[9]="IX",mp[40]="XL",mp[90]="XC",mp[400]="CD",mp[900]="CM";
    int x=num%10;
    num-=num%10;
    string s;
    if(mp.find(x)!=mp.end()){
        s=mp[x]+s;
    }
    else{
        if(x<5){
            while(x--)s=mp[1]+s;
        }
        else{
            while(x>5)s=mp[1]+s,x-=1;
            s=mp[5]+s;
        }
    }
    x=num%100;
    num-=num%100;
    if(mp.find(x)!=mp.end()){
        s=mp[x]+s;
    }
    else{
        if(x<50){
            while(x)s=mp[10]+s,x-=10;
        }
        else{
            while(x>50)s=mp[10]+s,x-=10;
            s=mp[50]+s;
        }
    }
    x=num%1000;
    num-=num%1000;
    if(mp.find(x)!=mp.end()){
        s=mp[x]+s;
    }
    else{
        if(x<500){
            while(x)s=mp[100]+s,x-=100;
        }
        else{
            while(x>500)s=mp[100]+s,x-=100;
            s=mp[500]+s;
        }
    }
    x=num/1000;
    while(x--){
        s=mp[1000]+s;
    }
    return s;
}
};