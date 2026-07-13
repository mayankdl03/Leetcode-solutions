class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        vector<char> order={'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
        for(int i=0;i<words.size();i++){//i=0,sum=0,j=0,sum=0+weights['a'-words[0][0]],sum=0+5
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                sum+=weights[abs('a'-words[i][j])];
            }
            int modulo=sum%26;
            result+=order[modulo];
        }
        return result;
    }

};
