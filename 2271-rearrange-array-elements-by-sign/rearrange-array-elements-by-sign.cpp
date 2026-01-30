class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positive_index = 0;
        int negative_index = 1;
        
   
        vector<int> result(n); 
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                result[positive_index] = nums[i];
                positive_index += 2;
            }
            else{
                result[negative_index] = nums[i];
                negative_index += 2;
            }
        }
        return result; 
    }
};