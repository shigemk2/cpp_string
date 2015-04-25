// 読み取り専用位置 ‘*(s + 1u)’ への代入です
int main() {
    const char *s = "abc";
    s[1] = 'B';  // コンパイルエラー
}
