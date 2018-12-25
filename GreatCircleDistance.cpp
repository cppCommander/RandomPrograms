#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    string Ls1;     //Latitude 1 sign

    string Lus1;    //longitude 1 sign

    string Ls2;     //Latitude 2 sign

    string Lus2;    //longitude 2 sign

	double L1 = 0;  //Latitude 1 value

    double Lu1 = 0; //longitude 1 sign

    double L2 = 0;  //Latitude 2 sign

    double Lu2 = 0; //longitude 2 sign

    cout << "Input latitude 1" << endl;
    cin >> Ls1;

    cout << "Input longitude 1" << endl;
    cin >> Lus1;

    cout << "Input latitude 2" << endl;
    cin >> Ls2;

    cout << "Input longitude  2" << endl;
    cin >> Lus2;

    cout << endl;

    string Ls11 = Ls1;
    string Lus11 = Lus1;
    string Ls22 = Ls2;
    string Lus22 = Lus2;

    if (Ls11.find('N') != std::string::npos || Ls1.find('n') != std::string::npos) {
        L1 = -(stod(Ls1));
    }
        else {
            L1 = stod(Ls1);
        }

    if (Lus11.find('E') != std::string::npos || Lus1.find('e') != std::string::npos) {
        Lu1 = -(stod(Lus1));
    }
        else {
            Lu1 = stod(Lus1);
        }

    if (Ls22.find('N') != std::string::npos || Ls2.find('n') != std::string::npos) {
        L2 = -(stod(Ls2));
    }
        else {
            L2 = stod(Ls2);
        }

    if (Lus22.find('E') != std::string::npos || Lus2.find('e') != std::string::npos) {
        Lu2 = -(stod(Lus2));
    }
        else {
            Lu2 = stod(Lus2);
        }


    L1 = L1 * 3.14159/180; // Converts degrees to radians
    Lu1 = Lu1 * 3.14159/180;
    L2 = L2 * 3.14159/180;
    Lu2 = Lu2 * 3.14159/180;

    double an = abs (Lu1 - Lu2); // Absolute difference of longitudes

    double b = acos (sin(L1) *  sin(L2) +  cos(L1) *  cos(L2) * cos(an));

    double d = 6371 * b;

    cout << "Distance on surface" << " " << d;


    return 0;

}

