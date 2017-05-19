#include "labyrinth.h"

Labyrinth::Labyrinth()
{
}


Labyrinth::~Labyrinth()
{
}

void Labyrinth::ReadFile(int& width, int& height, string& Labyrinth) {
	string tmp;
	string path;
	cout << "Enter path to maze: \n";

	/*                               ÄNDERN                        */
	//cin >> path;
	ifstream ifs("maze.txt");
	/*                                                             */

	//read Labyrinth into 1d-string-array
	if (ifs.good()) {
		//gets width of Labyrinth
		getline(ifs, tmp, '\n');
		Labyrinth += tmp;
		Labyrinth += "\n";
		width = tmp.size();

		while (!ifs.eof()) {
			getline(ifs, tmp, '\n');
			height++;
			Labyrinth += tmp;
			Labyrinth += "\n";
		}
	}
}

void Labyrinth::CreateBlackedMap(int & width, int & height, string& blackedMap)
{
	for (int i = 0; i < height + 1; i++) {
		for (int k = 0; k < width; k++) {
			blackedMap += (char)219u;
		}
		blackedMap += "\n";
	}
}

int Labyrinth::GetEntryPoint(int& width, string & Labyrinth)
{
	int entry = 0;
	for (int i = 0; i < width; i++) {
		if (Labyrinth[i] == ' ') {
			entry = i;
			break;
		}
	}
	return entry;
}

void Labyrinth::PrintLab(string & lab)
{
	cout << "\n\n";
	cout << lab << endl;

	int width = 0;
	int height = 0;

	int labSize = lab.size();

	for (int i = 0; i < labSize; i++) {
		if (lab[i] == '\n') {
			width = i + 1;
			break;
		}
	}


	cout << "Width of String: " << width << endl;
	cout << "Height of String: " << lab.size() / width << endl;

	cout << "Length of String (length*width): " << lab.size() << "\n\n";
}