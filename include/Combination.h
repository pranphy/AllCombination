#ifndef COMBINATION_H_INCLUDED
#define COMBINATION_H_INCLUDED

/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

class Combination {
private:
	unsigned n,r;
	bool EndReached, Generated;
	vector<char> Elements;
	vector<unsigned> Chosen;
	vector<vector<unsigned>> AllCombi;
	vector<unsigned> Trim(vector<unsigned>&,vector<unsigned>&);
	void MakeAll();
	void DisplayIt(vector<unsigned>&);
public:
	Combination(int=9,int=3);
	void SetElements(vector<char>);
	void DisplayAll(void);
	void DisplayChosen();
	vector<unsigned> Next();
	bool EndStatus(void);
	void Reset(void);
	void WriteToFile(void);
	vector<unsigned> operator++(int); //postfix
	vector<unsigned> operator++();//prefix
	vector<unsigned> GetCurrent();
	vector<vector<unsigned>> GetAll();
};


#endif // COMBINATION_H_INCLUDED
