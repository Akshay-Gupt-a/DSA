class Solution {
public:
    int findMin(vector<int>&cost,int idx){
        if(idx==cost.size()){
            return 0;
        }
        if(idx==cost.size()-1){
            return  cost[idx];
        }
       
        if(idx ==-1){
             int first =  findMin(cost,idx+1);
            int second = findMin(cost,idx+2);
            return min(first,second);
        }
       int first =  findMin(cost,idx+1)+cost[idx];
       int second = findMin(cost,idx+2)+cost[idx];
       return min(first,second);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==0){
            return -1;
        }
        // vector<int>dp(-1,n+1);
        int prev1 = 0;
        int prev2=0;
        int curr = 0;
        int first = 0;
        int second = 0;
        for(int i = 0;i<n;i++){
             first= prev1+cost[i];
            second = prev2+cost[i];
            curr = min(first,second);
            prev1=prev2;
            prev2=curr;
        }
        curr = min(prev1,prev2);
        return   curr;

    }
};