#include<iostream>
#include<fstream>
#include<nlohmann/json.hpp>

int main()
{
    std::ifstream f("data/json/diluc.json");
    nlohmann::json data = nlohmann::json::parse(f);
    std::cout << data["name"] << std::endl;
    std::ofstream fout;
    fout.open("../src_lib/pers/diluc.h");
    fout << "#include<headers/g_lib.h>" << std::endl;
    fout << std::endl;
    fout << std::endl;
    fout << "namespace genshin_lib {" << std::endl;
    fout << "class diluc : public character" << std::endl;
    fout << "{" << std::endl;
    fout << "public:" << std::endl;
    fout << "diluc() : character(" << data["name"] << ", element::pyro, " << data["title"] << ") {}" << std::endl;
    fout << "};" << std::endl;
    fout << "}" << std::endl;
    fout.close();
    return 0;
}
