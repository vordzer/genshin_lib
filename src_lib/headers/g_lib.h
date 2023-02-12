#ifndef G_LIB_H
#define G_LIB_H

#include<string>
#include<element.h>

namespace genshin_lib {

//////////////////////////////////////////////////////////////
//------------------------------------------------------------
class character
{
public:
    character(const std::string & , const element , const std::string & );
    const std::string &get_name() const;
    element get_element() const;
    const std::string &get_element_str() const;
    const std::string &get_title() const;
private:
    std::string name;
    element el;
    std::string title;
    std::unordered_map<element, const std::string> el_to_str
    {
        {element::pyro, "pyro"},
        {element::hydro, "hydro"},
        {element::cryo, "cryo"},
        {element::electro, "electro"},
        {element::anemo, "anemo"},
        {element::geo, "geo"},
        {element::dendro, "dendro"}
    };
};
//------------------------------------------------------------
//////////////////////////////////////////////////////////////
}

#endif // G_LIB_H
