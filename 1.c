#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[8];
    const char *s1 = "abc";
    const char *s2 = "def";
    strcpy(buf, s1);
    strcat(buf, s2);
    printf("%s\n", buf);
    return 0;
}
