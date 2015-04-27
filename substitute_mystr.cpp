#include <stdio.h>
#include <string.h>

struct mystr {
    char *str;

    mystr() {
        str = new char[1];
        str[0] = 0;
    }

    ~mystr() {
        delete[] str;
    }

    void printn() {
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

    mystr &operator=(const char *s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        return *this;
    }
};

int main() {
    mystr s;
    s = "abc";
    s.printn();
}
