#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
#include "taskTwo.h"

using namespace std;
/**
 * Name: Mark Sanghera
 * Class: CPSC 122, Spring 2023
 * Date: February 26, 2023
 * Programming Assignment: PA4                                   
 * Description: This file reads and writes the package information of a truck load 
 * Notes:
**/

Package* loadPackages(ifstream& inFile, string* driverName, int* numPackages) {
    string nameOfDriver;
    string line;
    int count = 0;
    vector<Package*> packages;
    Package* currentPackage;

    getline(inFile, nameOfDriver);
    *driverName = nameOfDriver;

    while(!inFile.eof()) {
        getline(inFile, line);
        if(line.size() == 0) {
            continue;
        }
        switch(count) {
            case 0:
                // ID
                currentPackage = new Package;
                packages.push_back(currentPackage);
                currentPackage->idNumber = stoi(line);
                break;
            case 1:
                // weight
                currentPackage->weight = stod(line);
                break;
            case 2: 
                // width
                currentPackage->width = stoi(line);
                break;
            case 3: 
                // length
                currentPackage->length = stoi(line);
                break;
            case 4: 
                // height
                currentPackage->height = stoi(line);
                break;
        }
        count = ++count % 5;
    }
    *numPackages = packages.size();
    Package* ptrToPackages = new Package[packages.size()];
    for(int i = 0; i < packages.size(); i++) {
        ptrToPackages[i].idNumber = packages[i]->idNumber;
        ptrToPackages[i].weight = packages[i]->weight;
        ptrToPackages[i].width = packages[i]->width;
        ptrToPackages[i].length = packages[i]->length;
        ptrToPackages[i].height = packages[i]->height;
        delete packages[i];
    }

    return ptrToPackages;
}

void computePackageStats(const Package* packages, const int numPackages, int* heaviestId, double* heaviestWeight, double* avgWeight) {
    int currentMaxIndex = 0;
    double sum = 0;
    for(int i = 0; i < numPackages; i++) {
        if(currentMaxIndex < 0 || packages[currentMaxIndex].weight < packages[i].weight){
                currentMaxIndex = i;
        }
        sum += packages[i].weight;
    }
    
    *heaviestId = packages[currentMaxIndex].idNumber;
    *heaviestWeight = packages[currentMaxIndex].weight;
    *avgWeight = sum / numPackages;
}

void printPackagesInformation(const Package* packages, const string &driverName, const int &numPackages, const int heaviestId, const double heaviestWeight, const double avgWeight) {
    cout << "This is the driver Name: " << driverName << endl
        << "Number of packages in truck: " << numPackages << endl;
    
    for(int i = 0; i < numPackages; i++) {
        cout << "Package ID: " << packages[i].idNumber << " Package weight: " << packages[i].weight << " Package width: " << packages[i].width 
            << " Package length: " << packages[i].length << " Package height: " << packages[i].height << endl;
    }
    cout << "Heaviest ID: " << heaviestId << " Heaviest Weight: " << heaviestWeight << " Average Weigth: " << avgWeight << endl;
}