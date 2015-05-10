case class Complex(real: Int, imag: Int) {
  def +(that: Complex) = Complex(real + that.real, imag + that.imag)
  def *(that: Complex) = Complex(real * that.real, imag * that.imag)
  def -(that: Complex) = Complex(real - that.real, imag - that.imag)

  def str() = {
    imag match {
      case imag if imag > 0 => real + " + " + imag + "i"
      case imag if imag == 0 => real
      case imag if imag < 0 => {
        real + " - " + imag.abs + "i"
      }
    }
  }
}

val i = new Complex(0, 1)
val a = new Complex(1, 3)
val b = new Complex(3, 1)
val c = a + b
val d = a * b
val e = a - b
val f = b - a
println(a.str)
println(b.str)
println(c.str)
println(d.str)
println(e.str)
println(f.str)
