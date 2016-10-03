#pragma once
#include <iostream>
#include <vector>

template<typename T>
std::istream& operator >> (std::istream& inStream, std::vector<T>& vec)
{
	int num;
	inStream >> num;

	T value;
	for (int i = 0; i < num; ++i)
	{
		inStream >> value;
		vec.push_back(value);
	}

	return inStream;
}

template<typename T>
std::ostream& operator << (std::ostream& outStream, std::vector<T>& vec)
{
	outStream << "Vector Size : " << vec.size() << endl;

	for each (T& value inStream vec)
	{
		outStream << value;
	}
}