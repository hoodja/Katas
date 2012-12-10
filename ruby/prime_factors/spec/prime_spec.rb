class PrimeFactors
  def prime_factors(n)
#    primes = []
#    (2..n).each do |candidate|
#      while n % candidate == 0
#         primes << candidate
#         n /= candidate
#      end
#    end
#    primes
#  end
     return [] if n == 1
     factor = (2..n).find { |x| n % x == 0 }
     [factor] + prime_factors(n / factor) # awesome sauce
  end
end

describe "prime factor kata" do
  let(:prime_factors) { PrimeFactors.new }
  it "give [] for 1" do
#    1.include(PrimeFactors).prime_factors.should == []
    prime_factors.prime_factors(1).should == []
  end

  it "give [2] for 2" do
    prime_factors.prime_factors(2).should == [2]
  end

  it "give [3] for 3" do
    prime_factors.prime_factors(3).should == [3]
  end

  it "give [2, 2] for 4" do
    prime_factors.prime_factors(4).should == [2, 2]
  end

  it "give [2, 3] for 6" do
    prime_factors.prime_factors(6).should == [2, 3]
  end

  it "give [2, 2, 2] for 8" do
    prime_factors.prime_factors(8).should == [2, 2, 2]
  end

  it "give [3, 3] for 9" do
    prime_factors.prime_factors(9).should == [3, 3] # wtf
  end

  it "give [3, 7] for 21" do
    prime_factors.prime_factors(21).should == [3, 7] # wtf
  end
end
