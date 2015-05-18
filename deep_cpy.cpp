#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
    char s[10000];

    A() {
        strcpy(s, "123");
    }

    A(const A& a) {
        memcpy(s, a.s, sizeof(s));
    }

    void printn() {
        printf("%s\n", s);
    }
};

int main() {
    A a;
    return 0;
}
