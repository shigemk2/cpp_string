#include <stdio.h>
#include <string.h>

struct mystr {
    char *str;

    mystr(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~mystr() {
        delete[] str;
    }

    void printn() {
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
    mystr s = "abc";
    // s += "def";
    (s += "def") += "ghi";  // エラー
    printf("s = %s\n", s.str);
}
