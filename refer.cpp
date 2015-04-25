#include <stdio.h>
#include <string.h>

void testp() {
    printf("testp\n");
    int a = 1;
    int *b = &a;
    printf("a = %d, b = %d\n", a, *b);
    a = 2;
    printf("a = %d, b = %d\n", a, *b);
    *b = 3;
    printf("a = %d, b = %d\n", a, *b);
}

void testr() {
    printf("testr\n");
    int a = 1;
    int &b = a;
    printf("a = %d, b = %d\n", a, b);
    a = 2;
    printf("a = %d, b = %d\n", a, b);
    b = 3;
    printf("a = %d, b = %d\n", a, b);
}

// 具体的には、aの値、もしくはbの値を変更すると、それにつられてもう片方の値も変わる
int main() {
    testp();
    testr();
}
