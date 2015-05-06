#include <stdio.h>
#include <string.h>
#include <time.h>

class mystr {
private:
    char *str;
    // メンバ変数で長さを保持すればstrlen()の使用回数を減らすことができます。
    size_t len;
    // バッファサイズを保持するメンバ変数を追加
    size_t buflen;
    // バッファ操作で参照カウントを増減
    int *refcount;

public:
    // strを返すだけの関数
    const char *c_str() const { return str; }
    // 長さを返すだけの関数
    size_t length() const { return len; }

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
        unset(str);
    }

    void printn() const {
        printf("%s\n", str);
    }

private:
    // set()は内部だけで使用するため非公開にします
    // バッファサイズの最小値を16として、不足すれば収まるまで倍に拡張します。
    // バッファが共有された数を記録しておいて、ゼロになれば解放する
    void set(const char *s, size_t newlen) {
        char *old = str;
        len = newlen;
        if (!old || buflen < len) {
            if (!old) buflen = 16;
            while (buflen < len)
                buflen += buflen;
            str = new char[buflen + 1];
        }
        if (str != s) strcpy(str, s);
        if (old != str) {
            unset(old);
            refcount = new int(1);
        }
    }

    // バッファが共有された数を記録しておいて、ゼロになれば解放する方法です。このような方法を参照カウントと呼びます。
    void unset(char *str) {
        if (str && --*refcount == 0) {
            delete refcount;
            delete[] str;
        }
    }

public:
    // +=演算子をオーバーロード
    mystr &operator+=(const char *s) {
        int oldlen = len;
        set(str, len + strlen(s));
        strcpy(&str[oldlen], s);
        return *this;
    }

    // 関数のオーバーロード
    mystr &operator+=(const mystr &s) {
        int oldlen = len;
        set(str, len + s.len);
        strcpy(&str[oldlen], s.str);
        return *this;
    }

    // =演算子をオーバーロード
    mystr &operator=(const char *s) {
        set(s, strlen(s));
        return *this;
    }

    // 関数のオーバーロード
    mystr &operator=(const mystr &s) {
        unset(str);
        str = s.str;
        len = s.len;
        buflen = s.buflen;
        ++*(refcount = s.refcount);
        return *this;
    }

    // +演算子をオーバーロードしたやつをstructの外に出す
    // +演算子は新しいインスタンスを返しているため、自分自身のメンバ変数に影響を与えません。そのためconstを指定しています。
    mystr operator+(const mystr &s) const {
        mystr ret = *this;
        ret += s;
        return ret;
    }

    mystr substr(int start, int len) const {
        mystr ret;
        ret.set("", len);
        strncpy(ret.str, &str[start], len);
        ret.str[len] = 0;
        return ret;
    }
};

// +演算子をオーバーロードしたやつをstructの外に出す
// +演算子は新しいインスタンスを返しているため、自分自身のメンバ変数に影響を与えません。そのためconstを指定しています。
mystr operator+(const mystr &s1, const mystr &s2) {
    mystr ret = s1;
    ret += s2;
    return ret;
}

int main() {
    mystr s1, s2;
    for (int i = 0; i < 100000; ++i)
        s1 += "a";
    double t1 = (double)clock();
    for (int i = 0; i < 100000; ++i)
        s2 = s1;
    double t2 = (double)clock();
    printf("%.2fs\n",
        (t2 - t1) / CLOCKS_PER_SEC);
}
