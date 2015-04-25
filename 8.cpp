void test1(char *) {}
void test2(const char *) {}

int main() {
    const char *a = "abc";
    char b[] = "abc";
    // test1(a);  // エラー
    test1(b);  // OK
    test2(a);  // OK
    test2(b);  // OK
}
