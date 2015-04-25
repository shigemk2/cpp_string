#include <stdio.h>
#include <string.h>

struct mystr {
    char *str;

    mystr(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~mystr() {
        printf("delete ~mystr: %s\n", str);
        delete[] str;
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
