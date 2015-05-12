class MyStr(str: String) {
  def this() = this("123")

  def println(): Unit = {
    print(s"$str\n")
  }
}

val s = new MyStr("abc")
s.println()

val t = new MyStr()
t.println()
