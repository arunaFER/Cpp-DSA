/*
    String reversal using stack
*/

#include <iostream>
#include <stack>
#include <cstring>

void reverse(char* c, int n){
    std::stack<char> s;

    // to push
    for(int i{0}; i < n; ++i){
        s.push(c[i]);
    }

    // to pop
    for (int i {0}; i < n; ++i){
        c[i] = s.top();
        s.pop();
    }
}

int main(){
    char str[] = "Hello";
    int n = std::strlen(str);
    reverse(str, n);
    std::cout << str << std::endl;
    
    return 0;
}