#include <bits/stdc++.h>


int main(){

/**
 * A X = 3
 * A Y = 6
 * A Z = 0
 * 
 * B X = 0
 * B Y = 3
 * B Z = 6
 * 
 * C X = 6
 * C Y = 0
 * C Z = 3
*/
    int A[3] {3,6,0};
    int B[3] {0,3,6};
    int C[3] {6,0,3};
    std::map<char,int*> scores{
        {'A',A},
        {'B',B},
        {'C',C}
    };
    char a,b;
    long long score{0};
    while(std::cin>>a>>b){
        int b_int = (int)b - 87;
        score+= b_int;
        score+= scores[a][b_int-1];
    }
    std::cout<<score;

    return 0;
}