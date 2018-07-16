//Victor G. Balcazar
//Contact info: victorbalcazar3@hotmail.com

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

#include <fstream>

using namespace std;

void printRing(int npar, int W[][100], double seconds);

void printStar(int npar, int W[][100], double seconds);

void printMesh(int npar, int W[][100], double seconds);

void printNeither(int npar, int W[][100], double seconds);

int main() {
	int n, i, j, center = 0;
	int count = 0;
	int W[100][100];
	bool cond;
	int RSM = 0;

	//display header
	cout << endl << "CPSC335-x - Programming Assignment #2" << endl;
	cout << "Topology recognition algorithm" << endl;
	cout << "Enter the number of nodes in the topoligy" << endl;
	//read the number of nodes
	cin >> n;
	//read weight matrix
	cout << "Enter the positive weights, 100 for infinity: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> W[i][j];
		}
	}//end of nested for loop

	//Start the chronograph to time the excecution of the algorithm
	auto start = chrono::high_resolution_clock::now();

	cout << "The topology is " << endl;

	cond = true;
	
	//loop to check whether the topology is a ring
	//--------------------------------------------
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] != 0 && W[i][j] != 100)
				count++;
		}
		if (count != 2)
			cond = false;
		count = 0;
	}//end of nested for loop

	if (cond) {
		cout << "ring\n";
		RSM = 1;
		
		//return EXIT_SUCCESS;
	}
	//-------------------------------------------

	//loop to check whether the topology is star
	//variables initialized for the sake of making my algorithm work
	cond = true;

	int tmp_count = 0; //temporary counter for the number of connections in the j controlled loop
	count = 0;
	bool set = false; //sets center
	center = 0;
	//===========================================
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] != 0 && W[i][j] != 100)
				tmp_count++;
		}
		if (tmp_count == (n - 1) && set == true) {
			cond = false;
		}
		if (tmp_count == (n - 1) && set == false) {
			set = true;
			center = i;
		}
		
		count += tmp_count;
		tmp_count = 0;
	}//end of nested for loop
	
	if (count != ((n - 1) * 2) && set == false)
		cond = false;

	if (cond) {
		cout << "star\n";
		RSM = 2;
		//return EXIT_SUCCESS;
	}
	//============================================

	//loop to check whether the topology is a fully connected mesh
	cond = true;
	count = 0;
	//--------------------------------------------
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] != 0 && W[i][j] != 100)
				count++;
		}
		if (count != (n - 1))
			cond = false;
		count = 0;
	}//end of nested for loop

	if (cond == true) {
		cout << "fully connected mesh\n";
		RSM = 3;
		//return EXIT_SUCCESS;
	}
	else if(RSM == 0){
		cout << "neither\n";
	}
	//-------------------------------------------

	/*if (!cond)
		cout << "neither" << endl;*/

	//End the chronograph to time the excecution of the algorithm
	auto end = chrono::high_resolution_clock::now();

	//Displaying the output is NOT part of the algorithm so the timer ends before displaying the output
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	cout << "elapsed time: " << seconds << "seconds" << endl;

	if (RSM == 1)
		printRing(n, W, seconds);
	else if (RSM == 2)
		printStar(n, W, seconds);
	else if (RSM == 3)
		printMesh(n, W, seconds);
	else if (RSM == 0)
		printNeither(n, W, seconds);

	system("pause");
	return 0;
}

void printRing(int npar, int W[][100], double seconds) {
	ofstream file_;
	file_.open("ringOutput.txt");
	file_ << endl << "CPSC335-x - Programming Assignment #2" << endl;
	file_ << "Topology recognition algorithm" << endl;
	file_ << "Enter the number of nodes in the topoligy" << endl;
	//read the number of nodes
	file_ << npar;
	file_ << "Enter the positive weights, 100 for infinity: " << endl;
	//read weight matrix
	for (int i = 0; i < npar; i++) {
		for (int j = 0; j < npar; j++) {
			file_ << W[i][j] << " ";
		}
		file_ << endl;
	}//end of nested for loop
	

	file_ << "The topology is " << endl;
	file_ << "ring\n";

	file_ << "elapsed time: " << seconds << "seconds" << endl;

	file_.close();

}

void printStar(int npar, int W[][100], double seconds) {
	ofstream file_;
	file_.open("starOutput.txt");
	file_ << endl << "CPSC335-x - Programming Assignment #2" << endl;
	file_ << "Topology recognition algorithm" << endl;
	file_ << "Enter the number of nodes in the topoligy" << endl;
	//read the number of nodes
	file_ << npar;
	file_ << "Enter the positive weights, 100 for infinity: " << endl;
	//read weight matrix
	for (int i = 0; i < npar; i++) {
		for (int j = 0; j < npar; j++) {
			file_ << W[i][j] << " ";
		}
		file_ << endl;
	}//end of nested for loop


	file_ << "The topology is " << endl;
	file_ << "star\n";

	file_ << "elapsed time: " << seconds << "seconds" << endl;

	file_.close();
}

void printMesh(int npar, int W[][100], double seconds) {
	ofstream file_;
	file_.open("meshOutput.txt");
	file_ << endl << "CPSC335-x - Programming Assignment #2" << endl;
	file_ << "Topology recognition algorithm" << endl;
	file_ << "Enter the number of nodes in the topoligy" << endl;
	//read the number of nodes
	file_ << npar;
	file_ << "Enter the positive weights, 100 for infinity: " << endl;
	//read weight matrix
	for (int i = 0; i < npar; i++) {
		for (int j = 0; j < npar; j++) {
			file_ << W[i][j] << " ";
		}
		file_ << endl;
	}//end of nested for loop


	file_ << "The topology is " << endl;
	file_ << "fully connected mesh\n";

	file_ << "elapsed time: " << seconds << "seconds" << endl;

	file_.close();
}

void printNeither(int npar, int W[][100], double seconds) {
	ofstream file_;
	file_.open("neitherOutput.txt");
	file_ << endl << "CPSC335-x - Programming Assignment #2" << endl;
	file_ << "Topology recognition algorithm" << endl;
	file_ << "Enter the number of nodes in the topoligy" << endl;
	//read the number of nodes
	file_ << npar;
	file_ << "Enter the positive weights, 100 for infinity: " << endl;
	//read weight matrix
	for (int i = 0; i < npar; i++) {
		for (int j = 0; j < npar; j++) {
			file_ << W[i][j] << " ";
		}
		file_ << endl;
	}//end of nested for loop


	file_ << "The topology is " << endl;
	file_ << "neither\n";

	file_ << "elapsed time: " << seconds << "seconds" << endl;

	file_.close();
}
