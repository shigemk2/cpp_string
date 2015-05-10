case class Complex(real: Int, imag: Int) {
  def this(re: Int) = this(re, 0)

  implicit def +(that: Complex) = Complex(real + that.real, imag + that.imag)
  implicit def *(that: Complex) = Complex(real * that.real, imag * that.imag)
  implicit def -(that: Complex) = Complex(real - that.real, imag - that.imag)

  override def toString() = {
    (real, imag) match {
      case (real, imag) if real == 0 && imag == 1 => "i"
      case (real, imag) if real == 0 && imag == -1 => "-i"
      case (real, imag) if real == 0 && imag == 0 => "0"
      case (real, imag) if real == 0 => imag + "i"
      case (real, imag) if imag > 0 => real + " + " + imag + "i"
      case (real, imag) if imag == 0 => real.toString
      case (real, imag) if imag < 0 => {
        real + " - " + imag.abs + "i"
      }
    }
  }
}

val i = new Complex(0, 1)
val a = new Complex(1, 2)
val b = new Complex(3, 4)
val c = a + b
val d = a * b
val e = a - b
val f = a - a

println(a)
println(b)
println(c)
println(d)
println(e)
println(f)
