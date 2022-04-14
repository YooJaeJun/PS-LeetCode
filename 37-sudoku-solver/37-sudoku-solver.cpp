#define n 9

class Solution {
public:
    bool row[n+1][n+1] = { false, };
    bool col[n+1][n+1] = { false, };
    bool grid3x3[n+1][n+1] = { false, };
    bool isPrinted = false;
    
    void backTracking(vector<vector<char>>& board, int depth) {
        if(isPrinted) {
            return;
        }
        if (depth == 81) {
            isPrinted = true;
            return;
        }
        
        int x = depth / n;
        int y = depth % n;
        
        if(board[x][y] == '.') {
            for(int num=1;num<=9;num++) {
                if(row[x][num] || col[y][num] || grid3x3[x/3*3 + y/3][num]) continue;
                
                row[x][num] = true;
                col[y][num] = true;
                grid3x3[x/3*3 + y/3][num] = true;
                board[x][y] = num + '0';
                
                backTracking(board, depth + 1);
                if(isPrinted) {
                    return;
                }
                
                board[x][y] = '.';
                row[x][num] = false;
                col[y][num] = false;
                grid3x3[x/3*3 + y/3][num] = false;
            }
        } 
        else {
            backTracking(board, depth + 1);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i!=n;i++) {
            for(int j=0;j!=n;j++) {
                if(board[i][j] != '.') {
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    grid3x3[i/3*3 + j/3][board[i][j] - '0'] = true;
                }
            }
        }
        backTracking(board, 0);
    }
};