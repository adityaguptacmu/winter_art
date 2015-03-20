#include <iostream>
#include <cassert>
#include <list>

using namespace std;
int runCustomerSimulation(int count, string input);


int main(int argc, char const *argv[])
{
	cout << "STRINGS" << endl;
	cout << "runCustomerSimulation(2, ) - " << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
	return 0;
}

int runCustomerSimulation(int count, string input)
{
	list <char> queue;
	list <char> using_list;

	cout << count << endl;
	cout << input << endl;
	for(char& c : input)
	{

		cout << c << endl;
	}
	return 0;
}