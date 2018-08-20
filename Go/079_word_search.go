func dfs(row, col, sindex int, word string, flag [][]int, board [][]byte) bool{
    if sindex == len(word) {
        return true
    }  
    if row < 0 || row >= len(board) || col < 0 || col >= len(board[0]) {
        return false 
    }
    if flag[row][col] == 1 || board[row][col] != word[sindex] {
        return false 
    } 
    flag[row][col] = 1 
    if  dfs(row+1,col,sindex+1,word,flag,board) || 
        dfs(row-1,col,sindex+1,word,flag,board) ||
        dfs(row,col-1,sindex+1,word,flag,board) ||
        dfs(row,col+1,sindex+1,word,flag,board) {
        return true
    }
    flag[row][col] = 0 
    return false 
}

// flag 用来标记某个格子是否已经被占 
func exist(board [][]byte, word string) bool {
    if len(word) == 0 {
        return true 
    }
    if len(board) == 0 || len(board[0]) == 0 {
        return false 
    } 
    len1 := len(board)
    len2 := len(board[0]) 
    var flag [][]int 
    for i := 0 ; i < len1 ; i++ {
        tmp := make([]int,len2) 
        flag = append(flag,tmp)
    }
    for i := 0 ; i < len1 ; i++ {
        for j := 0 ; j < len2 ; j++ {
            if ( dfs(i,j,0,word,flag,board) ) {
                return true 
            }
        }
    }
    return false
} 