#ifndef STATSMODEL_H_
#define STATSMODEL_H_

#include <string>
#include <vector>

class StatsModel {
 public:
  StatsModel(std::string fn);
  std::string data_file;
  void setXY();
  std::vector<float> x;
  std::vector<float> y;
  void setMeanX();
  void setMeanY();
  void setStdX();
  void setStdY();
  void setSummaryStats();
  float getMeanX();
  float getMeanY();
  float getStdX();
  float getStdY();
  float mean_x;
  float mean_y;
  float std_x;
  float std_y;
};

#endif
