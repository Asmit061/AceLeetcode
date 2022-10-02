class Solution {
public:
    vector<vector<int>> dp;
    int mod=1000000007;
    int rec(int n, int k, int target){
        if(target<=k&&n==1)
            return 1;
        if(target<=0||n<=0)
            return 0;
        if(dp[n][target]!=-1)
                return dp[n][target];
        int count=0;
        for(int i=1;i<target&&i<=k;i++){
            count=(count%mod + rec(n-1,k,target-i)%mod)%mod;
            dp[n][target]=count;
        }
        
        return count;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(31,vector<int> (1001,-1));
        return rec(n,k,target);
    }
};