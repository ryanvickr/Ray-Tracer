#include "interval.h"

#include "util.h"

Interval::Interval() : min_(math_utils::INF), max_(-math_utils::INF) {}

Interval::Interval(const double min, const double max) : min_(min), max_(max) {}

const double& Interval::min() const { return min_; }

const double& Interval::max() const { return max_; }

double Interval::size() const {
    return max_ - min_;
}

bool Interval::contains(const double x) const {
    return x >= min_ && x <= max_;
}

bool Interval::surrounds(const double x) const {
    return x > min_ && x < max_;
}
