class Solution {
public:
    
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        int first = 1;
        int second = 1;
        int curr = 0 ;
        for(int i= 2;i<=n;i++){
            curr = first + second;
            first = second;
            second = curr;
        }
        return curr;
    }
};