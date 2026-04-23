class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1;
        vector<int> result;
        int first=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                first=mid;
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        int lefty=0,righty=n-1;
        int second=-1;
        while(lefty<=righty){
            int mid=lefty+(righty-lefty)/2;
            if(nums[mid]==target){
                second=mid;
                lefty=mid+1;
            }else if(nums[mid]<target){
                lefty=mid+1;
            }else{
                righty=mid-1;
            }
        }
        result.push_back(first);
        result.push_back(second);
        return result;
    }
};