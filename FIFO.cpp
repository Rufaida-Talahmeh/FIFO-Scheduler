#include<iostream>
#include<fstream>
#include <string>
using namespace std;


int main() {
	string s = "in.txt";
	int  n = 0;
	ifstream in;
	in.open(s.c_str());
	in >> n;//number of processes

//*********************************
	int* ptime;
	ptime = new int[n];
	int* atime;
	atime = new int[n];
	string* name;
	name = new string[n];
//*********************************
// Reading from input file in.txt
	for (int i = 0; i < n; i++) {
		in >> name[i];             // process name
		//cout << name[i] << endl;

		in >> atime[i];           // arrival time for the ith process 
		//cout << atime[i] << endl;

		in >> ptime[i];           // processing time for the ith process
		//cout << ptime[i] << endl;
	}
	
	in.close();//close file 

// store data in arrays
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (atime[j] < atime[i])
			{
				int atemp = atime[i];
				atime[i] = atime[j];
				atime[j] = atemp;

				int ptemp = ptime[i];
				ptime[i] = ptime[j];
				ptime[j] = ptemp;

				string ntemp = name[i];
				name[i] = name[j];
				name[j] = ntemp;
			}
		}
	}
  
//sort arrays

	ofstream out;
	out.open("out.txt");
	for (int i = 0; i < n; i++)
	{
		out << name[i];
	}
	out << endl;
	//print test
	int delay = 0;
	int turnaround_time = 0;


//////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			turnaround_time =  ptime[i] ;
			//cout << name[i] << "  response : " << delay << "  turnaround_time : " << turnaround_time << "  delay : " << delay << endl;
			out << name[i] << ": (response=" << delay << ", turnaround=" << turnaround_time << ", delay=" << delay << ")"<<endl;
		}
		else
		{
			delay = delay+atime[i - 1] + ptime[i - 1] - atime[i];
			if (delay<0)
			{
				delay = 0;
			}
			turnaround_time =ptime[i]+delay ;
			//cout << name[i] << "  response : " << delay << "  turnaround_time : " << turnaround_time << "  delay : " << delay << endl;
			out << name[i] << ": (response=" << delay << ", turnaround=" << turnaround_time << ", delay=" << delay << ")" << endl;
		}
	}
	out.close();
//////////////////////////////////////////////////////////////////////////
	return 0;
}
