class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int candi1=0;
        int candi2 =0;
        for(int i = 0;i<nums.size();i++){
            if(count1 == 0 && nums[i] !=candi2){
                count1 = 1;
                candi1 = nums[i];
            }
            else if(count2==0 && nums[i] !=candi1){
                count2 = 1;
                candi2 = nums[i];
            }
            else if(candi1 == nums[i]){
                count1++;
            }
            else if(candi2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int threshold = nums.size()/3;

        count1 = 0, count2 = 0;
         for(int i = 0;i<nums.size();i++){
            if(candi1 == nums[i]){
                count1++;
            }
            else if(candi2 == nums[i]){
                count2++;
            }
         }

         if(count1>threshold){
            result.push_back(candi1);
         }
         if(count2>threshold){
            result.push_back(candi2);
         }
         return result;
    }
};