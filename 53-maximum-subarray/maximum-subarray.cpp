class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum=nums[0];
        int maximum_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            current_sum=max(nums[i],current_sum+nums[i]);
            maximum_sum=max(current_sum,maximum_sum);
        }
        return maximum_sum;
    }
};