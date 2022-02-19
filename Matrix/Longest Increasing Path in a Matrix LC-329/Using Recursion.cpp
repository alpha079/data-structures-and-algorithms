int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };   // all the moves available to us - top, down, left, right
int longestIncreasingPath(vector<vector<int>>& matrix) {
	int maxPath = 1; // atleast one cell can always be selected in the path
	// explore each cell of matrix to find longest path achievable from that cell and finally return the maximum
	for(int i = 0; i < size(matrix); i++)
		for(int j = 0; j < size(matrix[0]); j++)
			maxPath = max(maxPath, solve(matrix, i, j));		        
	return maxPath;
}
// recursive solver for each cell 
int solve(vector<vector<int>>& mat, int i, int j){
	int MAX = 1;  // max length of path starting from cell i,j of matrix
	// choosing all the 4 moves available for current cell
	for(int k = 0; k < 4; k++){
		int new_i = i + moves[k][0], new_j = j + moves[k][1];
		// bound checking as well as move to next cell only when it is greater in value
		if(new_i < 0 || new_j < 0 || new_i >= size(mat) || new_j >= size(mat[0]) || mat[new_i][new_j] <= mat[i][j]) continue;
		// MAX will be updated each time to store maximum of path length from each move
		MAX = max(MAX, 1 + solve(mat, new_i, new_j));
	}         
	return MAX;
}
//Time Complexity : O((N*M)*4^(N*M)). We are calculating longest path for each cell and for each cell we are invoking 4 additional functions. All those invoked functions may further call 4 additional functions and this may continue maximum of N*M times taking the overall time complexity to O((N*M)*4^(N*M)).
//We can see that 4 further functions are invoked only the first time solve is called and each subsequent time we only make 3 additional calls at max. So we can put O((N*M)*3^(N*M)) as a more tighter upper bound of the given solution.
//Space Complexity : O(N*M), maximum recursive stack depth for a cell can be O(N*M) when maximum path is N*M.
