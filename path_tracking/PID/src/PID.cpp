#include "PID.h"

  PID::PID(double kp_, double ki_, double kd_, std::string type_): 
  kp(kp_), ki(ki_), kd(kd_), control_type(type_) {
    first_cte = true;
  }

  double PID::pid_cmd(double cte){
    if(first_cte){
      prev_cte = cte;
      sum_cte = 0.0;
      first_cte = false;
    }

    output = kp * cte + ki * sum_cte + kd * (cte - prev_cte);
    sum_cte += cte;
    prev_cte = cte;

    if(control_type == "steer"){
      output = output > 1 ? 1 : output;
      output = output < -1 ? -1 : output;
    }

    return output;
  }