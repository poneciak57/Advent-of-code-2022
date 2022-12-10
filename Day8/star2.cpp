#include <bits/stdc++.h>

std::string inp;
std::vector<std::vector<int>> tab;
struct Pos
{
    int x;
    int y;
    void operator+=(const Pos&b){
        x+=b.x;
        y+=b.y;
    }
};
const inline bool isInBounds(const Pos& p){
    return p.x >= 0 && p.x < tab.size() && p.y >= 0 && p.y < tab[0].size();
}
std::vector<Pos> dirs{{-1,0},{1,0},{0,-1},{0,1}};

int getScore(int x,int y){
    int score{1};
    int tx,ty;
    int cur = tab[x][y];
    for(Pos &p : dirs){
        Pos tp{x,y};
        int c{1};
        tp +=  p;
        while (isInBounds(tp) && tab[tp.x][tp.y]<cur){
            c++;
            tp+=p;
        }
        score*=c - !isInBounds(tp);
    }
    return score;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while(std::cin>>inp){
        std::vector<int> temp;
        for(char &c: inp){
            temp.push_back(c-48);
        }
        tab.push_back(temp);
    }

    int max_score{0};
    for(int i = 1; i< tab.size();i++){
        for(int j = 1; j< tab[0].size() ;j++){
            max_score = std::max(max_score,getScore(i,j));
            // std::cout<<getScore(i,j)<<" ";
        }
        // std::cout<<"\n";
    }
    std::cout<<max_score;

    std::cout.flush();
    return 0;
}