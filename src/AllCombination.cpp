/**********************************
    Author       :@PrakashGautam
    Date Written :Nov   20, 2014
    Last Updated :Dec   03, 2014
    Email     :pranphy@gmail.com
************************************/


#include "AllCombination.h"

/*
	The following function is designed to generate all the possible combinations
	of contained in the vector Elements, taken r at a time. It works only if the
	value of n when divided by r leaves no  remainder  because the value n-k*r,k
	integer,must be r. First it generates a combination C(n,r) and then from the
	remaining elements except those r's already chosen C(n-r,r) and so on  up to
	C(r,r) . For all C(n,r) it attaches C(n-r,r) and generates a new combination
	equaling C(n,r)*C(n-r,r) combinations, and then continues until it generates
	the total of C(n,r)*C(n-r,r)*C(n-2*r)*... *C(r,r). It can be used to generate
	all combination for the game kitty.

*/
void CompleteCombi(unsigned n,unsigned r, vector<unsigned> ReceivedElements) { //nothingh done with receivedElements so far.
	if((n % r) != 0){
        ostringstream Error;
        Error<<" Cannot generate Complete Combi as "<<n<<" is not divisible by "<<r<<" without remainder ";
        throw Error.str();
    }else {
        vector<unsigned> Elements;
        for(unsigned i = 0;  i < n; Elements.push_back(i++));
        
        /** The vector of vectors of vectors SuperCombination could be very large for
         *  large n and r (with the constraint n%r == 0), the  total elements in  the
         *  vector would be exactly C(n,r)*C(n-r,r)*C(n-2*r)*...*C(r,r) plus overhead
         *  have to be careful about his so that RAM wouldn't be completely  consumed. 
         */
		vector<vector<vector<unsigned>>> SuperCombination;
		for(unsigned i=0; i<n/r; i++) {
			Combination Current(n-i*r,r);
			SuperCombination.push_back(Current.GetAll());
		}

        /**                   
         *                  {  1 For the first(0th) pass
         *   Total Lines = <
         *                  {  Number of lines in Combination.dat for other pass
         * */
		unsigned Pass = 0,TotalLines = 1;
		for(auto AllCombination : SuperCombination) {
            /** Since the file Combination.dat doesn't exist in the First (0th) pass
             *  there should he some robust'er' method to handle  this  situation as 
             *  this is likel to be error prone, may be other implementation of  c++
             *  compiler dont stand the constructs like this at all (I have GNU GCC).
             */
			ifstream OutputFile("Combination.dat"); //Doesn't exist at first (0th) pass.
			ofstream TemporaryFile("Temp.dat"); //Created from first pass.

            /** Total lines is the number of lines in Combination.dat  since at 
             *  the firs pass the file doesn't exist it is equal to 1 to  begin
             *  the proceedings  */
			for(unsigned Lines = TotalLines; Lines--;) {
                /** Current contains the Current line from the Combination.dat file so
                 *  that we can use it to trim the elements from  the elements  vector
                 *  at the first(0th) pass the current vector is empty
                 */
				vector<unsigned> Current;
				unsigned Value; //cell value to be read from file
				Current.reserve(Pass * r);
                /** To loop through every value at the current line, and read the element
                 *  in the Current vector. In the first (0th) pass it is empty
                 */
				for(unsigned Cell = 0; Cell < Pass * r; Cell++) {
					OutputFile>>Value;
					Current.push_back(Value);
				}
                /** Trim the read elements  from  the  elements  vector  at the first pass
                 *  nothing is trimmed so that Trimmed is equal to Elements itself. */
				auto Trimmed = Trim(Elements,Current);
                /** Loop through the every combination of current combination and write  it to
                 *  file against the already existing in file
                 */
				for(auto CurrentCombination : AllCombination) {
					/** First write the vector from file  */
                    for(unsigned i:Current)
						TemporaryFile<<i<<" ";
                    /** Write the trimmed elements into the file against the elements */
					for(unsigned i: CurrentCombination)
                        /* Trimmed[i]; here [i] (ith inde) is very important as we dont
                         *  want to write i itself rather than  Trimmed[i] special care
                         *  should be taken here
                         */
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
