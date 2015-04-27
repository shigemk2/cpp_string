#include <stdio.h>

int main() {
    int i = 1;
    (i += 3) += 5;
    printf("i = %d\n", i);
}
