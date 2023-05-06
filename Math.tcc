Vector2 Math::randomPos(int radius) {
	double angle = 2 * randomFloat(0, 1) * Math::PI;
	double r = randomFloat(0, radius);
	int x = (int)(r * cos(angle));
	int y = (int)(r * sin(angle));
	
	return Vector2(x, y);
}

template <typename T>
void Math::swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = a;
}

int Math::random(int beg, int end) {
	static std::default_random_engine e(time(0));
	std::uniform_int_distribution<int> dist(beg, end);

	return dist(e);
}

float Math::randomFloat(float beg, float end) {
	static std::default_random_engine e(time(0));
	std::uniform_real_distribution<float> dist(beg, end);

	return dist(e);
}

template <typename T>
auto Math::pickRandom(T const& container) {
	return container[random(0, container.size()-1)];
}

bool Math::chance(double percentage) {
	return (random(0, 99) < percentage*100);
}

std::vector<int> Math::clamp(const std::vector<int>& vect, int lo, int hi) {
	std::vector<int> v;
	for (auto& i: vect)
		if (i >= lo && i <= hi)
			v.push_back(i);

	return v;
}

std::vector<int> Math::range(int beg, int end) {
	std::vector<int> result;
	for (int i=beg; i<=end; i++)
		result.push_back(i);

	return result;
}

template <typename Container, typename Predicate>
Container& Math::filter(Container& container, Predicate const& predicate) {
	container.erase(std::remove_if(container.begin(), container.end(), predicate),
	                container.end());

	return container;
}

template <typename Container, typename Predicate>
Container Math::filter(Container&& container, Predicate const& predicate) {
	container.erase(std::remove_if(container.begin(), container.end(), predicate),
	                container.end());

	return container;
}

template <typename Container, typename Value>
Container& Math::remove(Container& container, Value const& value) {
	container.erase(std::remove(container.begin(), container.end(), value),
	                container.end());

	return container;
}

template <typename Container, typename Function>
Container& Math::map(Container& container, Function function) {
	for (auto& element: container)
		element = function(element);

	return container;
}

template <typename Container, typename Function>
Container Math::map(Container&& container, Function function) {
	for (auto& element: container)
		element = function(element);

	return container;
}
