class Solution {
public:
    string largestOddNumber(string num) {
        int end=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                end=i;
                break;
            }           
        }
        int i=0;
        while(i<end && num[i]=='0')i++;
        string result=num.substr(i,end-i+1);
        return result;
    }
};