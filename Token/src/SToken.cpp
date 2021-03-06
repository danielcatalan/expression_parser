#include "SToken.hpp"
#include "Operators.hpp"
#include <array>
#include <algorithm>

std::vector<std::string> STokens(const char* cstr)
{
    std::vector<std::string> stokens;
    std::string str = cstr;

    auto positions = FindOperatorMarkers(cstr);
    auto start = 0;
    
    for(auto& p : positions)
    {
        auto length = p-start;
        stokens.push_back(str.substr(start, length));
        start = p;
        stokens.push_back(str.substr(start, 1));
        start = p+1;
    }

    auto end = str.size();
    auto length = end - start;
    stokens.push_back(str.substr(start, length));

    return stokens;
}


std::vector<int> FindOperatorMarkers(const char* cstr)
{
    std::vector<int> positions;
    std::array<char const *,2> delims = GetSOperators();
    std::string str = cstr;
    


    for(auto& d : delims)
    {
        auto start = 0;
        auto pos = 0;
        while (true)
        {
            pos = str.find(d, start);

            if(pos == std::string::npos)
            {
                break;
            }
            positions.push_back(pos);
            start = pos+1;
        }
    }
    std::sort(positions.begin(), positions.end());

    return positions;
}
