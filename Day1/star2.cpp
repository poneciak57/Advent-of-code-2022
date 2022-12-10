#include <bits/stdc++.h>

int main(){

    std::priority_queue<long> q;
    long elf{0};
    long inp;
    while (std::cin>>inp)
    {
        if(inp==0){
            q.push(elf);
            elf = 0;
            continue;
        }
        elf += inp;
    }
    q.push(elf);
    int how_many_elfs = 3;
    int sum{0};
    while(how_many_elfs--){
        sum+=q.top();
        q.pop();
    }
    std::cout<<sum;
    return 0;
}