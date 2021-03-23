#ifndef STOKEN_HPP
#define STOKEN_HPP
#include <vector>
#include <string>

/**
 * @brief Create String Tokens based on expression. If 
 * expression is "4+3.1", output would be ["4" "+", "3.1"]
 * 
 * @param str Expression to be parsed
 * @return std::vector<std::string> Vector of strings.
 */
std::vector<std::string> STokens(const char* str);

std::vector<int> GetOperatorMarkers(const char* str);

#endif // STOKEN_HPP