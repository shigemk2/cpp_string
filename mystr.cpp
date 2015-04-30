#include <stdio.h>

struct mystr {
    const char *str;

    mystr(const char *s) {
        str = s;
    }

    void printn() {
        printf("%s\n", str);
    }
};

int main() {
    mystr s = "abc";
    printf("%s\n", s);
    s.printn();
}
