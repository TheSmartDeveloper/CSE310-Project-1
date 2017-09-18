/*
	Kevin George
	Prof. Xue
	CSE310 - Data Structures & Algorithms
	February 7th, 2017 @ 4:30 PM
	Brief Description:
		This project will perform calculations on given input. The input will be provided by an input file  		(input.txt). This input will be read into the main method and processed through the function named  		foreignsub. This function will be built on a separate file and will have an associated header   		file consisting of the function prototype to process the data.
*/

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "foreignsub.h"

using namespace std;

int main()
{
	fstream inputFile;	//variable name is given for file operations
	string fileName;	//variable name given to specify what the user inputs as the name of the file
	string fileLines;
	int lineSize = 0;
	cout << "What file would you like to open up? " << endl;
	getline(cin, fileName);		//get data from user and put it into string fileName
	inputFile.open(fileName);	//open the file
	if(inputFile.is_open())		//check if file open
	{
		cout << "The file " << fileName << " is open."<< endl;
		getline (inputFile, fileLines);		//take everything from the line of the file
		string delim = " ";					//delimiter for getting rid of the spaces in between values
		size_t startPoint = 0;				//specifies where the line starts
		string token;						// this will take each piece of data
		string endString;					// final string for the end of each line from input
		int myCount = 0;					//simple iterating counter set up for printing later
		int n = std::stoi(fileLines);		//takes the first value and converts it from a string to an int and plaes it in an integer variable
		int values;							//integer variable designed to place data in array after integer conversion
		cout << "the total number of lines in " << fileName << " is = " << n << endl;
		for(int count = 0; count < n; count++) //first action to just get the length of each line
		{
			getline (inputFile, fileLines);
			lineSize = lineSize + fileLines.length();
		}
		cout << "The total number of all characters (including whitespace) in " << fileName << " is = " << lineSize << endl;
		int *A = NULL;						//dynamically allocated arrays set to the aforementioned lineSize. This guarantees that the arrays will not be smaller than the amount of data in input
		A = new int[lineSize];
		int *B = NULL;
		B = new int[lineSize];
		int *C = NULL;
		C = new int[lineSize];
		inputFile.close();					//file closed so the process can be restarted later
		inputFile.open(fileName);			//file reopened so that the first line value can be guaranteed
		getline (inputFile, fileLines);
		n = std::stoi(fileLines);			//perform the same integer conversion of the first value, this is for safety since the input cannot be changed during run, it is easier to pull from the source again then attempting to pull from anything initialized above just in case the value is for some reason changed
		for(int count = 0; count < n; count++)	//until we have gone through every line
		{
			getline (inputFile, fileLines);		//take the line
			string testString = fileLines + " ";	//add a space at the end to aid data processing
			while((startPoint = testString.find(delim)) != string::npos)
			{								//whenever we find a demiliter and have not reached the end of the line
				token = testString.substr(0, startPoint); //take the first data point and place it into token
				values = std::stoi(token);			//convert token to an integer
				A[myCount] = values;				//plug each value into the corresponding array cell
				B[myCount] = values;
				C[myCount] = values;
				myCount++;							//increment counter so that the array will move up
				endString = testString.erase(0, startPoint + delim.length());		//erase the rest of the string to prevent any issues in conversion
			}
		}
		inputFile.close();					//close input
		cout << "The file " << fileName << " is closed."<< endl;
		fstream outputFile;					//create/open the output files
		string outputFileName = "output1.txt";
		outputFile.open(outputFileName, ofstream::out | ofstream::trunc); //makes sure that the output file is clear of any previous data since input sizes are prone to change
		if(outputFile.is_open())
		{
			cout << "The file " << outputFileName << " is open."<< endl;
			outputFile << n << endl;
			//as long as the file is open, output the array, for this section I chose to have each array given its own line since this would make it easier to read. Until we hit the end output each data point after the other. Once that is done break the loop and start the next array on the next line.
			for(int count = 0; count <= (lineSize/2); count++)
			{				//lineSize/2 is used distinctly because when the loop is set to max at just "lineSize" the array will print out several unused array cells filled with 0's. This minimizes how many extra cells there are
				outputFile << A[count] << " ";
			}
			outputFile << endl;
			for(int count = 0; count <= (lineSize/2); count++)
			{
				outputFile << B[count] << " ";
			}
			outputFile << endl;
			for(int count = 0; count <= (lineSize/2); count++)
			{
				outputFile << C[count] << " ";
			}
			outputFile.close();
			cout << "The file " << outputFileName << " is closed."<< endl;
			//close and display that the output is closed so that the next output file can be opened
		}
		else
		{
			cout << "Filename not found, program terminating..." << endl;
			return 0;
		}
		fstream outputFileTwo;					//create/open the output files
		outputFileName = "output2.txt";
		outputFileTwo.open(outputFileName, ofstream::out | ofstream::trunc);
		int result = sub(n, A, B, C);		//function called from foreignsub.h
		if(outputFileTwo.is_open())
		{
			cout << "The file " << outputFileName << " is open."<< endl;
			outputFileTwo << n << endl; //print the adjusted values
			for(int count = 0; count <= (lineSize/2); count++)
			{
				outputFileTwo << A[count] << " ";
			}
			outputFileTwo << endl;
			for(int count = 0; count <= (lineSize/2); count++)
			{
				outputFileTwo << B[count] << " ";
			}
			outputFileTwo << endl;
			for(int count = 0; count <= (lineSize/2); count++)
			{
				outputFileTwo << C[count] << " ";
			}
			cout << result << endl;
			outputFileTwo.close();
			cout << "The file " << outputFileName << " is closed."<< endl;
		}
		else
		{
			cout << "Filename not found, program terminating..." << endl;
			return 0;
			//if the file name is wrong the program will terminate
		}
		//arrays deleted and nullified to clear the memory
		delete [] A;
		A = NULL;
		delete [] B;
		B = NULL;
		delete [] C;
		C = NULL;
		cout << "The program is finished" << endl;
	}
	else
	{
		cout << "Filename not found, program terminating..." << endl;
		return 0;
	}
}