#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

#include "Point2D.h"     // Point2D class
#include "Point3D.h"     // Point3D class
#include "Line2D.h"      // Line2D class
#include "Line3D.h"      // Line3D class
#include "MyTemplates.h" // template function file

using namespace std;

string filterCriteria = "Point2D";
string sortCriteria = "x-coordinate";
string sortingOrder = "ASC";
string fileOutputString;

void printStartPage();
void userStartInput();
void returnToMain();
void inputData();
void filterData();
void sortData();
void sortDataOrder();
void viewData();
void storeData();
void quitProgram();