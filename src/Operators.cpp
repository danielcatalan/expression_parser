#include "Operators.hpp"
#include <tuple>


enum class  Ops: int
{
    Add,
    Sub
};

std::array< std::tuple<const char*, const Ops>, 2> Operators = {
    std::make_tuple("+", Ops::Add),
    std::make_tuple("-", Ops::Sub) };

 

 std::array<const char*, 2> GetSOperators()
{
    // std::vector<std::string> sop;

    // for(auto& op : Operators)
    // {
    //     sop.push_back( std::get<0>(op) );
    // }
    // std::vector<std::string> sop = {"+", "-"};
    return std::array<const char*, 2> ({"+","-"});
}


