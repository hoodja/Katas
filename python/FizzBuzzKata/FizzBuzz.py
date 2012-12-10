#!/usr/bin/python

import unittest

class TestSequenceFunctions(unittest.TestCase):


    listOfNumbers = range(1, 101)

    def FizzBuzz(self, the_list):
      fizzbuzz = lambda x: 'FizzBuzz' if x % 3 == 0 and x % 5 == 0 else x
      fizz = lambda x: 'Fizz' if isinstance(x, int) and (x % 3 == 0 or str(x).find('3') >=0) else x
      buzz = lambda x: 'Buzz' if isinstance(x, int) and (x % 5 == 0 or str(x).find('5') >= 0) else x
      return [ buzz(fizz(fizzbuzz(num))) for num in the_list ]

    def Triple(self, the_list):
      result = []
      for x in range(3):
        for y in the_list:
          result.append(y)
        the_list.reverse()
      return result

    def test_numbers(self):
      self.assertEqual(self.listOfNumbers, range(1,101))

    def test_zero(self):
      self.assertEqual(self.FizzBuzz([0]), ["FizzBuzz"])

    def test_negative(self):
      self.assertEqual(self.FizzBuzz([-15]), ["FizzBuzz"])

    def test_fizz(self):
      self.assertEqual(self.FizzBuzz(self.listOfNumbers)[2], "Fizz")    

    def test_fives(self):
      self.assertEqual(self.FizzBuzz([1,5,10,11,14]), [1,"Buzz", "Buzz", 11, 14])

    def test_contains_3(self):
      self.assertEqual(self.FizzBuzz([1, 3, 4, 6, 11, 13]), [1, "Fizz", 4, "Fizz", 11, "Fizz"])

    def test_contains_5(self):
      self.assertEqual(self.FizzBuzz([1, 3, 4, 6, 11, 13, 53, 52]), [1, "Fizz", 4, "Fizz", 11, "Fizz", "Fizz", "Buzz" ])

    def test_fives_and_threes(self):
      self.assertEqual(self.FizzBuzz([15, 18, 20, 23, 52]), ["FizzBuzz", "Fizz", "Buzz", "Fizz", "Buzz"])

    def test_djs_crappy_end_requirement(self):
      self.assertEqual(self.Triple(self.FizzBuzz([15, 18, 20, 71])), ["FizzBuzz", "Fizz", "Buzz", 71, 71, "Buzz", "Fizz", "FizzBuzz", "FizzBuzz", "Fizz", "Buzz", 71])

if __name__ == '__main__':
    unittest.main()
