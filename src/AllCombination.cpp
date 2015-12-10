/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/


#include "AllCombination.h"

/*
	The following function is designed to  generate all the possible combinations
	of contained in the vector Elements, taken r at a time. It works only if the
	value of n when divided by r leaves no  remainder  because the value n-k*r,k
	integer,must be r. First it generates a combination C(n,r) and then from the
	remaining elements except those r's already chosen C(n-r,r) and so on  up to
	C(r,r) . For all C(n,r) it attaches C(n-r,r) and generates a new combination
	equaling C(n,r)*C(n-r,r) combinations, and then continues until it generates
	the total of C(n,r)*C(n-r,r)*C(n-2*r)*... *C(r,r). It can be used to generate
	all combination for the game kitty.

*/
void CompleteCombi(vector<unsigned>&Elements,unsigned n,unsigned r) {

	if((n % r) != 0)
		exit(1);
	else {
		if(Elements.size() < n) exit(1);
		vector<vector<vector<unsigned>>> SuperCombination;
		for(unsigned i=0; i<n/r; i++) {
			Combination Current(n-i*r,r);
			SuperCombination.push_back(Current.GetAll());
		}

		unsigned Pass = 0,TotalLines = 1,Lines;
		for(auto AllCombination : SuperCombination) {
			ifstream OutputFile("Combination.dat");
			ofstream TemporaryFile("Temp.dat");

			for(Lines = TotalLines; Lines--;) {
				vector<unsigned> Current;
				unsigned Value;
				Current.reserve(Pass * r);
				for(unsigned Cell = 0; Cell < Pass * r; Cell++) {
					OutputFile>>Value;
					Current.push_back(Value);
				}
				auto Trimmed = Trim(Elements,Current);
				for(auto CurrentCombination : AllCombination) {
					for(unsigned i:Current)
						TemporaryFile<<i<<" ";
					for(unsigned i: CurrentCombination)
						TemporaryFile<<Trimmed[i]<<" ";
					TemporaryFile<<endl;
				}
			}
			Pass++;
			TotalLines *= AllCombination.size();
			OutputFile.close();
			TemporaryFile.close();
			remove("Combination.dat");
			rename("Temp.dat","Combination.dat");
		}
	}

}

/*
	It should be straightforward  from the name,  that this function
	Returns a vector with the elements of From but not in Remove,i.e,
	It trims out all the elements of Remove from From. If the element
	repeats in From vector and is contained in Remove vector then no
	instance of element will be in the returned vector.
*/
vector<unsigned> Trim(vector<unsigned>& From,vector<unsigned>& Remove) {
	vector<unsigned> Trimmed;
	Trimmed.reserve(From.size()-Remove.size());
	for(unsigned i:From) {
		if(find(Remove.begin(),Remove.end(),i) == Remove.end())
			Trimmed.push_back(i);
	}
	return Trimmed;
}

/*
	DisplayIt Function for internal checking purpose only
*/

void DisplayIt(vector<unsigned>& V) {
	for(unsigned i:V)
		cout<<i;
}
