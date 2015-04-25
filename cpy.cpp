#include <stdio.h>
#include <string>

int main() {
    char buf[] = "abc";
    std::string s = buf;
    printf("%s\n", s.c_str());
    // std::stringでは値をローカルコピーしているため、連動しません
    buf[0] = 'A';
    printf("%s\n", s.c_str());
}
