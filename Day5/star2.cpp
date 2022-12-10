#include <bits/stdc++.h>

void printTab(std::vector<std::deque<char>> tab){
    int i{0};
    for(auto &q: tab){
        std::cout<<i<<": ";
        while(!q.empty()){
            std::cout<<q.front()<<" ";
            q.pop_front();
        }
        std::cout<<"\n";
        i++;
    }
}

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
    // printTab(tab);
    std::string t1,t2,t3;
    int q,f,t;
    while (std::cin>>t1>>q>>t2>>f>>t3>>t)
    {
        f -= 1;
        t -= 1;
        std::vector<char> tq;
        std::vector<char>::iterator it;
        while (q--)
        {
            tq.push_back(tab[f].back());
            tab[f].pop_back();
        }
        for (int i = tq.size()-1;i>=0;i--){
            tab[t].push_back(tq[i]);
        }
    }
    for(auto &q : tab){
        if(!q.empty())
            std::cout<<q.back();
    }
    return 0;
}