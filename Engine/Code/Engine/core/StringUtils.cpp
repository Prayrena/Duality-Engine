#include "Engine/Core/StringUtils.hpp"
#include <stdarg.h>

//-----------------------------------------------------------------------------------------------
constexpr int STRINGF_STACK_LOCAL_TEMP_LENGTH = 2048;


//-----------------------------------------------------------------------------------------------
const std::string Stringf( char const* format, ... )
{
	char textLiteral[ STRINGF_STACK_LOCAL_TEMP_LENGTH ];
	va_list variableArgumentList;
	va_start( variableArgumentList, format );
	vsnprintf_s( textLiteral, STRINGF_STACK_LOCAL_TEMP_LENGTH, _TRUNCATE, format, variableArgumentList );	
	va_end( variableArgumentList );
	textLiteral[ STRINGF_STACK_LOCAL_TEMP_LENGTH - 1 ] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	return std::string( textLiteral );
}


//-----------------------------------------------------------------------------------------------
const std::string Stringf( int maxLength, char const* format, ... )
{
	char textLiteralSmall[ STRINGF_STACK_LOCAL_TEMP_LENGTH ];
	char* textLiteral = textLiteralSmall;
	if( maxLength > STRINGF_STACK_LOCAL_TEMP_LENGTH )
		textLiteral = new char[ maxLength ];

	va_list variableArgumentList;
	va_start( variableArgumentList, format );
	vsnprintf_s( textLiteral, maxLength, _TRUNCATE, format, variableArgumentList );	
	va_end( variableArgumentList );
	textLiteral[ maxLength - 1 ] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	std::string returnValue( textLiteral );
	if( maxLength > STRINGF_STACK_LOCAL_TEMP_LENGTH )
		delete[] textLiteral;

	return returnValue;
}

//Strings SplitStringOnDelimiter(std::string const& originalString, char delimiterToSplitOn)
//{
//	Strings newStrings; // list of string for output
//	std::string singleString; // temp store for single string
//
//	for (int charIndex = 0; charIndex < originalString.size(); ++charIndex)
//	{
//		if (originalString[charIndex] != delimiterToSplitOn)// if it is not the same as the split char, 
//		{
//			singleString.push_back(originalString[charIndex]);// push the char into the temp char array
//		}
//		else
//		{
//			newStrings.push_back(singleString);// put the temp string into the list of string
//			singleString.clear();// clear up the temp string for the next loop
//		}
//	}
//	newStrings.push_back(singleString);// put the rest of the temp string into the strings
//	return newStrings;
//	//----------------------------------------------------------------------------------------------------------------------------------------------------
//	// std::size_t found = originalString.find_first_of(delimiterToSplitOn);
//	// int subStringStart = 0;
//	// int startOfSubstr = 0;
//	// int delimziterIndex = 0;
//	// while (found != std::string::npos)
//	// {
//	// 	singleString = originalString.substr(subStringStart, found);
//	// 	newStrings.push_back(singleString);
//	// 	restOfString = originalString.substr((found + 1));
//	// 	subStringStart = found + 1;
//	// 	found = found + 1 + restOfString.find_first_of(delimiterToSplitOn);		
//	// }
//	// newStrings.push_back(restOfString);
//	// return newStrings;
//}

Strings SplitStringOnDelimiter(std::string const& originalString, char const& delimiterToSplitOn, bool removeEmpty /*= false*/)
{
	std::string tempString;								// temp store for single string
	std::vector<std::string> StringsCollection;			// list of string for output

	for (int charIndex = 0; charIndex < (int)(originalString.size()); ++charIndex)
	{
		char currentChar = originalString[charIndex];

		if (currentChar != delimiterToSplitOn && !removeEmpty)// if it is not the same as the split char and it is not ' '
		{
			tempString.push_back(currentChar);// push the char into the temp char array
		}
		else
		{
			
			if (removeEmpty) // remove space as well
			{
				if (currentChar == delimiterToSplitOn || originalString[charIndex] == ' ')
				{
					if (!tempString.empty())
					{
						StringsCollection.push_back(tempString);	// put the temp string into the list of string
						tempString.clear();				// clear up the temp string for the next loop
					}
					else
					{
						continue;
					}
				}
				continue;
			}
			else // remove only delimiter
			{
				if (currentChar == delimiterToSplitOn) // need to remove the char
				{
					if (!tempString.empty()) //temp string is not empty
					{
						StringsCollection.push_back(tempString);	// put the temp string into the list of string
						tempString.clear();				// clear up the temp string for the next loop
					}
					else // temp string is empty, check the next char
					{
						continue;
					}
				}
				else // no need to remove the char, add the char to the temp string
				{
					tempString.push_back(currentChar);// push the char into the temp char array
				}
			}
		}
	}

	if (!tempString.empty())
	{
		StringsCollection.push_back(tempString);// put the rest of the temp string into the strings
	}
	Strings result = StringsCollection; // ???????????????????????????????????????????????????????????????????????????????????
	return result;
}

int SplitStringOnDelimiter(Strings& outSplitStrings, std::string const& originalString, std::string const& delimiterToSplitOn)
{
	unsigned int start = 0;
	unsigned int end = (unsigned int)originalString.find(delimiterToSplitOn);

	// Clear the output vector to ensure it's empty before adding new elements
	outSplitStrings.clear();

	// Loop until no more delimiter is found in the original string
	while (end != static_cast<unsigned int>(std::string::npos)) 
	{
		// Extract the substring and add it to the output vector
		outSplitStrings.push_back(originalString.substr(start, end - start));

		// Move the starting index forward to search for the next part of the string
		start = end + (unsigned int)delimiterToSplitOn.length();
		end = (unsigned int)originalString.find(delimiterToSplitOn, start);
	}

	// Add the remaining part of the string after the last delimiter
	outSplitStrings.push_back(originalString.substr(start));

	// Return the number of split strings
	return static_cast<unsigned int>(outSplitStrings.size());
}

void GetTokensOfAllLines(Strings const& lines, std::vector<Strings>& tokensOfAllLines)
{
	for (auto line : lines)
	{
		Strings tokensOfEachLine = SplitStringOnDelimiter(line, ' ');
		tokensOfAllLines.push_back(tokensOfEachLine);
	}
}


