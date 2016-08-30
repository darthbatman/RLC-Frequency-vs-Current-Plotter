#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main() {

	const double PI = 3.1415926535897;

	double r1, r2, c, l, sv, ssf, esf, fss;
	double zc, zl, i;

	cout << "Resistor 1 value: ";
	cin >> r1;

	cout << "Resistor 2 value: ";
	cin >> r2;

	cout << "Capacitor value: ";
	cin >> c;

	cout << "Inductor value: ";
	cin >> l;

	cout << "Source Voltage value: ";
	cin >> sv;

	cout << "Starting Sweep Frequency value: ";
	cin >> ssf;

	cout << "Ending Sweep Frequency value: ";
	cin >> esf;

	cout << "Frequency Sweep Step size: ";
	cin >> fss;

	ofstream dataFile;
	dataFile.open("new.csv");
	dataFile << "Frequency,Current" << endl;

	for (int f = ssf; f <= esf; f += fss) {
		zc = 1 / (2 * PI * f * c);
		zl = (2 * PI * f * l);
		i = sv / sqrt((pow((r1 + r2), 2)) + (pow((zl - zc), 2)));
		
		dataFile << f << "," << i << endl;
	}

	dataFile.close();

	system("generatedGraph.xlsx");

	return 0;
}