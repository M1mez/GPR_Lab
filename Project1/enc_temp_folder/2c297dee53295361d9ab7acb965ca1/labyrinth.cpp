#include "labyrinth.h"

Labyrinth::Labyrinth()
{
}


Labyrinth::~Labyrinth()
{
}

void Labyrinth::ReadFile(int& width, int& height, string& Labyrinth)
{
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
		width++;
		height++;

		while (!ifs.eof()) {
			getline(ifs, tmp, '\n');
			height++;
			Labyrinth += tmp;
			Labyrinth += '\n';
		}
	}
}

void Labyrinth::CreateBlackedMap(int& width, int& height, string& blackedMap)
{
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width - 1; k++) {
			blackedMap += (char)219u;
		}
		blackedMap += "\n";
	}
}

int Labyrinth::GetEntryPoint(int& width, int& height, string & labyrinth)
{
	int length = width * height;

	int entry = 0;
	cout << width << height;
	while (true)
	{
		cout << entry << " ";
		if (width+1 == entry) return -1;
		cout << labyrinth[entry-1];
		if (labyrinth[entry] == ' ') return entry;
		system("pause");
		if ((entry - (width) < 0) && (entry + 1 != width))
		{
			entry++;
			continue;
		}
		else if (!((entry + 1) % width) && (entry + 2 < length))
		{
			entry += width;
			continue;
		}
		else if ((entry + width > length) && (entry % width != 1))
		{
			entry--;
			continue;
		}
		else if (entry % width == 1)
		{
			entry -= width;
			continue;
		}
	}

	////	searches on the top side
	//for (int entry = 0; entry < width - 1;) {
	//	if (labyrinth[entry++] == ' ') {
	//		return entry;
	//	}
	//}

	////	FEHLERHAFT
	////	searches right side
	//for (int entry = width-2; entry < length; entry += width) {
	//	//cout << " blabla " << entry << " " << labyrinth[entry] << endl;
	//	cout << "width: " << width;
	//	if (labyrinth[entry] == ' ') {
	//		return entry;
	//	}
	//}

	cout << "No entry found" << endl;
	return -1;
}

void Labyrinth::PrintLab(int& width, int& height, string & lab)
{
	cout << "\n\n";
	cout << lab << endl;

	int w = 0, h = 0;

	for (int i = 0; i < lab.size(); i++) {
		w++;
		if (lab[i] == '\n') {
			break;
		}
	}

	for (int i = 0; i < lab.size(); i++) {
		if (lab[i] == '\n') {
			h++;
		}
	}

	cout << "Width of String (with newline): " << w << endl;
	cout << "Height of String: " << h << endl;

	cout << "Length of String (length*width): " << lab.size() << "\n\n";
}