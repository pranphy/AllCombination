#ifndef ALLCOMBINATION_H_INCLUDED
#define ALLCOMBINATION_H_INCLUDED

#include <iostream>
#include <sstream>
#include <vector>

#include "Combination.h"
using namespace std;


vector<unsigned> Trim(vector<unsigned>&,vector<unsigned>&);
void DisplayIt(vector<unsigned>&);
void CompleteCombi(unsigned n,unsigned r,vector<unsigned> = {});


#endif // ALLCOMBINATION_H_INCLUDED
