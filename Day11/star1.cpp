#include <bits/stdc++.h>
typedef long long ll;


// int globaldivider{1};
std::stringstream split(std::string str,char del){
    std::string temp = "";
    std::stringstream ret;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
            continue;
        }
        ret << temp;
        temp = " ";
    }
    ret<<temp;
    return ret;
}
struct Operation{
    std::function<ll(ll,ll)> op;
    int b;

    ll doOperation(ll old){
        if(b == -1){
            return op(old,old);
        }
        return op(old,b);
    }
    Operation(std::string op,std::string b){
        if(op[0] == '+'){
            this->op = [](ll a,ll b){return a + b;};
        }else if(op[0] == '*'){
            this->op = [](ll a,ll b){return a * b;};
        }
        if(b[0] == 'o'){
            this->b = -1;
        }else{
            this->b = stoi(b);
        }
    }
};
struct Monkey{
    std::list<ll> items;
    Operation op;
    int divisible;
    int trueMonkey;
    int falseMonkey;
    ll counter{0};
};
//Monkey .{0,}:
//
//Test: divisible by 
//  If true: throw to monkey 
//  If false: throw to monkey
std::vector<Monkey> monkeys;

void printMonkeys(){
    int i{0};
    for(auto &m: monkeys){
        std::cout<<"Monkey "<<i<<": ";
        for(auto &item: m.items){
            std::cout<<item<<" ";
        }
        i++;
        std::cout<<"\n";
    }
}

void readMonkeys(){
    std::string items;
    while(std::cin>>items){
        std::stringstream items_stream = split(items,',');
        std::list<ll> temp_list;
        ll t_l;
        while(items_stream>>t_l){
            temp_list.push_back(t_l);
        }
        std::string a,o,b;
        std::cin>>a>>o>>b;
        Operation op(o,b);
        int d,t,f;
        std::cin>>d>>t>>f;
        monkeys.push_back({temp_list,op,d,t,f,0});
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    readMonkeys();
    const int ROUNDS{20};
    // printMonkeys();
    for(int i = 0;i<ROUNDS;i++){
        for(auto &m: monkeys){
            for(auto &item: m.items){
                ll newItem = m.op.doOperation(item) /3;
                if( newItem % m.divisible == 0){
                    monkeys[m.trueMonkey].items.push_back(newItem);
                }else{
                    monkeys[m.falseMonkey].items.push_back(newItem);
                }
                m.counter++;
            }
            m.items = {};
        }
    }
    // printMonkeys();
    sort(monkeys.begin(), monkeys.end(), 
    [](const Monkey & a, const Monkey & b) -> bool{ 
        return a.counter > b.counter; 
    });
    std::cout<<monkeys[0].counter*monkeys[1].counter;

    std::cout.flush();  
    return 0;
}