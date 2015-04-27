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

    mystr &operator+=(const mystr &s) {
        char *old = str;
        len += s.len;
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s.str);
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
    mystr s = "abc";
    s += s;
    printf("s[%d]: %s\n", s.len, s.str);
}
