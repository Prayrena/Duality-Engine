#pragma once
#include <vector>
//-----------------------------------------------------------------------------------------------
#include <string>
typedef std::vector<std::string> Strings;

//-----------------------------------------------------------------------------------------------
const std::string Stringf( char const* format, ... );
const std::string Stringf( int maxLength, char const* format, ... );

Strings SplitStringOnDelimiter(std::string const& originalString, char const& delimiterToSplitOn, bool removeEmpty = false);
int SplitStringOnDelimiter(Strings& outSplitStrings, std::string const& originalString, std::string const&  delimiterToSplitOn);
void GetTokensOfAllLines(Strings const& lines, std::vector<Strings>& tokensOfAllLines);


