class Solution {
public:
    int findTotalWay(int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(m==0 && n==0){
            return 1;
        }
        return dp[m][n]=(findTotalWay(m-1,n,dp)+findTotalWay(m,n-1,dp));

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findTotalWay(m-1,n-1,dp);

        
    }
};