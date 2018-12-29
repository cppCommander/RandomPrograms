#include <iostream>
#include <vector>


using namespace std;

void print(const string& label, const vector<int>& v){
    cout << label << " ";
    for(auto a : v)
    cout << a << " ";
}

void fibonacci(int x,int y,vector<int>& v,int n)
{
    v.push_back(x);
    v.push_back(y);
    for(int i = 1; i < n; ++i){
        v.push_back(v[i] + v[i-1]);
    }
}

int main()
{
    int x = 1;
    int y = 1;
    int n = 30;
    string label = "Fibonacci sequence";
    vector<int> v;
    fibonacci(x, y, v, n);
    print(label, v);
}
