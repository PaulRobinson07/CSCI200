#ifndef RANDOM_H
#define RANDOM_H

#include <random>

//generates a random number generator to be available to all files
namespace Random {
	inline std::mt19937& get() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		return gen;
	}
}

#endif
