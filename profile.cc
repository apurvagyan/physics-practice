#include "profile.h"

const double Profile::GetTime(bool ignore_maxv) {
  if (ignore_maxv) {
    double dx = goal_.position - current_.position;
    double t = current_.velocity + sqrt(current_.velocity * current_.velocity) + (2(*(kMaxAcceleration)*(dx))/(kMaxAcceleration);
    return t;
  } else {
    t1 = (kMaxVelocity - current_.velocity) / kMaxAcceleration;
    d1 = 1/2 * (kMaxAcceleration) * t1;
    d2 = dx - (kMaxVelocity) * 2 * d1;
    tf = 2 * (t1 / kMaxAcceleration) + d2 / kMaxVelocity;
    return tf;
  } 
  return 0.0;                                                                
}
                                                                                  
ProfilePoint getSetpoint(double t) {
  double c_velocity;
  double c_position;
  ProfilePoint status;
  if (t > t1) {
    c_velocity = current_.velocity + (kMaxAcceleration * t);
    c_position = (c_velocity / 2) * t;
    
    status.velocity = c_velocity;
    status.position - c_position;
    
  } elif (t1 < t > t1 + t2) {
    c_velocity = kMaxVelocity;
    c_position = kMaxVelocity * t;
    
    status.velocity = c_velocity;
    status.position - c_position;
    
  } elif (t1+ t2 < t < tf) {
    c_velocity = kMaxVelocity - (kMaxAcceleration * t);
    c_position = (c_velocity / 2) * t;
    
    status.velocity = c_velocity;
    status.position - c_position;
  }
  
  return status;
}
