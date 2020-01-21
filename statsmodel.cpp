#include "statsmodel.h"
#include <string>
#include <vector>
#include <iostream> 
#include <fstream> 
#include <sstream>
#include <cmath>

StatsModel::StatsModel (std::string fn) : data_file(fn) {
  setXY();
}  

void StatsModel::setSummaryStats() {
  setMeanX();
  setMeanY();
  setStdX();
  setStdY();
} 

void StatsModel::setStdX () {
  float sum = 0.0;
  for (int i = 0; i < x.size(); i++) {
  sum = sum + ((x[i] - mean_x) * (x[i] - mean_x));
  } 
  std_x = sqrt(sum/(x.size() - 1));
//std::cout << "std_x = " << std_x << std::endl;

} 

void StatsModel::setStdY () {
  float sum = 0.0;
  for (int i = 0; i < y.size(); i++) {
  sum = sum + ((y[i] - mean_y) * (y[i] - mean_y));
  } 
  std_y = sqrt(sum/(y.size() -1));
//std::cout << "std_y = " << std_y << std::endl;
} 

float StatsModel::getStdX () {
  return std_x;
} 

float StatsModel::getStdY () {
  return std_y;
} 

void StatsModel::setMeanX() {
  float sum = 0.0;
  for (int i = 0; i < x.size(); i++) {
  sum = sum + x[i];
  }
  mean_x = sum / x.size();
//std::cout << "meanx " <<  mean_x << std::endl;
}

void StatsModel::setMeanY() {
  float sum = 0.0;
  for (int i = 0; i < y.size(); i++) {
  sum = sum + y[i];
  }
  mean_y = sum / y.size();
//std::cout << "meany "<<  mean_y << std::endl;
}

float StatsModel::getMeanX() {
  return mean_x;
}

float StatsModel::getMeanY() {
  return mean_y;
}

void StatsModel::setXY () {
  std::ifstream inf;
  inf.open(data_file);
  if (!inf.is_open()) {
    std::cout << "file issue" << std::endl;
  }
  std::string line;
  char comma;
  float tmp_weight;
  float tmp_mpg;
  std::vector <StatsModel> l;
    while (std::getline(inf, line)) {
    std::istringstream ss(line);
    ss >> tmp_weight >> comma >> tmp_mpg;
        //std::cout << tmp_weight << std::endl;
//std::cout << tmp_mpg << std::endl;
    x.push_back(tmp_weight);// * 1000);
    y.push_back(tmp_mpg);
    //std::cout << tmp_weight << " " << tmp_mpg << std::endl;
    }
}

