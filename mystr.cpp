#include <stdio.h>
#include <string.h>

class mystr {
private:
    char *str;
    // メンバ変数で長さを保持すればstrlen()の使用回数を減らすことができます。
    size_t len;
    // バッファサイズを保持するメンバ変数を追加
    size_t buflen;

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
        delete[] str;
    }

    void printn() const {
        printf("%s\n", str);
    }

private:
    // set()は内部だけで使用するため非公開にします
    // バッファサイズの最小値を16として、不足すれば収まるまで倍に拡張します。
    void set(const char *s, size_t newlen) {
        char *old = str;
        len = newlen;
        if(!old || buflen < len) {
            if (!old) buflen = 16;
            while (buflen < len)
                buflen += buflen;
            str = new char[buflen + 1];
        }
        if (str != s) strcpy(str, s);
        if (old != str) delete[] old;
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
        set(s.str, s.len);
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
    mystr s = "abcd";
    printf("[%d]%s\n", s.length(), s.c_str());
    mystr s1 = "abcd" + s;
    printf("[%d]%s\n", s1.length(), s1.c_str());
}
