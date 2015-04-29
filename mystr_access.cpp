#include <stdio.h>
#include <string.h>
#include <time.h>

class mystr {
    char *str;
    size_t len;
    size_t buflen;

public:
    size_t length() const { return len; }

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
        if (!old || buflen < len) {
            if (!old) buflen = 16;
            while (buflen < len)
                buflen += buflen;
            str = new char[buflen + 1];
        }
        if (str != s) strcpy(str, s);
        if (old != str) delete[] old;
    }

    mystr &operator+=(const char *s) {
        int oldlen = len;
        set(str, len + strlen(s));
        strcpy(&str[oldlen], s);
        return *this;
    }

    mystr &operator+=(const mystr &s) {
        int oldlen = len;
        set(str, len + s.len);
        strcpy(&str[oldlen], s.str);
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

    mystr substr(int start, int len) const {
        mystr ret;
        ret.set("", len);
        strncpy(ret.str, &str[start], len);
        ret.str[len] = 0;
        return ret;
    }
};

int main() {
    mystr s = "abc";
    printf("[%d]\n", s.length());
    s.printn();
}
