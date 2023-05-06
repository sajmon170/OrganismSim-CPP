#pragma once

#include <iostream>
#include <cstddef>

class Vector2 {
	int x;
	int y;

public:
	Vector2() = default;
	Vector2(int const& x_val, int const& y_val)
		: x(x_val), y(y_val) {}
	
	inline int getX() const {
		return x;
	}
	inline int getY() const {
		return y;
	}
	inline void setX(int const& val) {
		x = val;
	}	
	inline void setY(int const& val) {
		y = val;
	}

	int magnitude() const;
	bool between(Vector2 const& a, Vector2 const& b) const;

	friend bool operator==(Vector2 const&, Vector2 const&);
	friend bool operator!=(Vector2 const&, Vector2 const&);
	friend Vector2 operator+(Vector2 const&, Vector2 const&);
	friend Vector2& operator+=(Vector2&, Vector2 const&);
	friend Vector2 operator-(Vector2 const&);
	friend Vector2 operator-(Vector2 const&, Vector2 const&);
	friend Vector2& operator-=(Vector2&, Vector2 const&);
	friend Vector2 operator*(int const&, Vector2 const&); // multiply by scalar
	friend Vector2 operator/(Vector2 const&, int const&); // divide by scalar
	friend int operator*(Vector2 const&, Vector2 const&); // dot product
	friend int operator^(Vector2 const&, Vector2 const&); // cross product
	
	friend std::istream& operator>>(std::istream&, Vector2&); 
};

namespace std {
	template <>
	struct hash<Vector2> {
		std::size_t operator()(Vector2 const& vect) const {
			return hash<int>{}(vect.getX()) ^ hash<int>{}(vect.getY());
		}
	};
}
