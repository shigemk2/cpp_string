import java.io._

def withWriter(filename: String)(op: Writer => Unit) {
  val writer = new BufferedWriter(new OutputStreamWriter(
    new FileOutputStream(filename),"UTF-8"))
  // op(writer)だけだと処理されない
  try {
    op(writer)
  } finally {
    writer.close()
  }
}

withWriter("test.txt"){
  writer => writer.write("this is sample")
}
