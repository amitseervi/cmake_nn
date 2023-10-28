#include<string>
#include<types/dim.h>
std::string get_message() {
	return "Hello world by Amit chaudhary";
}

Dimension::Dimension(int n, int m) {
	this->n = n;
	this->m = m;
}

int Dimension::get_n() {
	return this->n;
}

int Dimension::get_m() {
	return this->m;
}