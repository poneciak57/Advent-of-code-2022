#include <bits/stdc++.h>
typedef std::string S;

struct Node{
    int n;
    std::vector<Node> list;
    Node* parrent;
    bool isList;
};
Node convert(S s){
    Node main{-1,{},nullptr,true};
    s[0] = ',';
    s[s.size()-1] = ',';
    Node* curr = &main;
    for(int i =0;i<s.size();i++){
        if(s[i] == '['){
            curr->list.push_back({-1,{},curr,true});
            curr = &curr->list.back();
        }
        else if(s[i] == ']'){
            curr = curr->parrent;
        }
        else if(s[i] == ','){
            continue;
        }else{
            S temp{""};
            while (s[i] >=48 && s[i] <= 57)
            {
                temp+= s[i];
                i++;
            }
            i--;
            curr->list.push_back({std::stoi(temp),{},curr,false});
        }
    }
    return main;
}

void printNode(Node n){
    if(n.isList){
        std::cout<<"[";
        for(Node &el:n.list){
            printNode(el);
        }
        std::cout<<"]";
    }else{
        std::cout<<n.n;
    }
}

int compareNodes(Node n1,Node n2){
    
    for(int i =0;i<n1.list.size();i++){
        if((n2.list.size()) <= i){
            return 0;
        }
        if(!n1.list[i].isList && !n2.list[i].isList){
            if(n1.list[i].n > n2.list[i].n){
                return 0;
            }
            if(n1.list[i].n < n2.list[i].n){
                return 2;
            }
            continue;
        }
        Node n1t = n1.list[i];
        Node n2t = n2.list[i];
        if(!n1t.isList){
            n1t.isList = true;
            n1t.list.push_back({n1t.n,{},nullptr,false});
        }
        if(!n2t.isList){
            n2t.isList = true;
            n2t.list.push_back({n2t.n,{},nullptr,false});
        }
        int c = compareNodes(n1t,n2t);
        if(c == 1){
            continue;
        }
        return c;
    }
    return 1 + (n2.list.size()> n1.list.size());
}

bool compare(S first,S second){

    Node n1,n2;
    n1 = convert(first);
    n2 = convert(second);
    bool ret = compareNodes(n1,n2) == 2;


    // printNode(n1);
    // std::cout<<"\n";
    // printNode(n2);
    // std::cout<<"\n";
    // std::cout<<"isgood: "<<ret;
    // std::cout<<"\n";
    // std::cout<<"\n";

    return ret;
}

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    S pair1,pair2;
    int i{1};
    int sum{0};
    while (std::cin>>pair1>>pair2)
    {
        sum+= i*compare(pair1,pair2);
        i++;
    }
    
    std::cout<<sum;
    std::cout.flush();  
    return 0;
}
