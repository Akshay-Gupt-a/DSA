class Solution {
public:
    int findMax(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0 ){
            return nums[idx];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        
       int  pick=nums[idx]+findMax(nums,idx-2,dp);;
        int notPick ;
        // if(idx-1>=0){
            notPick =findMax(nums,idx-1,dp);
        // }
        
        dp[idx]=max(pick,notPick);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n+1,-1);
        // int first=findMax(nums,n-1,dp);
        // int second = findMax(nums,n-2,dp);
        return findMax(nums,n-1,dp);
        
    }
};