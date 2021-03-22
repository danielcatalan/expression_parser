#include "SToken.hpp"
#include <array>

std::vector<std::string> STokens(const char* cstr)
{
    std::vector<std::string> stokens;
    std::string str = cstr;

    auto positions = GetOperatorMarkers(cstr);
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

std::vector<int> GetOperatorMarkers(const char* cstr)
{
    std::vector<int> positions;
    std::array<std::string, 2> delims = {"+", "-"};
    std::string str = cstr;
    
    auto start = 0;
    auto pos = 0;

    for(auto& d : delims)
    {
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


    return positions;
}
