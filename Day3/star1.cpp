#include <bits/stdc++.h>


int main(){
    std::string line;
    long long sum{0};
    while(std::cin>>line){
        std::string first = line.substr(0, line.length()/2);
        std::string second = line.substr(line.length()/2);
        bool go{true};
        for (char &c1: first){
            if(!go){
                break;
            }
            for(char &c2: second){
                if(c1 == c2){
                    sum += (int)c1 - 38 - 58*((int)c1 > 90);
                    go = false;
                    break;
                }
            }
        }
        
    }
    std::cout<<sum;
    return 0;
}