#include <iostream>
#include <fstream>
#include <array>
#include "taskTwo.h"

using namespace std;

/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file is the driver for PA4 
 * Notes:
**/

int main(int argc, char *argv[]) {
    ifstream inputStream;
    string driverName;
    int numPackages = 0;
    Package* packages = NULL;
    int heaviestId = 0;
    double heaviestWeight = 0;
    double avgWeight = 0;
    // remove the name of the program from the arguments
    argc--;
    argv++;

    if(argc < 1) {
        cerr << "Missing truck manifest argument" << endl;
        exit(1);
    }
    cout << "Truck manifest: " << argv[0] << endl;

    inputStream.open(argv[0]);
    if(inputStream.is_open()) {
        packages = loadPackages(inputStream, &driverName, &numPackages);
        computePackageStats(packages, numPackages, &heaviestId, &heaviestWeight, &avgWeight);
        printPackagesInformation(packages, driverName, numPackages, heaviestId, heaviestWeight, avgWeight);


        // FINAL STEP: Delete dynamic allocated memory and close input stream
        delete[] packages;
        inputStream.close();
    }
    else {
        cerr << "Input File name: " << argv[0] << " is invalid." << endl;
    }
    return 0;
}