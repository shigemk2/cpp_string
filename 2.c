#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[8];
    const char *s1 = "abcde";
    const char *s2 = "fghij";
    int max = sizeof(buf) - 1;
    buf[max] = 0;
    strncpy(buf, s1, max);
    strncat(buf, s2, max - strlen(buf));
    printf("%s\n", buf);
    return 0;
}
