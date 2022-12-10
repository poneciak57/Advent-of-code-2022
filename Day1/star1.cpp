#include <bits/stdc++.h>

int main(){

    long elf{0};
    long max_elf{0};
    long inp;
    while (std::cin>>inp)
    {
        if(inp==0){
            max_elf = std::max(max_elf,elf);
            elf = 0;
            continue;
        }
        elf += inp;
    }
    max_elf = std::max(max_elf,elf);
    std::cout<<max_elf;
    return 0;
}