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
        *this = s;
    }

    ~mystr() {
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

    void set(const char *s, size_t newlen) {
        char *old = str;
        len = newlen;
        str = new char[len + 1];
        strcpy(str, s);
        delete[] old;
    }


    mystr &operator+=(const char *s) {
        set(str, len + strlen(s));
        strcat(str, s);
        return *this;
    }

    mystr &operator+=(const mystr &s) {
        set(str, len + s.len);
        strcat(str, s.str);
        return *this;
    }

    mystr &operator=(const char *s) {
        set(s, strlen(s));
        return *this;
    }

    mystr &operator=(const mystr &s) {
        set(s.str, s.len);
        return *this;
    }

    mystr operator+(const mystr &s) const {
        mystr ret = *this;
        ret += s;
        return ret;
    }
};

int main() {
    mystr s1 = "abcde";
    mystr s2 = "fghij";
    mystr buf = s1 + s2;
    buf.printn();
}
