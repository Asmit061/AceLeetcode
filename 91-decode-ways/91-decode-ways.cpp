class Solution {
public:
    vector<int> dp;
    int recur(vector<int>& v,int i,int &n,int &a){
        if(v[i]==0)
            return 0;
        if(i+1==n)
            return 1;
        a= v[i]*10+v[i+1];
        if(i+2==n&&a>0&&a<=26){
            if(v[i+1]==0)
                return 1;
            else
                return 2;
        }
        if(dp[i]!=-1)
            return dp[i];
        if(a>0&&a<=26)
            dp[i]= recur(v,i+1,n,a)+recur(v,i+2,n,a);
        else
            dp[i]= recur(v,i+1,n,a);
        return dp[i];
    }
    int numDecodings(string s) {
        vector<int> v(s.begin(),s.end());
        dp.resize(s.size()+1,-1);
        for(int i=0;i<v.size();i++){
            v[i]=v[i]-'0';
        }
        int n=v.size();
        int a=0;
        return recur(v,0,n,a);
    }
};