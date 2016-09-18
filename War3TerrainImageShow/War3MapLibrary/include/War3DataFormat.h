#ifndef WAR3DATAFORMATE_H
#define WAR3DATAFORMATE_H

#include <math.h>

namespace LibraryWar3Map
{
	int War3DataFormatGetStoredBytesValue(char *bytes, int len)
	{
		int value = 0;
		int i = 0;
		for (size_t i = 0; i < len; i++)
		{
			value += WAR3DEFINE_COMMON_DATA_TRANSLATE(bytes[i]) << (i * 8);
		}
		return value;
	}

	double War3DataFormatGetFloatMantissaFromBin(int binValue)
	{
		int tempValue = binValue;
		double floatValue = 0;
		int count = 0;
		int position = 0x400000;
		while (tempValue != 0)
		{
			count--;
			floatValue += pow(2.0, (count)) * ((tempValue & position) != 0);
			tempValue = tempValue & (~position);
			position = position >> 1;
		}
		return floatValue;
	}

	float War3DataFormatGetFloatFromHex(int hexValue)
	{
		int signValue = hexValue >> 31;
		int exponentValue = (hexValue & 0x7F800000) >> 23;
		int mantissaValue = (hexValue & 0x7FFFFF);
		return (float)(pow(-1.0, signValue) * (1 + War3DataFormatGetFloatMantissaFromBin(mantissaValue)) * pow(2.0, (exponentValue - 127)));
	}
}
#endif // WAR3DATAFORMATE_H

