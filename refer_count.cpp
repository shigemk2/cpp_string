#include <time.h>
#include <stdio.h>
#include <string>

int main() {
    std::string s1, s2;
    for (int i = 0; i < 100000; ++i)
        s1 += "a";
    double t1 = (double)clock();
    for (int i = 0; i < 100000; ++i)
        s2 = s1;
    double t2 = (double)clock();
    printf("%.2fs\n",
        (t2 - t1) / CLOCKS_PER_SEC);
}

