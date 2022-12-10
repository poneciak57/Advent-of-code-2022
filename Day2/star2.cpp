#include <bits/stdc++.h>


int main(){

/**
 * A X = Z
 * A Y = X
 * A Z = Y
 * 
 * B X = X
 * B Y = Y
 * B Z = Z
 * 
 * C X = Y
 * C Y = Z
 * C Z = X
*/
    int A[3] {3,4,8};
    int B[3] {1,5,9};
    int C[3] {2,6,7};
    std::map<char,int*> scores{
        {'A',A},
        {'B',B},
        {'C',C}
    };
    char a,b;
    long long score{0};
    while(std::cin>>a>>b){
        score+= scores[a][(int)b - 88];
    }
    std::cout<<score;

    return 0;
}