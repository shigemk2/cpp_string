#include <stdio.h>

void inc(int &x) {
    ++x;
}

int main() {
    int a = 1;
    inc(a);
    printf("%d\n", a);
}
