#include "Vec2.hpp"

Vec2::Vec2() {
	Vec2::x = Vec2::y = 0;
}

Vec2::Vec2(float _x, float _y) {
	Vec2::x = _x;
	Vec2::y = _y;
}

Vec2 Vec2::operator+(Vec2 const& rhs) {
	return Vec2::Vec2(Vec2::x + rhs.x, Vec2::y + rhs.y);
}

Vec2& Vec2::operator+=(Vec2 const& rhs) {
	Vec2::x += rhs.x;
	Vec2::y += rhs.y;

	return *this;
}

Vec2 Vec2::operator*(float rhs) {
	return Vec2::Vec2(Vec2::x * rhs, Vec2::y * rhs);
}