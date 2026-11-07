#pragma once
#include <random>

namespace Random {
	inline std::mt19937& get() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		return gen;
	}
}
