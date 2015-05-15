class MyStr(str: String) {
  def this() = this("123")

  def eq(s: String) = new MyStr(s)

  def println(): Unit = {
    print(s"$str\n")
  }
}

def test(s: MyStr) = {
  // s = "def" // エラー
  s.println()
}

val s = new MyStr("abc")
s.println()

val t = new MyStr()
t.eq("abc")
t.println()

test(s)
