class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =  0;
        int maxi = INT_MIN;
        int start = 0;
        int ans_start = -1;
        int ans_end = -1;

        for(int i = 0;i<nums.size();i++){
            if(sum ==0) start = i;
            sum += nums[i];

            if(sum>maxi){
                maxi = sum;
                ans_start = start;
                ans_end = i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};