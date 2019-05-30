#include "profile.h"
#include <iostream>

int main() {
  Profile::ProfilePoint current;
  Profile::ProfilePoint goal;
  {
    goal.position = 1.;
    goal.velocity = 0.;
  }
  Profile profile(current);
  profile.SetGoal(goal);
  double time = profile.GetTime();
  for (int i = 0; i <= int(time / .01); i++) {
    std::cout << i * .01 << "," << profile.GetSetpoint(time) << std::endl;
  }
}
