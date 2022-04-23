#include<iostream>
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)

template<typename ...Args>void logger(string vars, Args&&... values) {
    std::cerr<<" { " << vars << " = ";
    string delim = "";
    (..., (std::cerr << delim << values, delim = ", "));
    std::cerr<<" }"<<endl;
}
