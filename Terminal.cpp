#include "Terminal.hpp"
#include <iostream>
#include <cstring>

Terminal::Terminal(int h, int w): height(h), width(w) {
	buf  = new char*[height];
	for (int i = 0; i < height; i++) {
		buf[i] = new char[width];
		memset(buf[i], ' ', width);
	}
}

Terminal::~Terminal() {
	for (int i = 0; i < height; i++) {
		delete[] buf[i];
	}
	delete[] buf;
}

int Terminal::getHeight() const {
	return height;
}

int Terminal::getWidth() const {
	return width;
}

void Terminal::clear() {
	for (int i = 0; i < height; i++) {
		memset(buf[i], ' ', width); 
	}
}

void Terminal::write(std::string arg, int x, int y) {
	if (x < -1 || x >= width || y < -1 || y >= height) {
		return;
	}
	if (x == -1) {
		x = (width - arg.size())/2;
	}
	if (y == -1) {
		y = (height - 1)/2;
	}
	for (int i = x; i < x + arg.length() && i < width; i++) {
		buf[y][i] = arg.at(i - x);
	}
}

void Terminal::display() const {
	std::string s;
	#ifdef linux
		system("clear");
	#else
		system("cls");
	#endif
	for (int i = 0; i < height; i++) {
		s = "";
		for(int j = 0; j < width; j++) {
			s += buf[i][j];
		}
		std::cout << s << std::endl;
	}
}