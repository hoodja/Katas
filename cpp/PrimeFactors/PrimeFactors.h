#ifndef PRIMEFACTORS_H_
#define PRIMEFACTORS_H_
#include <vector>

class PrimeFactors {
public:
	static std::vector<int> generate(int n) {
		std::vector<int> result;

		for (int candidate = 2; n > 1; candidate++)
			for (; n % candidate == 0; n /= candidate)
				result.push_back(candidate);

		return result;
	}
};

#endif /* PRIMEFACTORS_H_ */
