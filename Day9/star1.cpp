#include <bits/stdc++.h>

struct Pos{
    int x;
    int y;
    void operator+=(const Pos&b){
        x+=b.x;
        y+=b.y;
    }
};

bool isTailInRange(Pos t,Pos h){    
    return (std::abs(t.x - h.x) <= 1) && (std::abs(t.y - h.y) <= 1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::vector<int>> odwiedzone(1000,std::vector<int>(1000,0));


    char dir;
    int fields;
    Pos h{500,500},t{500,500};
    odwiedzone[t.y][t.x] = 1;
    std::map<char,Pos> moves{
        {'R',{1,0}},
        {'L',{-1,0}},
        {'U',{0,-1}},
        {'D',{0,1}}
    };
    while(std::cin>>dir>>fields){
        while(fields--){
            Pos temp = h;
            h += moves[dir];
            if(!isTailInRange(t,h)){
                t = temp;
                odwiedzone[t.y][t.x] = 1;
            }
        }
    }
    int sum{0};
    for(auto &row : odwiedzone){
        for(auto &odw: row){
            sum+=odw;
        }
    }
    std::cout<<sum;

    std::cout.flush();  
    return 0;
}