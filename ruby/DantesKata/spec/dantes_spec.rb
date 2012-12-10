require 'rspec'

describe "dante" do
  let(:seq) { (1..10) }

  describe "one number" do
    it "returns 1" do
      spn_dba((1..1)).should eq(1)
    end
  end

  describe "one and two" do
    it "returns 2" do
      spn_dba((1..2)).should eq(2)
    end
  end

  describe "one thru three" do
    it "returns 6" do
      spn_dba((1..3)).should eq(6)
    end
  end

  describe "one thru fo" do
    it "returns 12" do
      spn_dba((1..4)).should eq(12)
    end
  end

  describe "one thru five" do
    it "returns 60" do
      spn_dba((1..5)).should eq(60)
    end
  end

  describe "one thru six" do
    it "returns 60" do
      spn_dba((1..6)).should eq(60)
    end
  end

  describe "one thru seven" do
    it "returns 420" do
      spn_dba((1..7)).should eq(420)
    end
  end

  describe "one thru eight" do
    it "returns 840" do
      spn_dba((1..8)).should eq(840)
    end
  end

  describe "one thru nine" do
    it "returns 2520" do
      spn_dba((1..9)).should eq(2520)
    end
  end

  describe "one thru ten" do
    it "returns 2520" do
      spn_dba((1..10)).should eq(2520)
    end
  end

  describe "one thru twenty" do
    it "returns 232792560" do
      spn_dba((1..20)).should eq(232792560)
    end
  end

  def spn_dba(sequence)
    current = []
    sequence.each do |x|
      current.each do |i|
        if x % i == 0
          x/=i
        end
      end
      if x > 1
        current.push(x)
      end
    end
    current.reduce(1, :*)
  end
end
