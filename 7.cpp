#include <stdio.h>

int main() {
    char s[] = "abc";
    s[1] = 'B';  // OK
    printf("%s\n", s);
}
