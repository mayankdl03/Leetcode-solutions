class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> result;
        for(auto it:nums){
            if(it%2==0){
                result.push_back(0);
            }else{
                result.push_back(1);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};