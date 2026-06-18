class Solution {
public: 

//   bool check(int n , vector<string>&Board, int i , int j){
//     //Upper left dign, koi bhi queen present nai 
//     int row = i , col = j ; 
//     while(row>-1 && col>-1)
//     {
//         if(Board[row][col] == 'Q') return 0; 
//         row--, col--; 
//     }
//     //Upper right dign
//     row = i , col = j; 
//     while(row>-1 && col<n) {
//       if(Board[row][col] == 'Q') return 0 ; 
//       row--, col++; 
//     }
//     return 1; 

//   }
  //Board
//   Q . . . 
//   . . . Q 
//   Q . . . 
//   . . Q .

   void find(int row, int n , vector<vector<string>>&ans, vector<string>&Board, vector<bool>&column, vector<bool>&LeftDig, vector<bool>&RightDig){

    // Base condition 
    if(row == n){
        ans.push_back(Board); 
        return; 
    }
    //Left Dig: n+1+col-row
    //Right Dig: row+col
    //PUt queen at any n position 
    for(int j =0; j<n; j++){
        if(column[j]== 0 && LeftDig[n-1+j-row]==0&& RightDig[row+j] ==0){
            column[j] = 1;
            Board[row][j] ='Q'; 
            LeftDig[n-1+j-row] = 1; 
            RightDig[row+j]= 1; 
            find(row+1, n , ans, Board, column, LeftDig, RightDig);
            column[j] = 0;
             Board[row][j] ='.';  
             LeftDig[n-1+j-row] = 0; 
            RightDig[row+j]= 0;

        }
    }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans; 
        vector<string>Board(n); 
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                Board[i].push_back('.'); 
            }
        }
        vector<bool>LeftDig(2*n-1, 0); 
        vector<bool>RightDig(2*n-1, 0); 
            vector<bool>column(n,0); 

            find(0, n, ans, Board, column , LeftDig, RightDig); 
            return ans; 
        }
    
};