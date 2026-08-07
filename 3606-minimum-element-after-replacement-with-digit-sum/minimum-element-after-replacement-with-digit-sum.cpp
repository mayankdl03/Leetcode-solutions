class Solution {
public:
    int minElement(vector<int>& nums) {
        int minimum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            string digit=to_string(nums[i]);//"10"
            int sum=0;//sum=0
            for(int j=0;j<digit.size();j++){
                sum+=(digit[j]-'0');
            }
            minimum=min(minimum,sum);
            
        }
        return minimum;
    }
};