#include <iostream>
#include "linebestfit.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

LineBestFit::LineBestFit(std::string fn) : StatsModel(fn) {} 

void LineBestFit::setCorrelation() {
  float sum;
  for (int i = 0; i < x.size(); i++) {
  sum = sum + ((x[i]-mean_x) / std_x) * ((y[i]-mean_y) / std_y);
  } 
  correlation = sum / (x.size() - 1);
} 

float LineBestFit::getCorrelation () {
  return correlation;
} 

float LineBestFit::getSlope() {
  return slope;
} 

float LineBestFit::getIntercept() {
  return intercept;
}
 
void LineBestFit::setIntercept() {
  setMeanX();
  setMeanY();
  intercept = mean_y - (slope * mean_x);
} 

void LineBestFit::setSlope () { 
  setMeanX();
  setMeanY();
  float denominator = 0.0;
  float top = 0.0;
 // std::cout << mean_x << " TEST " << mean_y << std::endl;
  for (int i = 0; i < x.size(); i++) {
  	denominator = denominator +  ((x[i]) * (x[i] - mean_x));
  }   
  for (int i = 0; i < x.size(); i++) {  
        top = top + (((x[i]) * (y[i] - mean_y)));
  } 
  slope = top / denominator;
  //std::cout << "top is " << top << "bottom is " << std::endl;
  //std::cout << denominator << std::endl;
  //std::cout << "slope is " << slope << std::endl;
}

 
