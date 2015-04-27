#include <stdio.h>
#include <string>

int main() {
    std::string s = "abc";
    (s += "def") += "ghi";
    printf("s = %s\n", s.c_str());
}
