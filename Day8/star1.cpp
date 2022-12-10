#include <bits/stdc++.h>


struct Tree{
    int v;
    int visible;
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string inp;
    std::vector<std::vector<Tree>> tab;

    while(std::cin>>inp){
        std::vector<Tree> temp;
        for(char &c: inp){
            temp.push_back({(int)c-48,0});
        }
        tab.push_back(temp);
    }


    int max{-1},sum{0};
    for(auto &row : tab){
        max = -1;
        for(auto &tree : row){
            tree.visible += tree.v > max;
            max = std::max(max,tree.v);
        }
        max = -1;
        for(int i = row.size()-1; i>=0;i--){
            Tree& tree = row[i];
            tree.visible += tree.v > max;
            max = std::max(max,tree.v);
        }
    }
    for(int i = 0; i<tab[0].size() ;i++){
        max = -1;
        for(int j = 0;j<tab.size();j++){
            Tree& tree = tab[j][i];
            tree.visible += tree.v > max;
            max = std::max(max,tree.v);
        }
        max = -1;
        for(int j = tab.size()-1;j>=0;j--){
            Tree& tree = tab[j][i];
            tree.visible += tree.v > max;
            max = std::max(max,tree.v);
            sum+=(tree.visible ==0);
        }
    }
    std::cout<<tab.size()*tab[0].size() - sum<<"\n";
    std::cout<<sum;
    // for(auto &row : tab){
    //     for(auto &tree : row){
    //         std::cout<<tree.visible;
    //     }
    //     std::cout<<"\n";
    // }
    std::cout.flush();    
    return 0;
}