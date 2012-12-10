package calc;

import static org.junit.Assert.*

import org.junit.Test
import org.junit.Before

class StringCalculatorTest {

  def calc

  @Before
  public void setup() {
    calc = new StringCalculator()
  }

  @Test
  public void emptyString() {
    assert 0 == calc.add("")
  }

  @Test
  public void oneNumber() {
    assert 1 == calc.add("1")
  }

  @Test
  public void anotherSingleNumber() {
    assert 2 == calc.add("2")
  }

  @Test
  public void twoNumbers() {
    assert 3 == calc.add("1,2")
  }

  @Test
  public void newLineDelimiter() {
    assert 3 == calc.add("1\n2")
  }

  @Test
  public void declareDelimiter() {
    assert 3 == calc.add("//;\n1;2")
  }

  @Test
  public void potentialReservedCharAsDelimiter() {
    assert 3 == calc.add("//*\n1*2")
  }

  @Test
  public void negativeNumber() {
    try {
      calc.add("-1")
      fail("Negative nbumbers should fail!")
    } catch (RuntimeException e) {
      assert "Negatives not allowed: [-1]" == e.getMessage()
    }
  }
 
  @Test
  public void negativeNumbers() {
    try {
      calc.add("-1,2,-3,4")
      fail("Negative nbumbers should fail!")
    } catch (RuntimeException e) {
      assert "Negatives not allowed: [-1, -3]" == e.getMessage()
    }
  }

}

class StringCalculator {
  def add(input) {
    if (! input) {
      return 0
    }

    def numbers = input.findAll("-?\\d+").collect{it.toInteger()}
    def negatives = numbers.grep{it < 0}
    if (negatives) {
      throw new RuntimeException("Negatives not allowed: $negatives")
    }

    numbers.sum()
    
  }
}
