#ifndef PID_H
#define PID_H

#include <string>

class PID {
public:
  PID(double kp_, double ki_, double kd_, std::string type_);
  ~PID() {}

  double pid_cmd(double cte);

protected:
  double kp;
  double ki;
  double kd;

  double prev_cte;
  double sum_cte;
  double output;

  bool first_cte;

  std::string control_type;
};

#endif  // PID_H