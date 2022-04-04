#include "teststudent.h"
#include "buffile.h"
#include "length.h"

int main(int argc, char** argv) {

	Student st1;
	cin >> st1;
	cout << st1;

	LengthFieldBuffer Buff;
	st1.Pack(Buff);
	
	cout << "\nBuff!!!!\n";
	Buff.Print(cout);

	return 1;
}