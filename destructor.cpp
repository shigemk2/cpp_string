#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
    char *str;

    mystr(const char *s) {
        str = (char *)malloc(strlen(s) + 1);
        strcpy(str, s);
    }

    ~mystr() {
        printf("free ~mystr: %s\n", str);
        free(str);
    }

    void printn() {
        printf("%s\n", str);
    }
};

int main() {
    char buf[] = "abc";
    mystr s = buf;
    buf[0] = 'A';
    s.printn();
    printf("last of main()\n");
}
