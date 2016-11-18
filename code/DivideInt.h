#pragma once
#include <limits.h>


class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		if (divisor == 0)
		{
			return INT_MAX;
		}

		int flag = (dividend & 0x80000000) ^ (divisor & 0x80000000);

		unsigned int udividend = dividend < 0 ? -dividend : dividend;
		unsigned int udivisor = divisor < 0 ? -divisor : divisor;

		int maxBitLoc = 32;
		unsigned int ures = 0;
		while (maxBitLoc > 0 && udividend >= udivisor)
		{
			for (int i = 0; i < maxBitLoc; ++i)
			{
				unsigned int decline = udivisor << i;
				unsigned int left = udividend - decline;

				if (left < decline)
				{
					maxBitLoc = i;
					udividend = left;
					ures |= 1 << i;

					break;
				}
			}
		}

		int res;
		if (flag != 0)
		{
			res = ures > INT_MAX? INT_MIN : -(int)ures;
		}
		else
		{
			res = ures > INT_MAX ? INT_MAX : ures;
		}
		
		return res;
	}
};