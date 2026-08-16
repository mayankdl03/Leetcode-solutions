class Solution {
public:
    string reversePrefix(string s, int k) {
        int low=0,high=k-1;
        while(low<high){
            int temp=s[low];
            s[low]=s[high];
            s[high]=temp;
            low++;
            high--;
            
        }
        return s;

    }
};