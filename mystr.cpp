#include <stdio.h>
#include <stdlib.h>
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
        printf("free ~mystr: %s\n", str);
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

    mystr &operator+=(const char *s) {
        char *old = str;
        int len = strlen(str) + strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
        return *this;
    }
};

void testp() {
    printf("testp\n");
    mystr a = "abc";
    mystr *b = &a;
    printf("a = %s, b = %s\n", a.str, b->str);
    a += "def";
    printf("a = %s, b = %s\n", a.str, b->str);
    *b += "ghi";
    printf("a = %s, b = %s\n", a.str, b->str);
}

void testr() {
    printf("testr\n");
    mystr a = "abc";
    mystr &b = a;
    printf("a = %s, b = %s\n", a.str, b.str);
    a += "def";
    printf("a = %s, b = %s\n", a.str, b.str);
    b += "ghi";
    printf("a = %s, b = %s\n", a.str, b.str);
}

void test(const mystr &s) {
    s.printn();  // エラー
}

int main() {
    mystr s = "abc";
    (s += "def") += "ghi";
    printf("s = %s\n", s.str);
}
