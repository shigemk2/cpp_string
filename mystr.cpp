#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
    char *str;

    // 初期値を与えないで引数を宣言
    mystr() {
        str = NULL;
        *this = "";
    }

    // コンストラクタ
    mystr(const char *s) {
        str = NULL;
        *this = s;
    }

    // 代入の実現 コピーコンストラクタ
    mystr(const mystr &s) {
        str = NULL;
        *this = s.str;
    }

    ~mystr() {
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

    // +=演算子をオーバーロード
    mystr &operator+=(const char *s) {
        char *old = str;
        int len = strlen(str) + strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
        return *this;
    }

    // =演算子をオーバーロード
    mystr &operator=(const char *s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        return *this;
    }
};

void testp() {
    printf("testp\n");
    mystr a = "abc";
    mystr *b = &a;
    printf("a = %s, b = %s\n", a.str, b->str);
    a += "def";
    printf("a = %s, b = %s\n", a.str, b->str);
    *b += "ghi";
    printf("a = %s, b = %s\n", a.str, b->str);
}

void testr() {
    printf("testr\n");
    mystr a = "abc";
    mystr &b = a;
    printf("a = %s, b = %s\n", a.str, b.str);
    a += "def";
    printf("a = %s, b = %s\n", a.str, b.str);
    b += "ghi";
    printf("a = %s, b = %s\n", a.str, b.str);
}

void test(const mystr &s) {
    s.printn();  // エラー
}

int main() {
    mystr s;
    s = "abc";
    s.printn();
}
