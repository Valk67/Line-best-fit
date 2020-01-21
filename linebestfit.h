#ifndef LINEBESTFIT_H_
#define LINEBESTFIT_H_

#include "statsmodel.h"

class LineBestFit : public StatsModel {
public:
  LineBestFit(std::string fn);
  void setSlope();
  void setIntercept();
  void setCorrelation();
  float getSlope();
  float getIntercept();
  float getCorrelation();
  float intercept;
  float slope;
  float correlation;
};

#endif
