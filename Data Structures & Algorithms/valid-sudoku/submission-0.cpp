class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {



        for(int i=0;i<9;i++){
            set<int> st;
            for(int j=0;j<9;j++){
                if( st.find(board[i][j])!=st.end()){
                            return false;
                        }
                        else {
                             if(board[i][j]!='.')
                            st.insert(board[i][j]);
                        }
            }
        }

          for(int i=0;i<9;i++){
            set<int> st;
            for(int j=0;j<9;j++){
                if(st.find(board[j][i])!=st.end()){
                            return false;
                        }
                        else {
                             if(board[j][i]!='.')
                            st.insert(board[j][i]);
                        }
            }
        }

        for(int i=0;i<8;i+=3){
            for(int j=0;j<8;j+=3){
                set<int> st;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(st.find(board[k][l])!=st.end()){
                            return false;
                        }
                        else {
                            if(board[k][l]!='.')
                            st.insert(board[k][l]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
