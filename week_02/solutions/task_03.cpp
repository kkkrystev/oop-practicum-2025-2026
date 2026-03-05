#include <cmath>

const double PI = 3.141592653589793;

struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

double area(const Circle& circle) {
    return PI * circle.radius * circle.radius;
}

double perimeter(const Circle& circle) {
    const double PI = 3.141592653589793;
    return 2 * PI * circle.radius;
}

bool contains(const Circle& circle, const Point& point) {
    double dx = point.x - circle.center.x;
    double dy = point.y - circle.center.y;

    double distanceToCenter = std::sqrt(dx * dx + dy * dy);
    return distanceToCenter <= circle.radius;
}