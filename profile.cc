#include "profile.h"

const double Profile::GetTime(bool ignore_maxv) {
  if (ignore_maxv) {
    double dx = goal_.position - current_.position;
    double t = current_.velocity + sqrt(current_.velocity * current_.velocity) + (2(*(kMaxAcceleration)*(dx))/(kMaxAcceleration);

  else {
    t1 = (kMaxVelocity - current_.position) / kMaxAcceleration;
    d1 = 
  
  
  
  
  
  
  
  
  return 0.0;
}
