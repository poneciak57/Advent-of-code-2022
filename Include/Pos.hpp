#pragma once
#include <iostream>
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