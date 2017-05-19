#include "Labyrinth.h"
#include <iostream>

using namespace std;

void ReadFile(int& width, int& height, string& labyrinth);
void CreateBlackedMap(int& width, int& height, string& blackedMap);
void getentry(int& entry, int& width, string& labyrinth);

/////////
void PrintLab(string& lab);


int main() {
	string labyrinth = "";

	//blacked version of labyrinth
	string blackedMap = "";

	int width, height;
	width = height = 0;
	int entry, exit;

	ReadFile(width, height, labyrinth);
	PrintLab(labyrinth);
	CreateBlackedMap(width, height, blackedMap);
	PrintLab(blackedMap);
	width++;
	blackedMap[2 + (0 * width)] = ' ';
	blackedMap[2 + (1 * width)] = ' ';
	blackedMap[2 + (2 * width)] = ' ';
	blackedMap[3 + (2 * width)] = ' ';
	blackedMap[4 + (2 * width)] = ' ';
	blackedMap[4 + (3 * width)] = ' ';
	getentry(entry, width, labyrinth);
	PrintLab(blackedMap);

	system("PAUSE");
}

void ReadFile(int& width, int& height, string& labyrinth){
	string tmp;
	string path;
	cout << "Enter path to maze: \n";
	//ÄNDERN
	//cin >> path;
	ifstream ifs("maze.txt");

	//read labyrinth into 1d-string-array
	if (ifs.good()) {
		//gets width of labyrinth
		getline(ifs, tmp, '\n');
		labyrinth += tmp;
		labyrinth += "\n";		
		width = tmp.size();
		
		while (!ifs.eof()) {
			getline(ifs, tmp, '\n');
			height++;
			labyrinth += tmp;
			labyrinth += "\n";
		}
	}
}

void CreateBlackedMap(int & width, int & height, string& blackedMap)
{
	for (int i = 0; i < height+1; i++) {
		for (int k = 0; k < width; k++) {
			blackedMap += (char)219u;
		}
		blackedMap += "\n";
	}
}

void getentry(int& entry, int& width, string & labyrinth)
{
	for (int i = 0; i < width; i++) {
		if (labyrinth[i] == ' ') {
			entry = i;
			break;
		}
	}
	cout << "Entry Point: " << entry;
	cout << labyrinth[0];
}

void PrintLab(string & lab)
{
	cout << "\n\n";
	cout << lab << endl;

	int width = 0;
	int height = 0;

	for (int i = 0; i < lab.size(); i++) {
		if (lab[i] == '\n') {
			width = i+1;
			break;
		}
	}


	cout << "Width of String: " << width << endl;
	cout << "Height of String: " << lab.size() / width << endl;

	cout << "Length of String (length*width): " << lab.size() << "\n\n";
}
