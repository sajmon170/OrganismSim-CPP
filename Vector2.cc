#include "Vector2.hh"

inline int sqr(const int& x) {
	return x * x;
}

int Vector2::magnitude() const {
	return sqr(x) + sqr(y);
}

bool Vector2::between(Vector2 const& a, Vector2 const& b) const {
	return x >= a.x && y >= a.y
		&& x <= b.x && y <= b.y;
}

bool operator==(Vector2 const& a, Vector2 const& b) {
	return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(Vector2 const& a, Vector2 const& b) {
	return !(a == b);
}

Vector2 operator+(Vector2 const& a, Vector2 const& b) {
	return Vector2{a.x + b.x, a.y + b.y};
}

Vector2& operator+=(Vector2& a, Vector2 const& b) {
	return a = a + b;
}

Vector2 operator-(Vector2 const& a) {
	return Vector2{-a.x, -a.y};
}

Vector2 operator-(Vector2 const& a, Vector2 const& b) {
	return a + (-b);
}

Vector2& operator-=(Vector2& a, Vector2 const& b) {
	return a = a - b;
}

Vector2 operator*(const int& t, Vector2 const& a) {
	return Vector2{t*a.x, t*a.y};
}

Vector2 operator/(Vector2 const& a, const int& t) {
	return Vector2{a.x/t, a.y/t};
}

int operator*(Vector2 const& a, Vector2 const& b) {
	return a.x*b.x + a.y*b.y;
}

int operator^(Vector2 const& a, Vector2 const& b) {
	return a.x*b.y - a.y*b.x;
}

std::istream& operator>>(std::istream& in, Vector2& v) {
	in >> v.x;
	in >> v.y;
	return in;
}
