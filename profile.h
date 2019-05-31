#ifndef PROFILE_H_
#define PROFILE_H_

#include <cmath>

constexpr double kMaxVelocity = 1.;
constexpr double kMaxAcceleration = 1.;

class Profile {
 public:
  double t1_;
  double d1_;
  double d2_;
  double tf_;
	 
  struct ProfilePoint {
    double position = 0.;
    double velocity = 0.;
  };
  
  Profile(ProfilePoint current) {
    current_ = current;
  }
  
  void SetGoal(ProfilePoint goal) { goal_ = goal; }
  const double GetTime();

  Profile::ProfilePoint GetSetpoint(double t);

 private:
  ProfilePoint current_;
  ProfilePoint goal_;
};

#endif // PROFILE_H_
