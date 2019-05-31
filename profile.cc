// TODO use more descriptive variable names
// TODO figure out logic for triangular motion profile
// TODO figure out logic for moving backwards

#include "profile.h"

const double Profile::GetTime() {
  
  bool ignore_maxv = true;
  double dx = goal_.position - current_.position;
  
  if (ignore_maxv) {
    double t = current_.velocity + sqrt(current_.velocity * current_.velocity) + (2*kMaxAcceleration*dx)/kMaxAcceleration;
    return t;
  } else {
    t1_ = (kMaxVelocity - current_.velocity) / kMaxAcceleration;
    t3_ = (kMaxVelocity - goal_.velocity) / kMaxAcceleration;
    
    d1_ = 1./2. * kMaxAcceleration * t1_;
    d3_ = 1./2. * kMaxAcceleration * t3_;
    
    d2_ = dx - d1_ - d3_;
    t2_ = d2_ / kMaxVelocity;
    
    tf_ = t1_ + t2_ + t3_;
    
    return tf_;
  }
  return 0.;
}
                                                                                  
Profile::ProfilePoint Profile::GetSetpoint(double t) {
  double c_velocity;
  double c_position;
  
  Profile::ProfilePoint status;
  
  if (t > t1_) {
    c_velocity = current_.velocity + (kMaxAcceleration * t);
    c_position = (c_velocity / 2.) * t;
    
    status.velocity = c_velocity;
    status.position = c_position;
    
  } else if (t1_ < t && t < t1_ + t2_) {
    c_velocity = kMaxVelocity;
    c_position = kMaxVelocity * t;
 
    status.velocity = c_velocity;
    status.position = c_position;
    
  } else if (t1_ + t2_ < t && t < tf_) {
    c_velocity = kMaxVelocity - (kMaxAcceleration * t);
    c_position = (c_velocity / 2.) * t;
    
    status.velocity = c_velocity;
    status.position = c_position;
  }
  
  return status;
}
