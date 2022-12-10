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
Pos operator/(const Pos&a,int b){
    return {a.x/b,a.y/b};
}
Pos operator*(const Pos&a,int b){
    return {a.x*b,a.y*b};
}
std::ostream& operator<<(std::ostream& os, const Pos& p)
{
    os <<"x: "<<p.x<<", y: "<<p.y;
    return os;
}

const int BOARD_WIDTH{1000};
const int BOARD_HEIGHT{1000};
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
    std::vector<Pos> last_move(10,pzero);
    odwiedzone[INITIAL_POS.y][INITIAL_POS.x] = 1;
    while(std::cin>>dir>>fields){
        while(fields--){
            tail[0] += moves[dir]; 
            // last_move[0] = moves[dir];
            for(int i = 0;i< tail.size()-1;i++){
                if(!isTailInRange(tail[i+1],tail[i])){
                    Pos dif = tail[i] - tail[i+1];
                    if(dif.x == 0 || dif.y == 0){
                        tail[i+1] += dif/2;
                    }else{
                        // std::cout<<"tail["<<i<<"]: "<<tail[i]<<"\n";
                        // std::cout<<"tail["<<i+1<<"]: "<<tail[i+1]<<"\n";
                        // std::cout<<"dif: "<<dif<<"\n";
                        // std::cout<<"dif/2: "<<dif/2<<"\n";
                        tail[i+1] = tail[i] - (dif/2);
                    }

                }
            }
            odwiedzone[tail[9].y][tail[9].x] = 1;
        }
        // printBoard(tail);
        // std::cout<<"\n";
    }
    // printVisited(odwiedzone);
    // return 0;
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