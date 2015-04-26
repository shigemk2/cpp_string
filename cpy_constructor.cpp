#include <stdio.h>
#include <string>

int main() {
    std::string s1 = "abc";
    std::string s2 = s1;
    s1 += "def";
    s2 += "ghi";
    printf("s1: %s\n", s1.c_str());
    printf("s2: %s\n", s2.c_str());
}
