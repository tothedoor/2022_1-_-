#include <fstream>
#include <iostream>

using namespace std;

int main (void)
{
	char ch;
	fstream file; // declare fstream unattached
	char fileName[20];
	cout << "Enter the name of the file: " << flush;	// Step 1
	cin >> fileName;									// Step 2 
	file.open(fileName, ios::in);						// Step 3 
	
	while (true)
	{
		file >> ch;										// Step 4a 
		if (file.fail())
			break;

		if (ch == '|')									// Step 4b 				
			cout << "\n";
		else
			cout << ch;							
	}

	file.close();										// Step 5. Close file.
	system("pause");

	return 1;
}
