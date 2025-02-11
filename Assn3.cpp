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
    cout << left << "Student ID: 9786405" << endl;
    cout << left << "Student Name: Zircon Jun Hao Teo" << endl;
    cout << left << "----------------------------------------------" << endl;
    cout << left << "Welcome to Assn3 Program!" << endl
         << endl;
    cout << left << "1)     Read in data" << endl;
    cout << left << "2)     Specify filtering criteria (current: " << filterCriteria << ")" << endl;
    cout << left << "3)     Specify sorting criteria (current: " << sortCriteria << ")" << endl;
    cout << left << "4)     Specify sorting order (current: " << sortingOrder << ")" << endl;
    cout << left << "5)     View data" << endl;
    cout << left << "6)     Store data" << endl;
    cout << left << "7)     Quit" << endl;

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
    case 2:
        filterData();
        break;
    case 3:
        sortData();
        break;
    case 4:
        sortDataOrder();
        break;
    /* case 5:
        viewData();
        break;
    case 6:
        storeData();
        break; */
    case 7:
        Point2DVec.clear();
        Point3DVec.clear();
        Line2DVec.clear();
        Line3DVec.clear();
        cout << "Quitting program" << endl;
        break;
    case 8:
        testPrint();
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
            string type = line.substr(0, line.find(',')); // get the type of data
            if (type == "Point2D")
            {
                line = line.substr(line.find('[') + 1); // leftover string after Point2D
                int x = stoi(line);                     // get x;
                line = line.substr(line.find(',') + 2); // leftover string after x and comma
                int y = stoi(line.substr(0, line.find(']')));
                // cout << x << " " << y << endl;
                Point2DVec.push_back(new Point2D(x, y));
            }
            else if (type == "Point3D")
            {

                line = line.substr(line.find('[') + 1);       // leftover string after Point3D
                int x = stoi(line);                           // get x;
                line = line.substr(line.find(',') + 2);       // leftover string after x and comma
                int y = stoi(line.substr(0, line.find(','))); // get y
                line = line.substr(line.find(',') + 2);       // leftover string after y and comma
                int z = stoi(line.substr(0, line.find(']'))); // get z
                // cout << x << " " << y << " " << z << endl;
                Point3DVec.push_back(new Point3D(x, y, z));
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
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                // Line2DVec.push_back(new Line2D(new Point2D(x1, y1), new Point2D(x2, y2)));
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
                // cout << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << endl;
                // Line3DVec.push_back(new Line3D(Point3D(x1, y1, z1), Point3D(x2, y2, z2)));
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

void testPrint()
{
    for (int i = 0; i < Point2DVec.size(); i++)
    {
        cout << *Point2DVec[i] << endl;
    }
    for (int i = 0; i < Point3DVec.size(); i++)
    {
        cout << *Point3DVec[i] << endl;
    }
    returnToMain();
}

void filterData()
{
    string input;
    cout << "[ Specifying filtering criteria (current: " << filterCriteria << ") ]" << endl
         << endl;
    cout << "   a)     Point2D" << endl;
    cout << "   b)     Point3D" << endl;
    cout << "   c)     Line2D" << endl;
    cout << "   d)     Line3D" << endl;
    cout << endl;
    cout << "Please enter your criteria (a - d): ";
    cin >> input;
    if (input == "a")
    {
        filterCriteria = "Point2D";
        sortCriteria = "x-coordinate"; // set default whenever filter criteria changes
        cout << "Filter criteria successfully set to 'Point2D'" << endl;
    }
    else if (input == "b")
    {
        filterCriteria = "Point3D";
        sortCriteria = "x-coordinate"; // set default whenever filter criteria changes
        cout << "Filter criteria successfully set to 'Point3D'" << endl;
    }
    else if (input == "c")
    {
        filterCriteria = "Line2D";
        sortCriteria = "pt.1"; // set default whenever filter criteria changes
        cout << "Filter criteria successfully set to 'Line2D'" << endl;
    }
    else if (input == "d")
    {
        filterCriteria = "Line3D";
        sortCriteria = "pt.1"; // set default whenever filter criteria changes
        cout << "Filter criteria successfully set to 'Line3D'" << endl;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        cin.clear();
        cin.ignore();
        filterData();
    }
    returnToMain();
}

void sortData()
{
    string input;
    if (filterCriteria == "Point2D")
    {
        cout << "[ Specifying sorting criteria (current: " << sortCriteria << ") ]" << endl
             << endl;
        cout << "   a)     x-coordinate" << endl;
        cout << "   b)     y-coordinate" << endl;
        cout << "   c)     distance from origin" << endl;
        cout << endl;
        cout << "Please enter your criteria (a - c): ";
        cin >> input;
        if (input == "a")
        {
            sortCriteria = "x-coordinate";
            cout << "Sorting criteria successfully set to 'x-coordinate'" << endl;
        }
        else if (input == "b")
        {
            sortCriteria = "y-coordinate";
            cout << "Sorting criteria successfully set to 'y-coordinate'" << endl;
        }
        else if (input == "c")
        {
            sortCriteria = "Length";
            cout << "Sorting criteria successfully set to 'distance from origin'" << endl;
        }
        else
        {
            cout << "Invalid input, please try again" << endl;
            cin.clear();
            cin.ignore();
            sortData();
        }
    }
    else if (filterCriteria == "Point3D")
    {
        cout << "[ Specifying sorting criteria (current: " << sortCriteria << ") ]" << endl
             << endl;
        cout << "   a)     x-coordinate" << endl;
        cout << "   b)     y-coordinate" << endl;
        cout << "   c)     z-coordinate" << endl;
        cout << "   d)     distance from origin" << endl;
        cout << endl;
        cout << "Please enter your criteria (a - d): ";
        cin >> input;
        if (input == "a")
        {
            sortCriteria = "x-coordinate";
            cout << "Sorting criteria successfully set to 'x-coordinate'" << endl;
        }
        else if (input == "b")
        {
            sortCriteria = "y-coordinate";
            cout << "Sorting criteria successfully set to 'y-coordinate'" << endl;
        }
        else if (input == "c")
        {
            sortCriteria = "z-coordinate";
            cout << "Sorting criteria successfully set to 'z-coordinate'" << endl;
        }
        else if (input == "d")
        {
            sortCriteria = "Length";
            cout << "Sorting criteria successfully set to 'distance from origin'" << endl;
        }
        else
        {
            cout << "Invalid input, please try again" << endl;
            cin.clear();
            cin.ignore();
            sortData();
        }
    }
    else if (filterCriteria == "Line2D" || filterCriteria == "Line3D")
    {
        cout << "[ Specifying sorting criteria (current: " << sortCriteria << ") ]" << endl
             << endl;
        cout << "   a)     Pt.1's (x, y) values" << endl;
        cout << "   b)     Pt.2's (x, y) values" << endl;
        cout << "   c)     Length" << endl;
        cout << endl;
        cout << "Please enter your criteria (a - c): ";
        cin >> input;
        if (input == "a")
        {
            sortCriteria = "Pt. 1";
            cout << "Sorting criteria successfully set to 'Pt.1's (x, y) values'" << endl;
        }
        else if (input == "b")
        {
            sortCriteria = "Pt. 2";
            cout << "Sorting criteria successfully set to 'Pt.2's (x, y) values'" << endl;
        }
        else if (input == "c")
        {
            sortCriteria = "Length";
            cout << "Sorting criteria successfully set to 'Length'" << endl;
        }
        else
        {
            cout << "Invalid input, please try again" << endl;
            cin.clear();
            cin.ignore();
            sortData();
        }
    }
    returnToMain();
}

void sortDataOrder()
{
    string input;
    cout << "[ Specifying sorting order (current: " << sortingOrder << ") ]" << endl
         << endl;
    cout << "   a)     ASC (Ascending order)" << endl;
    cout << "   b)     DSC (Descending order)" << endl;
    cout << endl;
    cout << "Please enter your criteria (a - b): ";
    cin >> input;
    if (input == "a")
    {
        sortingOrder = "ASC";
        cout << "Sorting order successfully set to 'Ascending'" << endl;
    }
    else if (input == "b")
    {
        sortingOrder = "DSC";
        cout << "Sorting order successfully set to 'Descending'" << endl;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        cin.clear();
        cin.ignore();
        sortDataOrder();
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