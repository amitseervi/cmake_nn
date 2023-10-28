#include<iostream>
#include<types/dim.h>

int main() {
	std::string message = get_message();
	std::cout << "message =" << message << "\n";
	Dimension d(1,2);
	std::cout << "Dimension = " << d.get_m() << " " << d.get_n() << "\n";
}