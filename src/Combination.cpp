/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/

#include "Combination.h"

Combination::Combination(int Yan,int Are):n(Yan),r(Are) {
	Elements.reserve(n);
	Chosen.reserve(r);
	Generated = false;
	if(r>n) //this is a mathematical error
		throw 4;
	EndReached = false;
	for(unsigned i=0; i<n; Elements.push_back(i++));
	for(unsigned i=0; i<r; Chosen.push_back(i++));
	MakeAll();
}

void Combination::SetElements(vector<int> ReceivedElements) {
	for(unsigned i=0; i<n; i++)
		Elements[i] = ReceivedElements[i];

}

void Combination::DisplayAll(void) {
	int p=1;
	for(auto v: AllCombi) {
		cout<<p++<<".  ";
		DisplayIt(v);
		cout<<endl;
	}
}

void Combination::MakeAll() {
	if(!Generated) {
		Reset();
		AllCombi.push_back(GetCurrent());
		while(!EndStatus())
			AllCombi.push_back(Next());
		Generated = true;
	}
}

vector<vector<unsigned>> Combination::GetAll() {
	return AllCombi;
}

vector<unsigned> Combination::Next() {
	unsigned k = r-1;
	if(EndStatus())
		return Chosen;
	else {
		/*
		* Increase the value at last(rightmost) cell until it has got to its
		* maximum value that is n-r+k where k is the cell address
		* from the left;
		*/
		if(Chosen[k]<n-r+k) {
			Chosen[k]++;
			EndStatus();
			return Chosen;
		}
		/*
		* When the last cell reached its maximum, find the rightmost cell left to
		* last cell which hasn't reached its  maximum,  and increase it by one(as
		* in Chosen[k]++ below) also then place consecutive integers to the next
		* cell to follow till the last cell
		*/
		while(Chosen[k] == (n-r+k) )
			k--;
		Chosen[k]++;
		for(unsigned j=k+1; j<r; j++)
			Chosen[j] = Chosen[j-1]+1;
		EndStatus();
		return Chosen;
	}

}



vector<unsigned> Combination::Trim(vector<unsigned>& From,vector<unsigned>& Remove) {
	vector<unsigned> Trimmed;
	Trimmed.reserve(From.size()-Remove.size());
	for(unsigned i:From) {
		if(find(Remove.begin(),Remove.end(),i) == Remove.end())
			Trimmed.push_back(i);
	}
	return Trimmed;
}

void Combination::DisplayChosen() {
	for(unsigned i=0; i<r; i++)
		cout<<Chosen[i];
	cout<<endl;
}

bool Combination::EndStatus() {
	if(Chosen[0] == n-r)
		EndReached = true;
	else
		EndReached = false;
	return EndReached;
}

void Combination::Reset() {
	for(unsigned i=0; i<r; Chosen[i]=i,i++);
}

vector<unsigned> Combination::operator++(int) { //postfix
	vector<unsigned> Temp = Chosen;
	Next();
	return Temp;
}

vector<unsigned> Combination::operator++() { //prefix
	return Next();
}

vector<unsigned> Combination::GetCurrent() {
	return Chosen;
}

void Combination::DisplayIt(vector<unsigned> &v) {
	for(unsigned i: v)
		cout<<Elements[i];
}
