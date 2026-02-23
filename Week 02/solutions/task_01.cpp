#include <cmath>

enum class Quadrant {
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	X_AXIS,
	Y_AXIS
};

struct Point {
	double x, y;
};

double distance(const Point& p1, const Point& p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

Quadrant getQuadrant(const Point& p) {
	if (p.x == 0)
		return Quadrant::X_AXIS;
	if (p.y == 0)
		return Quadrant::Y_AXIS;
	if (p.x > 0 && p.y > 0) 
		return Quadrant::FIRST;
	if (p.x < 0 && p.y > 0) 
		return Quadrant::SECOND;
	if (p.x < 0 && p.y < 0) 
		return Quadrant::THIRD;
	return Quadrant::FOURTH;
}

bool areInSameQuadrant(const Point& p1, const Point& p2) {
	return getQuadrant(p1) == getQuadrant(p2);
}
