#include <stdio.h>
#include <string.h>

struct mystr {
    char *str;

    mystr(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    mystr(const mystr &s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    ~mystr() {
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

    void operator+=(const char *s) {
        char *old = str;
        int len = strlen(str) + strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
    }
};

int main() {
    mystr s1 = "abc";
    mystr s2 = s1;
    s1 += "def";
    s2 += "ghi";
    printf("s1: %s\n", s1.str);
    printf("s2: %s\n", s2.str);
}
