function solution(rows, columns, queries) {
    const answer = [];
    const board = []
    for (let r=0; r<rows; r++){
        var lines = []
        for (let c=0; c<columns; c++){
            lines.push(r*columns + c+1)
        }
        board.push(lines)
    }
    queries.forEach(([y1, x1, y2, x2]) => {
        y1-=1, x1-=1, y2-=1, x2-=1;
        var prev = board[y1][x1];
        var result = 100000001;
        var tmp;

        for (let x=x1+1; x <= x2; x++){
            tmp = board[y1][x]
            board[y1][x] = prev
            prev = tmp
            result = Math.min(result, prev)
        }
        for (let y=y1+1; y <= y2; y++){
            tmp = board[y][x2]
            board[y][x2] = prev
            prev = tmp
            result = Math.min(result, prev)
        }
        for (let x=x2-1; x >= x1; x--){
            tmp = board[y2][x];
            board[y2][x] = prev;
            prev = tmp
            result = Math.min(result, prev)
        }
        for (let y=y2-1; y >= y1; y--){
            tmp = board[y][x1]    
            board[y][x1] = prev;
            prev = tmp
            result = Math.min(result, prev)  
        }
        answer.push(result)
    })
    return answer;
}
