#include "SToken.hpp"
#include <array>

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