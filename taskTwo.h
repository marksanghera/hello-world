#ifndef __TASK_TWO_H
#define __TASK_TWO_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Package {
    int idNumber;
    double weight;
    int width;
    int length;
    int height;
};
Package* loadPackages(ifstream& inFile, string* driverName, int* numPackages);
void computePackageStats(const Package* packages, const int numPackages, int* heaviestId, double* heaviestWeight, double* avgWeight);
void printPackagesInformation(const Package* packages, const string &driverName, const int &numPackages, const int heaviestId, const double heaviestWeight, const double avgWeight);


#endif