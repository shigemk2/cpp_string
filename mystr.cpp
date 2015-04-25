#include <stdio.h>

struct mystr {
    const char *str;

    void printn() {
        printf("%s\n", str);
    }
};

int main() {
    mystr s = { "abc" };
    s.printn();
}
