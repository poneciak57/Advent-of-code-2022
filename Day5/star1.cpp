#include <bits/stdc++.h>



int main(){

    std::vector<std::deque<char>> tab(10);
    std::string inp;

    do{
        std::getline(std::cin,inp);
        for(int i = 0;i<inp.length();i++){
            if((int)inp[i] >= 65 && (int)inp[i] <=90){
                // std::cout<<inp[i]<<(i-1)/4<<"\n";
                tab[(i-1)/4].push_front(inp[i]);
            }
        }
    }while(inp.length()!=0);
    std::string t1,t2,t3;
    int q,f,t;
    while (std::cin>>t1>>q>>t2>>f>>t3>>t)
    {
        f -= 1;
        t -= 1;
        while (q--)
        {
            tab[t].push_back(tab[f].back());
            tab[f].pop_back();
        }
    }
    for(auto &q : tab){
        if(!q.empty())
            std::cout<<q.back();
    }
    return 0;
}