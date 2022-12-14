#include <bits/stdc++.h>
#include <Pos.hpp>
typedef std::string S;

std::stringstream split(std::string str)
{
    std::string temp = "";
    std::stringstream ret;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] != '>' && str[i] != '-' && str[i] != ',')
        {
            temp += str[i];
            continue;
        }
        ret << temp;
        temp = " ";
    }
    ret << temp;
    return ret;
}

int HIGHEST_Y{0};

std::list<Pos> getPath(S line)
{
    std::list<Pos> ret;
    std::stringstream ss = split(line);
    Pos inp;
    while (ss >> inp.x >> inp.y)
    {
        HIGHEST_Y = std::max(HIGHEST_Y,inp.y);
        ret.push_back(inp);
    }
    return ret;
}

std::vector<std::vector<int>> grid(1000,std::vector<int>(1000,0));

void draw(Pos p){
    grid[p.y][p.x] = 1;
}

void drawPath(std::list<Pos> path){
    Pos c = path.front();
    draw(c);
    for(Pos &p: path){
        while(c.x != p.x){
            if(c.x < p.x){
                c.x++;
            }else{
                c.x--;
            }
            draw(c);
        }
        while(c.y != p.y){
            if(c.y < p.y){
                c.y++;
            }else{
                c.y--;
            }
            draw(c);
        }
    }
}

bool dropSand(){
    Pos p{500,0};
    if(grid[p.y][p.x]){
        return false;
    }
    while(p.y < 999){
        if(grid[p.y+1][p.x] == 0){
            p.y++;
        }else if(grid[p.y+1][p.x-1] == 0){
            p.y++;
            p.x--;
        }else if(grid[p.y+1][p.x+1] == 0){
            p.y++;
            p.x++;
        }else{
            draw(p);
            return true;
        }   
    }
    return false;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    S inp;
    Pos p{1, 1};
    while (std::getline(std::cin, inp))
    {
        drawPath(getPath(inp));
    }

    HIGHEST_Y += 2;
    drawPath({{0,HIGHEST_Y},{999,HIGHEST_Y}});
    int sum{0};
    while(dropSand()){
        sum++;
    }
    std::cout<<sum;

    std::cout.flush();
    return 0;
}