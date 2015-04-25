#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
    char *str;

    mystr(const char *s) {
        str = (char *)malloc(strlen(s) + 1);
        strcpy(str, s);
    }

    void printn() {
        printf("%s\n", str);
    }
};

// ローカルコピーしているので、値は書き換わらない
int main() {
    char buf[] = "abc";
    mystr s = buf;
    buf[0] = 'A';
    s.printn();
}
