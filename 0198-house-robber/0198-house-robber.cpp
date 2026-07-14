class Solution {
public:
    int findMax(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0 || idx==1){
            return nums[idx];
        }
        if(dp[idx]!=-1) return dp[idx];
        int result = INT_MIN;
        for(int i = 2; (idx-i)>=0  ;i++){
            int value = findMax(nums,idx-i,dp)+nums[idx];
            result= max(value,result);
        }
        dp[idx]=result;
        return result;
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
        int first=findMax(nums,n-1,dp);
        int second = findMax(nums,n-2,dp);
        return max(first,second);
    }
};