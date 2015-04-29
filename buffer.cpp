#include <time.h>
#include <stdio.h>
#include <string>

int main() {
    double t1 = (double)clock();
    std::string s;
    for (int i = 0; i < 100000000; ++i)
        s += "a";
    double t2 = (double)clock();
    printf("%.2fs\n", (t2 - t1) / CLOCKS_PER_SEC);
}
