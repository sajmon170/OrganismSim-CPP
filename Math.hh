#pragma once

#include "Vector2.hh"

#include <cmath>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <utility>

namespace Math {
	static const double PI = 3.14159265358979323846;

	inline Vector2 randomPos(int radius);

	template <typename T>
	void swap(T& a, T& b);
	
	inline int random(int beg, int end);

	inline float randomFloat(float beg, float end);

	template <typename T>
	auto pickRandom(T const& container);
	
	inline bool chance(double percentage);

	inline std::vector<int> clamp(std::vector<int> const& v, int lo, int hi);
	inline std::vector<int> range(int beg, int end);
	
	template <typename Container, typename Predicate>
	Container& filter(Container&, Predicate const&);

	template <typename Container, typename Predicate>
	Container filter(Container&&, Predicate const&);
	
	template <typename Container, typename Value>
	Container& remove(Container&, Value const&);

	template <typename Container, typename Function>
	Container& map(Container&, Function);

	template <typename Container, typename Function>
	Container map(Container&&, Function);
}

#include "Math.tcc"
