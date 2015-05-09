class MyStr(str: String) {
  def println(): Unit = {
    print(s"$str")
  }
}

val s = new MyStr("abc")
s.println()
