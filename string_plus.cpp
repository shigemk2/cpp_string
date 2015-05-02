#include <stdio.h>
#include <string>

int main() {
    std::string s1 = "abc";
    // string s1 = "abc";
    s1 += "def";
    printf("%s\n", s1.c_str());
}
