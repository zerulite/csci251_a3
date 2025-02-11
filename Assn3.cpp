#include "Assn3.h"

using namespace std;

// to store points and lines
vector<Point2D *> Point2DVec{};
vector<Point3D *> Point3DVec{};
vector<Line2D *> Line2DVec{};
vector<Line3D *> Line3DVec{};

// prints start page
void printStartPage()
{
    cout << setw(50) << left << "Student ID: 9786405" << endl;
    cout << setw(50) << left << "Student Name: Zircon Jun Hao Teo" << endl;
    cout << setw(50) << left << "----------------------------------------------" << endl;
    cout << setw(50) << left << "Welcome to Assn3 Program!" << endl
         << endl;
    cout << setw(50) << left << "1)     Read in data" << endl;
    cout << setw(50) << left << "2)     Specify filtering criteria (current:" << endl;
    cout << setw(50) << left << "3)     Specify sorting criteria (current:" << endl;
    cout << setw(50) << left << "4)     Specify sorting order (current:" << endl;
    cout << setw(50) << left << "5)     View data" << endl;
    cout << setw(50) << left << "6)     Store data" << endl;
    cout << setw(50) << left << "7)     Quit" << endl;

    userStartInput(); // call for user input
}

// for user input, uses a switch case to see which option the user has chosen
void userStartInput()
{
    int input = 0;
    cout << "Please enter your choice: ";
    cin >> input;
    switch (input)
    {
    case 1:
        inputData();
        break;
        /*    case 2:
               filterData();
               break;
           case 3:
               sortData();
               break;
           case 4:
               sortDataOrder();
               break;
           case 5:
               viewData();
               break;
           case 6:
               storeData();
               break; */
    case 7:
        cout << "Quitting program" << endl;
        Point2DVec.clear();
        Point3DVec.clear();
        Line2DVec.clear();
        Line3DVec.clear();
        break;
    default:
        cout << "Invalid input, please try again" << endl;
        cin.clear();
        cin.ignore();
        printStartPage(); // recursive call to print start page again if invalid input
        break;
    }
}

void inputData()
{
    string fileName;
    cout << "Please enter filename: ";
    cin >> fileName;

    string line;         // temp variable to store each line of the file
    ifstream configFile; // input file stream var
    configFile.open(fileName.c_str());

    if (configFile.is_open())
    {
        while (getline(configFile, line))
        {
            // cout << line.substr(0, line.find(',')) << endl; // this shows data to the left

            string type = line.substr(0, line.find(',')); // get the type of data
            if (type == "Point2D")
            {
                line = line.substr(line.find('[') + 1); // leftover string after Point2D
                int x = stoi(line);                     // get x;
                line = line.substr(line.find(',') + 2); // leftover string after x and comma
                int y = stoi(line.substr(0, line.find(']')));
                cout << x << " " << y << endl;
            }
            else if (type == "Point3D")
            {

                line = line.substr(line.find('[') + 1);       // leftover string after Point3D
                int x = stoi(line);                           // get x;
                line = line.substr(line.find(',') + 2);       // leftover string after x and comma
                int y = stoi(line.substr(0, line.find(','))); // get y
                line = line.substr(line.find(',') + 2);       // leftover string after y and comma
                int z = stoi(line.substr(0, line.find(']'))); // get z
                cout << x << " " << y << " " << z << endl;
            }
            else if (type == "Line2D")
            {
                line = line.substr(line.find('[') + 1); // leftover string after Line2D
                int x1 = stoi(line);                    // get x1;
                line = line.substr(line.find(',') + 2); // leftover string after x1 and comma
                int y1 = stoi(line.substr(0, line.find(']')));
                line = line.substr(line.find('[') + 1);        // leftover string after y1 and comma
                int x2 = stoi(line.substr(0, line.find(','))); // get x2
                line = line.substr(line.find(',') + 2);        // leftover string after x2 and comma
                int y2 = stoi(line.substr(0, line.find(']'))); // get y2
                cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            }
            else if (type == "Line3D")
            {
                line = line.substr(line.find('[') + 1);        // leftover string after Line3D
                int x1 = stoi(line);                           // get x1;
                line = line.substr(line.find(',') + 2);        // leftover string after x1 and comma
                int y1 = stoi(line.substr(0, line.find(','))); // get y1
                line = line.substr(line.find(',') + 2);        // leftover string after y1 and comma
                int z1 = stoi(line.substr(0, line.find(']'))); // get z1

                line = line.substr(line.find('[') + 1);        // leftover string after z1 and comma
                int x2 = stoi(line.substr(0, line.find(','))); // get x2
                line = line.substr(line.find(',') + 2);        // leftover string after x2 and comma
                int y2 = stoi(line.substr(0, line.find(','))); // get y2
                line = line.substr(line.find(',') + 2);        // leftover string after y2 and comma
                int z2 = stoi(line.substr(0, line.find(']'))); // get z2
                cout << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << endl;
            }
        }
        configFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    returnToMain();
}

void returnToMain()
{
    cout << "Press <enter> to go back to main menu...";
    cin.ignore();
    cin.get();
    cout << endl;
    printStartPage();
}

int main()
{
    printStartPage();
}