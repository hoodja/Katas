package primefactors;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import org.junit.Test;

import java.util.List;
import java.util.ArrayList;

public class PrimeFactorsTest {

  public static class PrimeFactors {
    public static List<Integer> generate(int n) {
      List<Integer> primes = new ArrayList<Integer>();
      int candidate = 2;
      while (n > 1) {
        while (n % candidate == 0) {
          primes.add(candidate);
          n /= candidate;
        }
        candidate++;
      }
      return primes;
    }
  }

  @Test
  public void testOne() {
    assertThat(PrimeFactors.generate(1), is(list()));
  }

  @Test
  public void testTwo() {
    assertThat(PrimeFactors.generate(2), is(list(2)));
  }

  @Test
  public void testThree() {
    assertThat(PrimeFactors.generate(3), is(list(3)));
  }

  @Test
  public void testFour() {
    assertThat(PrimeFactors.generate(4), is(list(2, 2)));
  }

  @Test
  public void testSix() {
    assertThat(PrimeFactors.generate(6), is(list(2, 3)));
  }

  @Test
  public void testEight() {
    assertThat(PrimeFactors.generate(8), is(list(2, 2, 2)));
  }

  @Test
  public void testNine() {
    assertThat(PrimeFactors.generate(9), is(list(3,3)));
  }

  public List<Integer> list(int... ints) {
    List<Integer> list = new ArrayList<Integer>();
    for (int i : ints) {
      list.add(i);
    }
    return list;
  }

}
