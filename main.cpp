#include "linebestfit.h"
#include <iomanip>
#include <iostream>
#include <string>

int main() {

  std::string filename;
  std::cout << "Please enter the data file." << std::endl;
  std::getline(std::cin, filename);

  LineBestFit d = LineBestFit(filename);
  d.setSummaryStats();          // read data and calculate summary statistics: xbar, ybar, std_x, std_y
  d.setSlope();                 // calculate slope
  d.setIntercept();             // calculate intercept
  d.setCorrelation();           // calculate correlation


  std::cout << "The line of best fit\n"
            << "y = " << std::setprecision(4) << d.getIntercept()
            << " + " << std::setprecision(4) << d.getSlope() << "*x\n"
            << "accounts for " << std::setprecision(4) << d.getCorrelation()*d.getCorrelation()*100
            << " percent of the variation in the response variable, y."
            << std::endl;



  return 0;
}
