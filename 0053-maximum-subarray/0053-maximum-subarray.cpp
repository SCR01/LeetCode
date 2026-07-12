class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int start = -1, end = -1;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum==0) start=i;
            if(sum>maxi){
                maxi = sum;
                start = start;
                end = i;
            }
            if(sum<0){
                sum = 0;
            }
            
        }
        return maxi;
    }
};