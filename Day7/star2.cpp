#include <bits/stdc++.h>

struct Node{
    long long size;
    Node* parrent;
    bool root{false};
};

std::vector<long long> doneNodes;

/**
 * zaczynamy z root noda
 * kiedy wychodzimy z noda znaczy ze go przejrzelismy wrzucamy jego rozmiar do przejrzanych
 * wracamy do parent noda i dodajemy mu size nodea
 * nie trzymamy polaczen tylko na biezaco dodajemy sizey dirow
 * cd .. - node skonczony
 * cd <nodename> - utworz node z parentem w obecnym (zawsze po tym ls)
 * dir <nodename> - pomijamy
 * ls - pomijamy
*/
int main(){
    std::string t,c,d;
    std::cin>>t>>t>>t>>t>>t;
    Node root{0,nullptr,true};
    Node *curr = &root;
    while(std::cin>>c){
        if(c == "$"){
            std::cin>>c;
            if(c == "cd"){
                std::cin>>c;
                if(c == ".."){
                    doneNodes.push_back(curr->size);
                    curr->parrent->size+=curr->size;
                    Node* temp = curr;
                    curr = curr->parrent;
                    delete temp;
                }else{
                    Node* temp = curr;
                    curr = new Node;
                    curr->parrent = temp;
                    curr->size = 0;
                }
            }
        }else if(c == "dir"){
            std::cin>>t;
        }else{
            curr->size+=stoi(c);
            std::cin>>t;
        }
    }
    while (!curr->root)
    {
        doneNodes.push_back(curr->size);
        curr->parrent->size+=curr->size;
        Node* temp = curr;
        curr = curr->parrent;
        delete temp;
    }
    long long smalest{70000000};
    const long long aspace{70000000};
    const long long nspace{30000000};
    long long need = nspace - (aspace - curr->size);
    for(long long a: doneNodes){
        if(a >= need){
            smalest = std::min(smalest,a);
        }
    }
    std::cout<<smalest;
    return 0;
}