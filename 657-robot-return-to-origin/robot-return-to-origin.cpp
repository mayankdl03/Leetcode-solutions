class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> position(2,0);
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                position[1]+=1;
            }else if(moves[i]=='D'){
                position[1]-=1;
            }else if(moves[i]=='L'){
                position[0]-=1;
            }else if(moves[i] == 'R'){
                position[0]+=1;
            }
        }
        if(position[0]==0&&position[1]==0){
            return true;
        }
        return false;
    }
};