#include<iostream>
#include<string>
#include "project_screen.h"
using namespace std;
int main() {
	project_screen First_type;
	project_screen Second_type(40, "wall", 60, "dell");
	project_screen Third_type(50, "wall", 70, "motorolla");
	First_type.Data_output();
	Second_type.Data_output();
	Third_type.Data_output();

	return 0;
}
