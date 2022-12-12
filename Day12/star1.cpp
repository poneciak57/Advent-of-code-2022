#include <bits/stdc++.h>

struct Pos{
    int x;
    int y;
};
bool operator==(const Pos &a,const Pos &b){
    return a.x == b.x && a.y == b.y;
}
Pos operator+(const Pos &a, const Pos &b){
    return {a.x + b.x, a.y +b.y};
}

std::vector<std::vector<int>> graf;

bool isInBounds(const Pos &p){
    return (p.x >= 0) && (p.x < (int)graf[0].size()) && (p.y >= 0) && (p.y < (int)graf.size());
}

int BFS(Pos s,Pos e){
    std::queue<std::pair<Pos,int>> q;
    q.push({s,0});
    Pos moves[4]{
        {1,0},{-1,0},{0,1},{0,-1}
    };
    Pos p = s;
    std::pair<Pos,int> c;
    while (!(p == e) && !q.empty()){
        c = q.front();
        q.pop();
        p = c.first;

        for(Pos &m : moves){
            Pos temp = p + m;
            if(isInBounds(temp)){
                int temp_g = graf[temp.y][temp.x];
                int temp_p = graf[p.y][p.x];
                // std::cout<<"p: "<<temp_p<<" t:"<<temp_g<<"\n";
                if((temp_p != -1)&&(temp_g!=-1) &&(temp_p >= temp_g || (temp_p+1) == temp_g)){
                    q.push({temp,c.second +1});
                    // std::cout<<"pushing x:"<<temp.x<<" y:"<<temp.y<<"\n";
                }
            }
        }
        graf[p.y][p.x] = -1;

    }
    return c.second;
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string inp;

    Pos start{0,0};
    Pos end{0,0};
    
    int r{0};
    while(std::cin>>inp){
        std::vector<int> temp;
        for(char &c: inp){
            if(c == 'S'){
                start = {(int)temp.size(),r};
                temp.push_back(0);
            }else if(c == 'E'){
                end = {(int)temp.size(),r};
                temp.push_back(25);
            }else{
                temp.push_back((int)c - 97);
            }
        }
        graf.push_back(temp);
        r++;
    }
    // for(auto &row: graf){
    //     for(auto &n : row){
    //         std::cout<<n<<" ";
    //     }
    //     std::cout<<"\n";
    // }
    // std::cout<<"starting bfs\n";
    std::cout<<BFS(start,end);

    std::cout.flush();  
    return 0;
}