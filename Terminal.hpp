#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>

class Terminal {
private:
	int height, width;
	char** buf;
public:
	Terminal(int h, int w);
	~Terminal();

	int getHeight() const;
	int getWidth() const;

	void clear();
	void write(std::string arg, int x, int y);
	void display() const;
};

#endif