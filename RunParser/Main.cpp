#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//////////////////////////////////////////////////
//
//Name: returnDistance
//Description: extracts an integer Distance from a
//			   line in the following format
//			   Distance: xxx km
//			   where xxx is the number in question
//			   there can be a variable number of spaces
//			   between the number and words however the 
//			   words must be as written
//Returns: The distance as a floating point number or
//		   -1 if there is an error
//
//Author: Matt Burton
//Date: Mar 17
//
//Revision: 
//
//////////////////////////////////////////////////
float returnDistance( string line )
{
	float numnum;
	string wordnum;
	int startnum = line.find("Distance:") + 9;	//starting position of word + length of word
	int endnum = line.find("km");	//position of end word
	int lengthnum = endnum - startnum;	//length of substring

	if (lengthnum <= 0)	//error
	{
		return -1;
	}
	else 
	{
		wordnum = line.substr(startnum, lengthnum);	//extract distance
		try {
			numnum = stof(wordnum);	//convert to floating point
		}
		catch (invalid_argument &a) {	//conversion failed
			cout << "error, invalid format:\""<< wordnum << "\"" << endl;
			exit(1);
		}
	}
	return numnum;
}

int main() {
	//variable declarations
	ifstream file;
	string line;
	float count = 0;
	float check = 0;

	//code section
	file.open("run.txt");	//name of textfile to parse

	while (getline(file, line))	//examine line-by-line
	{
		if (line.find("Distance:") != string::npos) { //Distance Parser
			check = returnDistance(line);
			if (check == -1) {	//error
				cout << "error, invalid format" << endl;
				exit(1);
			}
			else {
				count = count + check;
			}
				
		}
	}
	
	cout << "You ran: " << count << " km" << endl;

}