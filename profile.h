#ifndef PROFILE_H_
#define PROFILE_H_

class Profile {
public:
  struct ProfilePoint {
    double position = 0.0;
    double velocity = 0.0;
  };
  Profile(ProfilePoint current) {
    current_ = current;
  }
  void SetGoal(ProfilePoint goal) { goal_ = goal; }
  const double GetTime();

private:
  ProfilePoint current_;
  ProfilePoint goal_;
};

#endif // PROFILE_H_
