#include<string>
#ifndef __HEADER_DIM__
#define __HEADER_DIM__
std::string get_message();

class Dimension {
private:
	int n;
	int m;
public:
	Dimension(int n, int m);
	int get_n();
	int get_m();
};

#endif