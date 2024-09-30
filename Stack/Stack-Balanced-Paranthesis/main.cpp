/*
    Checking for balanced parenthesis
    Symbols - (), {}, []
*/

#include <iostream>
#include <stack>
#include <cstring>

bool check(const char* str);

bool check(const char* str){
    std::stack<char> s;
    int n = std::strlen(str);

    for (int i{0}; i < n; ++i){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s.push(str[i]);
        } 
        
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if (s.empty()){
                return false;
            }

            char top = s.top();
            s.pop();

            if ((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
                (str[i] == '}' && top != '{')) {
                return false;  // Mismatch found
            }
        }
        
    }

    return s.empty();
}

int main(){

    char exp1[] = ")(";
    char exp2[] = "[()]";
    char exp3[] = "[()()]";
    
    std::cout << std::boolalpha;
    std::cout << check(exp1) << std::endl;  // Output: 0 (false)
    std::cout << check(exp2) << std::endl;  // Output: 1 (true)
    std::cout << check(exp3) << std::endl;  // Output: 1 (true)

    return 0;
}