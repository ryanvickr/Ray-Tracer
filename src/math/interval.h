#ifndef MATH_INTERVAL_H
#define MATH_INTERVAL_H

class Interval {
 public:
  Interval();

  Interval(const double min, const double max);

  const double& min() const;

  const double& max() const;

  double size() const;

  bool contains(const double x) const;

  bool surrounds(const double x) const;

 private:
  const double min_;
  const double max_;
};

#endif  // MATH_INTERVAL_H
