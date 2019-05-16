#include "profile.h"

const double Profile::GetTime(bool ignore_maxv) {
  if (ignore_maxv) {
    double dx = goal_.position - current_.position;
    double t = current_.velocity + sqrt(current_.velocity * current_.velocity) + (2(*(kMaxAcceleration)*(dx))/(kMaxAcceleration);
    return t;

  else {
    t1 = (kMaxVelocity - current_.position) / kMaxAcceleration;
    d1 = 1/2 * (kMaxAcceleration) * (kMaxVelocity - current_.velocity) / (kMaxAcceleration);
    d2 = dx - (kMaxVelocity) * 2*d1;

    tf = 2 * (t1 / kMaxAcceleration) + d2 / kMaxVelocity;
    return tf;

  return 0.0;
}
