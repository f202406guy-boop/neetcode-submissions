
class Solution {
public:
    bool dfs(int x,int y,string s, vector<vector<char>> &board,int idx,vector<vector<bool>> &visit)
    {
       if(x>=board.size()||x<0||y<0||y>=board[0].size()) return false;
       if(board[x][y]!=s[idx]) return false ;
       if(visit[x][y]==true) return false;
       if(idx==s.length()-1) return true;
       if(board[x][y]==s[idx]) idx++;
       visit[x][y]=true;
       bool ans=dfs(x+1,y,s,board,idx,visit)||
       dfs(x-1,y,s,board,idx,visit)||
       dfs(x,y+1,s,board,idx,visit)||
       dfs(x,y-1,s,board,idx,visit);
       visit[x][y]=false;
       return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        bool ans=false;
        vector<vector<bool>> visit(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
           for(int j=0;j<col;j++)
           {
               ans=ans||dfs(i,j,word,board,0,visit);
               if(ans==true ) break;
           }
           if(ans==true) break;

        }
        return ans ;
    }
};
 
