#include <stdio.h>
#include <string>

int main() {
    std::string s1 = "abcde";
    std::string s2 = "fghij";
    std::string buf = s1 + s2;
    printf("%s\n", buf.c_str());
}
