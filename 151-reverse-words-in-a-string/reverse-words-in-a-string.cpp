class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> result;
        string ans="";
        while(ss>>word){
            result.push_back(word);
        }
        int n=result.size();
        for(int i=n-1;i>=0;i--){
            ans+=result[i];
            ans+=" ";
        }
        if(!ans.empty())ans.pop_back();
   
        return ans;
    }
};