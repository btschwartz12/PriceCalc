//
//  main.cpp
//  PriceComputer
//
//  Created by Ben Schwartz on 2/22/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "exprtk.hpp"

using namespace std;



int main(int argc, const char * argv[]) {

    
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;
    
    ifstream is("costs.in.txt");
    if (argc > 1 || is.fail()) {
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
    
        parser.compile(s, expression);
        cost[i] = expression.value();
    }
    
    double subtotal = 0;
    for (double val: cost)
        subtotal += val;
    is >> s;
    double total = stod(s);
    vector<double> paid(people);
    cout << "***\n***\n";
    for(int i = 0; i < people; i++) {
        paid[i] = cost[i] / subtotal * total;
        cout << names[i] << " owes " << setprecision(4) << paid[i] << endl;
    }
    cout << "***\n***\n";
    
    return 0;
    
}
