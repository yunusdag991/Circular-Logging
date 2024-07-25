#include <iostream>
#include "logging.h"


int main(int argc, char** argv) {
	logging a("C:/Users/yunus/OneDrive/Desktop/bb/config.json");
	
	a.change_LogType_Freg_MaxLog("haftalik",4,55);
	cout << a.get_Freg();

	return 0;
}
