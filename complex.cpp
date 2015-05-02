#include <stdio.h>
#include <string>

class Complex {
private:
int a, b;

public:
Complex(int real) {
a = real;
b = 0;
}

Complex(int real, int imag) {
a = real;
b = imag;
}

Complex(const Complex &c) {
*this = c;
}

Complex &operator=(const Complex &c) {
a = c.a;
b = c.b;
return *this;
}

Complex &operator+=(const Complex &c) {
a += c.a;
b += c.b;
return *this;
}

Complex &operator-=(const Complex &c) {
a -= c.a;
b -= c.b;
return *this;
}

Complex &operator*=(const Complex &c) {
Complex tmp = *this;
a = tmp.a * c.a - tmp.b * c.b;
b = tmp.a * c.b + tmp.b * c.a;
return *this;
}

std::string str() const {
char buf[32];
if (b == 0) {
snprintf(buf, sizeof(buf), "%d", a);
} else if (a == 0) {
if (b == -1) return "-i";
if (b ==  1) return  "i";
snprintf(buf, sizeof(buf), "%di", b);
} else if (b == -1) {
snprintf(buf, sizeof(buf), "%d-i", a);
} else if (b < 0) {
snprintf(buf, sizeof(buf), "%d%di", a, b);
} else if (b == 1) {
snprintf(buf, sizeof(buf), "%d+i", a);
} else {
snprintf(buf, sizeof(buf), "%d+%di", a, b);
}
return buf;
}
};

Complex operator+(const Complex &c1, const Complex &c2) {
Complex ret = c1;
ret += c2;
return ret;
}

Complex operator-(const Complex &c1, const Complex &c2) {
Complex ret = c1;
ret -= c2;
return ret;
}

Complex operator*(const Complex &c1, const Complex &c2) {
Complex ret = c1;
ret *= c2;
return ret;
}

int main() {
Complex i(0, 1);
Complex a = 1 + 2*i;
Complex b = 3 + 4*i;
Complex c = a + b;
Complex d = a * b;
Complex e = a - 1;
Complex f = a - 2*i;
printf("a = %s\n", a.str().c_str());
printf("b = %s\n", b.str().c_str());
printf("c = %s\n", c.str().c_str());
printf("d = %s\n", d.str().c_str());
printf("e = %s\n", e.str().c_str());
printf("f = %s\n", f.str().c_str());
}
