class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> postive;
        vector<int> negative;
        for(auto it:nums){
            if(it>0){
                postive.push_back(it);
            }
        }
        for(auto it:nums){
            if(it<0){
                negative.push_back(it);
            }
        }
        int i=0;
        for(auto it:postive){
            result[i]=it;
            i+=2;
        }
        int j=1;
        for(auto it:negative){
            result[j]=it;
            j+=2;
        }
        return result;

    }
};