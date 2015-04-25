int main() {
    int a = 1;
    const int &b = a;
    b = 2;  // エラー
}
