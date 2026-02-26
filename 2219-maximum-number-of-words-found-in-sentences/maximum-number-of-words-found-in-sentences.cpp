class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=0;
        int maximum=0;
        for(int i=0;i<sentences.size();i++){
            stringstream ss(sentences[i]);
            string word;
            while(ss>>word){
                count++;
            }
            maximum=max(count,maximum);
            count=0;
        }
        return maximum;
    }
};