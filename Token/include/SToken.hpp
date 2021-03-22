#ifndef STOKEN_HPP
#define STOKEN_HPP
#include <vector>
#include <string>

std::vector<std::string> STokens(const char* str);

std::vector<int> GetOperatorMarkers(const char* str);

#endif // STOKEN_HPP