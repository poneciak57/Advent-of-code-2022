#pragma once
#include <bits/stdc++.h>

namespace Helpers{
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
}