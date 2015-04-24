#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *s1 = "abcde";
    const char *s2 = "fghij";
    size_t len = strlen(s1) + strlen(s2);
    char *buf = (char *)malloc(len + 1);
    buf[len] = 0;
    strcpy(buf, s1);
    strcat(buf, s2);
    printf("%s\n", buf);
    free(buf);
    return 0;
}
