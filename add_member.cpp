#include <stdio.h>
#include <string.h>

struct mystr {
    char *str;
    size_t len;

    mystr() {
        str = NULL;
        *this = "";
    }

    mystr(const char *s) {
        str = NULL;
        *this = s;
    }

    mystr(const mystr &s) {
        str = NULL;
        *this = s.str;
    }

    ~mystr() {
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

    mystr &operator+=(const char *s) {
        char *old = str;
        len += strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
        return *this;
    }

    mystr &operator=(const char *s) {
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        return *this;
    }
};

int main() {
    mystr s1 = "abc";
    mystr s2 = s1;
    s1 += "def";
    s2 += "ghi";
    printf("s1[%d]=%s\n", s1.len, s1.str);
    printf("s2[%d]=%s\n", s2.len, s2.str);
}
