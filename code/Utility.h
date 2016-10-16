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
std::ostream& operator << (std::ostream& outStream, const std::vector<T>& vec)
{
	outStream << "Vector Size : " << vec.size() << endl;

	for each (const T& value in vec)
	{
		outStream << value << '\t';
	}

	return outStream;
}