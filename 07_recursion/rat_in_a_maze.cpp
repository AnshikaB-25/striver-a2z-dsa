class Solution {
  public:
  void findpath(vector<vector<int>>&maze, vector<string>&ans,string s,int n,int i,int j){
      if(i==n-1&& j==n-1){
          ans.push_back(s);
          return ;
      }
      if(i<0 || j<0 || i>=n || j>=n || maze[i][j]!=1) return; 
      int x = maze[i][j];
      maze[i][j]=-1;
      if(i+1<n && maze[i+1][j]==1){
          s.push_back('D');
          findpath(maze,ans,s,n,i+1,j);
          s.pop_back();
      }
      if(j-1>=0 && maze[i][j-1]==1){
          s.push_back('L');
          findpath(maze,ans,s,n,i,j-1);
          s.pop_back();
      }
      if(j+1<n && maze[i][j+1]==1){
          s.push_back('R');
          findpath(maze,ans,s,n,i,j+1);
          s.pop_back();
      }
      if(i-1>=0 && maze[i-1][j]==1){
          s.push_back('U');
          findpath(maze,ans,s,n,i-1,j);
          s.pop_back();
      }
      maze[i][j]=x;
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
         int n = maze.size();
        if(maze[0][0]==0) return {};
        if(maze[n-1][n-1]==0) return{};
        string s = "";
        findpath(maze,ans,s,n,0,0);
        return ans;

    }
};
