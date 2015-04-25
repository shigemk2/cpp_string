// [1]    18653 segmentation fault (core dumped)  ./a.out
int main() {
    char *s = "abc";
    s[1] = 'B';  // 実行時エラー
}
