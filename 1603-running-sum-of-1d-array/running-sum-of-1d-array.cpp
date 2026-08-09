class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum=nums[0];
        result.push_back(sum);
        for(int i=1;i<nums.size();i++){
            result.push_back(sum+nums[i]);
            sum+=nums[i];
        }
        return result;
    }
};