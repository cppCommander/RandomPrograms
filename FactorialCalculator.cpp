#include <iostream>
#include <iomanip>


using namespace std;

int main(){
    int number = 0;
    double sum = 1;

    cout << "Factorial calculator" << endl;

    while (cin >> number){

        for (int x = 1; x < number + 1; ++x){

        sum *= x;

        }

    std::cout << " = " << std::setprecision(100) << sum5 << endl;

    }
}
