#include <bits/stdc++.h>
typedef std::vector<std::vector<int>> matrix;
typedef std::vector<int> row;

struct Pos{
    int x;
    int y;
    void operator+=(const Pos&b){
        x+=b.x;
        y+=b.y;
    }
};
Pos operator+(const Pos&a,const Pos&b ){
    return {a.x+b.x,a.y+b.y};
}
Pos operator-(const Pos&a,const Pos&b ){
    return {a.x-b.x,a.y-b.y};
}
bool operator==(const Pos&a,const Pos&b ){
    return (a.x == b.x) && (a.y ==b.y);
}

const int BOARD_WIDTH{50};
const int BOARD_HEIGHT{50};
const Pos INITIAL_POS{BOARD_WIDTH/2,BOARD_HEIGHT/2};

bool isTailInRange(Pos t,Pos h){    
    return (std::abs(t.x - h.x) <= 1) && (std::abs(t.y - h.y) <= 1);
}
void printBoard(std::vector<Pos> tail){
    matrix board(BOARD_HEIGHT,row(BOARD_WIDTH,0));
    for(int i = tail.size()-1; i >= 0;i--){
        Pos c = tail[i];
        if(i==0){
            board[c.y][c.x] = 69;
            continue;
        }
        board[c.y][c.x] = i;
    }
    for(auto &r : board){
        for(auto &odw: r){
            std::cout<<(odw == 0 ? '.' : (odw == 69 ? 'H' : (char)(odw+48)));
        }
        std::cout<<"\n";
    }

}
void printVisited(matrix visited){
    for(auto &r : visited){
        for(auto &odw: r){
            std::cout<<(odw == 1 ? "#" : ".");
        }
        std::cout<<"\n";
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    matrix odwiedzone(BOARD_HEIGHT,row(BOARD_WIDTH,0));


    char dir;
    int fields;
    Pos pzero{0,0};
    std::map<char,Pos> moves{
        {'R',{1,0}},
        {'L',{-1,0}},
        {'U',{0,-1}},
        {'D',{0,1}}
    };
    std::vector<Pos> tail(10,INITIAL_POS);
    std::vector<Pos> temp(10);
    odwiedzone[INITIAL_POS.y][INITIAL_POS.x] = 1;
    while(std::cin>>dir>>fields){
        while(fields--){
            temp[0] = tail[0];
            tail[0] += moves[dir]; 
            Pos m = temp[0] - tail[1];
            for(int i = 0;i< tail.size()-1;i++){
                temp[i+1] = tail[i+1];
                if(!isTailInRange(tail[i+1],tail[i])){
                    Pos dif = (tail[i] - temp[i]);
                    tail[i+1] = temp[i] + (moves[dir] == dif ? pzero : moves[dir]);
                }
            }
            odwiedzone[tail[9].y][tail[9].x] = 1;
        }
        printBoard(tail);
        std::cout<<"\n";
    }
    // printVisited(odwiedzone);
    return 0;
    int sum{0};
    for(auto &r : odwiedzone){
        for(auto &odw: r){
            sum+=odw;
        }
    }
    std::cout<<sum;

    std::cout.flush();  
    return 0;
}