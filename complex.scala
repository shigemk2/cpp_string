object ComplexImplicits {
  implicit def fromInt(re: Int) = new Complex(re, 0)
}

import ComplexImplicits._

case class Complex(real: Int, imag: Int) {
  def this(re: Int) = this(re, 0)

  def +(that: Complex) = Complex(real + that.real, imag + that.imag)
  def +(re: Int) = Complex(real + re, imag)
  def *(that: Complex) = {
    val a = that.real * real - that.imag * imag
    val b = that.real * imag + that.imag * real
    Complex(a, b)
  }
  def *(re: Int) = Complex(real * re, imag)
  def -(that: Complex) = Complex(real - that.real, imag - that.imag)
  def -(re: Int) = Complex(real - re, imag)

  override def toString() = {
    (real, imag) match {
      case (real, imag) if real == 0 && imag == 1 => "i"
      case (real, imag) if real == 0 && imag == -1 => "-i"
      case (real, imag) if real == 0 && imag == 0 => "0"
      case (real, imag) if real == 0 => imag + "i"
      case (real, imag) if imag > 1 => real + " + " + imag + "i"
      case (real, imag) if imag == 1 => real + " + i"
      case (real, imag) if imag == 0 => real.toString
      case (real, imag) if imag == -1 => real + " - i"
      case (real, imag) if imag < -1 => {
        real + " - " + imag.abs + "i"
      }
    }
  }
}

val i = new Complex(0, 1)
val a = 1 + 2 * i
val b = 3 + 4 * i
val c = a + b
val d = a * b
val e = a - 1
val f = a - 2 * i;

println(a)
println(b)
println(c)
println(d)
println(e)
println(f)
