#include <bits/stdc++.h>


// It's the same as second star only DISTINCT variable is different//
int main(){
    const int DISTINCT{4};
    std::string buff;
    std::cin>>buff;
    for(int i{DISTINCT}; i< buff.length();i++){
        int ile{0};
        for(int j = i-DISTINCT;j<i;j++){
            for(int z = i-DISTINCT; z<i;z++){
                ile += (buff[j] == buff[z]);
            }
        }
        if(ile == DISTINCT){
            std::cout<<i;
            return 0;
        }
    }

    return 0;
}