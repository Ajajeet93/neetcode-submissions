class Solution {
    bool horizontal(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            unordered_set<char> st;
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
         return true;
    }
    bool vertical(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            unordered_set<char> st;
            for(int j=0;j<board.size();j++){
                if(board[j][i]=='.') continue;
                if(st.count(board[j][i])) return false;
                st.insert(board[j][i]);
            }
        }
         return true;
    }
    bool square(vector<vector<char>>& board){
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board.size();j+=3){
                unordered_set<char> st;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.') continue;
                        if(st.count(board[k][l])) return false;
                        st.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return horizontal(board) && vertical(board) && square(board);
    }
};
