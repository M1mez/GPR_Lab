#include "labyrinth.h"

using namespace std;

Labyrinth::Labyrinth()
{
	m_width = m_height = 0;
	m_entry = m_exit = 0;
	m_blackMap = m_labString = "";
	ReadFile();

	if (m_entry - m_width < 0) initHead = SOUTH;
	else if (!((m_entry + 2) % m_width)) initHead = WEST;
	else if (m_entry + m_width > m_labString.size()) initHead = NORTH;
	else if (!(m_entry % m_width)) initHead = EAST;
}

Labyrinth::~Labyrinth() {}

void Labyrinth::ReadFile()
{
	string tmp;
	string path;
	cout << "Enter path to maze: \n";
	///TODO static path
	path = "3.txt"; 

	ifstream ifs(path.c_str());
	if (ifs.good()) {
		getline(ifs, tmp, '\n');
		m_labString += (tmp + '\n');
		m_height++;

		m_width = tmp.size();

		while (!ifs.eof()) {
			getline(ifs, tmp, '\n');
			if (tmp.size() == m_width)
			{
				m_labString += (tmp + '\n');
				m_height++;
			}
		}
		m_width++;
	}
	GetEntryPoint();
	/*cout << "entry: " << m_entry << endl;
	cout << "exit: " << m_exit << endl;*/
	CreateBlackedMap();
}

void Labyrinth::CreateBlackedMap()
{
	m_blackMap = m_labString;
	for (char& c : m_blackMap)
	{
		if (c != '\n') c = (char)219u;
	}
	m_blackMap[m_entry] = m_labString[m_entry];
}

void Labyrinth::GetEntryPoint()
{
	int length = m_width * m_height;
	int i = 0;
	bool searchEntry = true;

	//top Side
	for (; i < m_width-2; i++) {
		if (m_labString[i] == ' ')
		{
			if (searchEntry)
			{
				m_entry = i;
				searchEntry = false;
			}
			else
			{
				m_exit = i;
				return;
			}
		}
	}

	// right Side
	for (;i < length;i += m_width)
	{
		if (m_labString[i] == ' ')
		{
			if (searchEntry)
			{
				m_entry = i;
				searchEntry = false;
			}
			else
			{
				m_exit = i;
				return;
			}
		}
		if (i + m_width > length) break;
	}

	// bottom Side
	for (; (i+1) % m_width;i--) {
		if (m_labString[i] == ' ')
		{
			if (searchEntry)
			{
				m_entry = i;
				searchEntry = false;
			}
			else
			{
				m_exit = i;
				return;
			}
		}
	}

	i++;
	// left Side
	for (;i > 2*m_width;i -= m_width)
	{
		if (m_labString[i] == ' ')
		{
			if (searchEntry)
			{
				m_entry = i;
				searchEntry = false;
			}
			else
			{
				m_exit = i;
				return;
			}
		}
	}

	if (!(m_entry && m_exit)) cout << endl << "No valid labyrinth! " << endl;
}

void Labyrinth::PrintLab(bool mapVisible)
{
	cout << endl << ( mapVisible ? m_labString : m_blackMap ) << endl;
}

int Labyrinth::TStart(Robot * r)
{
	return r->walk();
}
