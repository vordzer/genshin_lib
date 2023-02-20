#include<iostream>
#include<g_lib.h>
#include<pers/diluc.h>

namespace genshin_lib {

//////////////////////////////////////////////////////////////
//------------------------------------------------------------
character::character(const std::string &n, const element e, const std::string &t)
  : name(n), el(e), title(t)
{
}
//------------------------------------------------------------
const std::string &character::get_name() const
{
    return name;
}
//------------------------------------------------------------
element character::get_element() const
{
    return el;
}
//------------------------------------------------------------
const std::string &character::get_element_str() const
{
    return el_to_str.at(el);
}
//------------------------------------------------------------
const std::string &character::get_title() const
{
    return title;
}
//------------------------------------------------------------
character *character::create_character(const std::string & )
{
    return new diluc();
}
//------------------------------------------------------------
//////////////////////////////////////////////////////////////
}
