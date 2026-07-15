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
        int notPick =findMax(nums,idx-1,dp);
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
        vector<int>withFirst;
        vector<int>withLast;
        for(int i = 0;i<n;i++){
            if(i!=0) withLast.push_back(nums[i]);
            if(i!=n-1) withFirst.push_back(nums[i]);
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(findMax(withFirst,n-2,dp1),findMax(withLast,n-2,dp2));
        
    }
};