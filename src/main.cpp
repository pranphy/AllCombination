/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

#include "AllCombination.h"

using namespace std;
typedef  vector<unsigned>::const_iterator vci;
ostream& operator<<(ostream&,vector<unsigned>);

int main()
{
	// vector<char> V= {'a','b','c','d','e','f','g','h','i','j'};
    string Characters ="123456895@#$%^&*()"; vector<char> V; for(char i:Characters) V.push_back(i);
     //vector<char> V= {'@','b','c','d','e','f','g','h','i','j'};
	//for(unsigned i=0; i<9; i++)
	//	V.push_back(i);

    try{
        Combination C(6,3);
        C.SetElements(V);
        C.Reset();
        C.DisplayAll();
    }catch(string Error){
        cout<<Error<<endl;
    }
    try{
        CompleteCombi(6,3);
    }catch(string Error){
        cout<<Error<<endl;
    }

}

ostream& operator<<(ostream& st,vector<unsigned> Vect) {

	for(vci i = Vect.begin(); i!=Vect.end(); cout<<*i++);
	return st;
}
