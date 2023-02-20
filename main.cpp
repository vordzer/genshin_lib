#include<iostream>
#include<g_lib.h>

int main()
{
    genshin_lib::character *diluc = genshin_lib::character::create_character("Diluc");
    std::cout << diluc->get_name() << std::endl;
    std::cout << diluc->get_element_str() << std::endl;
    std::cout << diluc->get_title() << std::endl;
    return 0;
}
