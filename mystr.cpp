#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
    char *str;
    // メンバ変数で長さを保持すればstrlen()の使用回数を減らすことができます。
    size_t len;

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

    void set(const char *s, size_t newlen) {
        char *old = str;
        len = newlen;
        str = new char[len + 1];
        strcpy(str, s);
        delete[] old;
    }

    // +=演算子をオーバーロード
    mystr &operator+=(const char *s) {
        set(str, len + strlen(s));
        strcat(str, s);
        return *this;
    }

    // 関数のオーバーロード
    mystr &operator+=(const mystr &s) {
        set(str, len + s.len);
        strcat(str, s.str);
        return *this;
    }

    // =演算子をオーバーロード
    mystr &operator=(const char *s) {
        set(s, strlen(s));
        return *this;
    }

    // 関数のオーバーロード
    mystr &operator=(const mystr &s) {
        set(s.str, s.len);
        return *this;
    }

    // +演算子をオーバーロード
    // +演算子は新しいインスタンスを返しているため、自分自身のメンバ変数に影響を与えません。そのためconstを指定しています。
    mystr operator+(const mystr &s) const {
        mystr ret = *this;
        ret += s;
        return ret;
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

// mystrのコンストラクタではconst char *を受け付けます。引数としてconst mystr &を取る関数を呼び出すとき、コンストラクタが自動的にconst char *からmystrに変換してくれます。
// このように引数でconst参照を使うことで、関数呼び出し時の無駄なコピーを抑制できます。
void test(const mystr &s) {
    s.printn();
}

int main() {
    mystr s1 = "abc";
    mystr s2 = "abc";
    mystr buf = s1 + s2;
    buf.printn();
}
