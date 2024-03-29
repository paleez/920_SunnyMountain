// 920_SunnyMountain_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

struct Point { int x, y; };
double distance(Point &p1, Point &p2)
{
	return std::sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
};
bool compare(const Point p1, const Point p2) { return p2.x < p1.x; };

int main()
{
	int tc;
	std::cin >> tc;
	while ( tc-- )
	{
		int nop;
		int size = 0;
		std::cin >> nop;
		std::vector<Point> vec(nop);
		
		for (size_t i = 0; i < nop; i++)
		{
			int x, y;
			std::cin>> x >> y;
			vec[i].x = x;
			vec[i].y = y;
			size++;
		}
		std::sort(vec.begin(), vec.end(), compare);
		int cmy = 0;
		double length = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (vec[i].y > cmy)
			{
				length += distance(vec[i], vec[i - 1]) * (vec[i].y - cmy) / (vec[i].y - vec[i - 1].y);
				cmy = vec[i].y;
			}
		}
		std::cout << std::fixed << std::setprecision(2) << length << std::endl;
	}
	return 0;
}

