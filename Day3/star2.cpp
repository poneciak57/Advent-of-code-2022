#include <bits/stdc++.h>

bool findInString(std::string s,char cc){
    for(char &c:s){
        if(cc == c){
            return true;
        }
    }
    return false;
}

int main(){
    std::string e1,e2,e3;
    long long sum{0};
    while(std::cin>>e1>>e2>>e3){
        for (char &c: e1){
            if (findInString(e2,c) && findInString(e3,c))
            {
                sum += (int)c - 38 - 58*((int)c > 90);
                break;
            }  
        }
    }
    std::cout<<sum;
    return 0;
}