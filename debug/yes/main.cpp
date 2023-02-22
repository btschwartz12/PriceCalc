//
//  main.cpp
//  PriceComputer
//
//  Created by Ben Schwartz on 2/22/21.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream is("/Users/benschwartz/college_dev/calc/costs.in");
    if (argc != 1 || is.fail()) {
        cout << "USAGE: \"./main\" MAKE SURE cost.in IS FORMATTED CORRECTLY" << endl;
        return -1;
    }
    string s;
    is >> s;
    int people = stoi(s);
    vector<string> names(people);
    vector<double> cost(people);
    
    for(int i = 0; i < people; i++) {
        is >> s;
        names[i] = s;
        is >> s;
        double d = stod(s);
        cost[i] = d;
    }
    
    is >> s;
    double subtotal = stod(s);
    is >> s;
    double total = stod(s);
    vector<double> paid(people);
    cout << "***\n***\n";
    for(int i = 0; i < people; i++) {
        paid[i] = cost[i] / subtotal * total;
        cout << names[i] << " owes " << setprecision(4) << paid[i] << endl;
    }
    cout << "***\n***";
    return 0;
    
}
