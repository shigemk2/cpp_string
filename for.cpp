#include <stdio.h>

void string() {
    char *str;
    str = new char[1000000000];
}
int main() {
    for (unsigned int i = 0; i < 1000000 ; i++) {
        printf("i: %d\n", i);
        string();
    }
}
