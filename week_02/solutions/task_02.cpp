#include <iostream>

struct Interval {
    double left;
    double right;
};

Interval createInterval(double left, double right) {
    if (left > right)
        std::swap(left, right);

    return Interval{left, right};
}

bool contains(const Interval& interval, double value) {
    return value >= interval.left && value <= interval.right;
}

bool intersects(const Interval& a, const Interval& b) {
    return !(a.right < b.left || b.right < a.left);
}

bool intersection(const Interval& a, const Interval& b, Interval& result) {
    if (!intersects(a, b))
        return false;

    result.left = std::max(a.left, b.left);
    result.right = std::min(a.right, b.right);
    return true;
}

Interval* intersection(const Interval& a, const Interval& b) {

}