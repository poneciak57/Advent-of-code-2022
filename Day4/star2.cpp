#include <bits/stdc++.h>

// A quick way to split strings separated via any character
// delimiter.
std::vector<std::string> adv_tokenizer(std::string s, char del)
{
    std::vector<std::string> ret;
    std::stringstream ss(s);
    std::string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        ret.push_back(word);
    }
    return ret;
}
std::stringstream split(std::string str){
    std::string temp = "";
    std::stringstream ret;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != ',' && str[i] != '-'){
            temp += str[i];
            continue;
        }
        ret << temp;
        temp = " ";
    }
    ret<<temp;
    return ret;
}
 
int main(int argc, char const* argv[])
{
    std::string inp;
    int sum{0};
    while(std::cin>>inp){
        std::stringstream ss = split(inp + " ");
        int e1p,e1e,e2p,e2e;
        ss >> e1p >> e1e >> e2p >> e2e;
        if(
            e1e>=e2p && e1e<=e2e ||
            e2e>=e1p && e2e<=e1e ||
            e1p>=e2p && e1p<=e2e ||
            e2p>=e1p && e2p<=e1e 
        ){
            sum++;
        }
    }
    std::cout<<sum;
    return 0;
}