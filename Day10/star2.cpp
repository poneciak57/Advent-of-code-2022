#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> cycles(300,0);
    std::string instruction;
    int cycle_count{1};
    int X{1};
    while(std::cin>>instruction){
        if(instruction[0] == 'a'){
            int t;
            std::cin>>t;
            cycles[cycle_count] = X;
            cycle_count++;
            cycles[cycle_count] = X;
            cycle_count++;
            X+=t;
        }else{
            cycles[cycle_count] = X;
            cycle_count+=1;
        }
    }
    int sum{0};
    for(int i = 1; i<cycles.size();i+=40){

        for(int j = i; j< i+40;j++){
            if((cycles[j]+1) >= (j-i) && (cycles[j]-1) <= (j-i)){
                std::cout<<"#";
                continue;
            }
            std::cout<<".";
        }
        std::cout<<"\n";
    }
    std::cout<<sum;

    std::cout.flush();  
    return 0;
}