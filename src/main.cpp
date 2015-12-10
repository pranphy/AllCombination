/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/

#include<iostream>
#include<iomanip>
#include<vector>

#include "AllCombination.h"

using namespace std;
typedef  vector<unsigned>::const_iterator vci;
ostream& operator<<(ostream&,vector<unsigned>);

int main()
{
	vector<int> V; // = {'a','b','c','d','e','f','g','h','i','j'};
	for(unsigned i=0; i<9; i++)
		V.push_back(i);


	Combination C(9,5);
	C.SetElements(V);
	C.Reset();
	C.DisplayAll();

}

ostream& operator<<(ostream& st,vector<unsigned> Vect) {

	for(vci i = Vect.begin(); i!=Vect.end(); cout<<*i++);
	return st;
}
