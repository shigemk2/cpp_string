#include <stdio.h>
#include <string>

int main() {
    std::string s1 = "abcdefg";
    std::string s2 = s1.substr(2, 3);
    printf("%s\n", s2.c_str());
}
