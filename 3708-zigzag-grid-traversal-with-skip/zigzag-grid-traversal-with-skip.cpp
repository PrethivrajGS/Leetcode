class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<int> ans;
        for(int i=0;i < m ; i++){
            if(i%2){
                for(int j= (n&1)?n-2:n-1 ; j>=0; j-=2){
                    ans.push_back(grid[i][j]);
                }
                
            }else{
                for(int j=0;j<n;j+=2){
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;
    }
};