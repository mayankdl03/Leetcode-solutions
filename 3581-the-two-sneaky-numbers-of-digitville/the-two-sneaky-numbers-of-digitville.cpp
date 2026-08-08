class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto& i:mp){    
            if(i.second>=2){
                result.push_back(i.first);
            }
        }
        return result;
    }
};