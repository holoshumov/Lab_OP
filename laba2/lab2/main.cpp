#include "MainLib.h"
#include "Train_struct.h"
using namespace std;

int main() {

	string filename = inputForFile();
	readFile(filename);
	winterSchedule(filename);

	return 0;
}



