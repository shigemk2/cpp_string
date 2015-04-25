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
    char buf[] = "abc";
    mystr s = buf;
    s.printn();
    buf[0] = 'A';
    s.printn();
}
