#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void getRandom(vector<unsigned int> &vTest) {
	//srand(time(NULL));
	cout << time(NULL) << endl;
	for (int i = 0; i < vTest.size(); i++) {
		vTest.at(i) = rand() % 2;
	}
	return;
}

void printVectorInts(vector<unsigned int> inputVector) {
	for (int i = 0; i < inputVector.size(); i++) {
		cout << inputVector.at(i);
	}
	cout << endl;
	return;
}

//consider making recursive? or just iterate! Use an iterator FIX ME use an iterator/recursion
void verticalLinesInsert(int hitomeValue, int hitomeHoriSize, vector<string>& inputVector) {
	for (int i = 0; i < hitomeHoriSize; i++) {
		int j = i % 2;
		if (j == hitomeValue) {
			inputVector.push_back("_");
		}
		else {
			inputVector.push_back(" ");
		}
	}
	return;
}


// consider making recursive?
void verticalInput(int hitomeVerSize, int hitomeHoriSize, vector<vector<string>>& inputVector, 
	vector<unsigned int>& vTest) {

	for (int i = 0; i < hitomeVerSize; i++) {

		if (vTest.back() == 1) {
			verticalLinesInsert(1, hitomeHoriSize, inputVector.at(i));
		}
		else if (vTest.back() == 0) {
			verticalLinesInsert(0, hitomeHoriSize, inputVector.at(i));
		}
		else {
			cout << "One of the random values was off." << endl;
			return;
		}
		vTest.pop_back();
	}

	return;
}

void horizontalLinesInsert(bool hitomeValue, int horizontalValue, vector<string>& inputVector) {
	string temporaryValue = inputVector.at(horizontalValue);
	if (hitomeValue) {
		temporaryValue.append("|");
	}
	else {
		temporaryValue.append(" ");
	}
	inputVector.at(horizontalValue) = temporaryValue;

	return;

}


void horizontalLinesIterate(int hitomeValue, int horizontalValue, vector<vector<string>>& inputVector) {
	
	for (int i = 0; i < inputVector.size(); i++) {
		int j = i % 2;
		bool lineThere = false;
		if (hitomeValue == j) {
			lineThere = true;
		}
		horizontalLinesInsert(lineThere, horizontalValue, inputVector.at(i));
	}
	return;
}

//FIX ME use iterator
void horizontalInput(int hitomeVerSize, int hitomeHoriSize, vector<vector<string>>& inputVector,
	vector<unsigned int>& vTest) {

	for (int i = 0; i < hitomeHoriSize; i++) {
		if (vTest.back() == 1) {
			//call something
			horizontalLinesIterate(1, i, inputVector);
		}
		else if (vTest.back() == 0) {
			horizontalLinesIterate(0, i, inputVector);
		}
		else {
			cout << "one of the random values was off. Sorry!" << endl;
			return;
		}
		vTest.pop_back();
	}

	return;
}


void printVectorStrings(vector<string> inputVector) {
	for (int i = 0; i < inputVector.size(); i++) {
		cout << inputVector.at(i);
	}
	cout << endl;
	return;
}

void printIterateVectors(vector<vector<string>> inputVector) {
	for (int i = 0; i < inputVector.size(); i++) {
		printVectorStrings(inputVector.at(i));
	}
	return;
}


void stringToNum(vector<unsigned int>& vecString, string inputString) {
	unsigned int addToVec = 0;
	char interpret;
	for (int i = 0; i < inputString.size(); i++) {
		interpret = inputString.at(i);
		cout << interpret << " ";
		if (interpret == 'a' || interpret == 'A') {
			addToVec = 1;
		}
		else if (interpret == 'e' || interpret == 'E') {
			addToVec = 1;
		} 
		else if (interpret == 'i' || interpret == 'I') {
			addToVec = 1;
		}
		else if (interpret == 'o' || interpret == 'O') {
			addToVec = 1;
		}
		else if (interpret == 'u' || interpret == 'U') {
			addToVec = 1;
		}
		else if(interpret == 'y' || interpret == 'Y') {
			addToVec = 1;
		}
		else {
			addToVec = 0;
		}
		vecString[i] = addToVec;
	}
	cout << endl;
	return;
}

//okay now it's time to align stuff by numbers!
void numbersToNum(vector<unsigned int>& vecInts, string inputString) {
	unsigned int addToVec = 0;
	for (int i = 0; i < inputString.size(); i++) {
		addToVec = int(inputString.at(i));
		addToVec = addToVec % 2;
		vecInts[i] = addToVec;
	}
	return;
}


int main(int argv, char* argc[]) {

	//gonna try seeding rand with time here, see what happens
	srand(time(NULL));
	//also write the output to a file
	cout << "Commands: string, random, or numbers. " << endl;
	cout << "String and numbers should be followed by two pieces of input (vertical and horizontal axis data)." << endl;
	cout << "Random should be followed by two numbers for the number of rows and columns." << endl << endl;
	
	//interpret arg line
	int commandType = 0;
	string firstCommand;

	if (argv <= 1) {
		cout << "There is no command. " << endl;
		return 0;
	}
	
	firstCommand = argc[1];
	if (firstCommand == "string") {
		commandType = 1;
	}
	else if (firstCommand == "random") {
		commandType = 2;
	}
	else if (firstCommand == "numbers") {
		commandType = 3;
	}
	else {
		cout << "I don't recognize that command. " << endl;
		return 0;
	}

	int hitomeHoriSize = 0; // number of columns
	int hitomeVerSize = 0; // number of rows

	//string
	string verString = "";
	string horiString = "";


	if (commandType == 1) {
		verString = argc[2];
		horiString = argc[3];
		hitomeHoriSize = horiString.size();
		hitomeVerSize = verString.size();
	}
	//random
	else if (commandType == 2) {
		verString = argc[2];
		horiString = argc[3];
		hitomeVerSize = stoi(verString);
		hitomeHoriSize = stoi(horiString);
	}

	//numbers
	else if (commandType == 3) {
		verString = argc[2];
		horiString = argc[3];
		hitomeVerSize = verString.size();
		hitomeHoriSize = horiString.size();
	}

	int totalValues = hitomeHoriSize + hitomeVerSize;
	vector<vector<string>> hitomezashi(hitomeVerSize);
	vector<unsigned int> vHori(hitomeHoriSize);
	vector<unsigned int> vVer(hitomeVerSize);

	//string
	if (commandType == 1) {
		stringToNum(vHori, horiString);
		stringToNum(vVer, verString);
	}

	//random
	if (commandType == 2) {
		getRandom(vHori);
		getRandom(vVer);
	}

	//numbers
	if (commandType == 3) {
		numbersToNum(vHori, horiString);
		numbersToNum(vVer, verString);
	}

	//put all the strings in the thing

	printVectorInts(vHori);
	printVectorInts(vVer);
	verticalInput(hitomeVerSize, hitomeHoriSize, hitomezashi, vVer);
	horizontalInput(hitomeVerSize, hitomeHoriSize, hitomezashi, vHori);
	

	//now we gotta print
	printIterateVectors(hitomezashi);

	//horizontal input must have access to all the vector values so I think I'm just going to make it an array table


	return 0;
}