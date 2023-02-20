#include<iostream>
#include<fstream>
#include<filesystem>
#include<nlohmann/json.hpp>

void make_character(const std::string &fname)
{
    std::ifstream f(fname);
    nlohmann::json data = nlohmann::json::parse(f);
    std::cout << "Make character: " << data["name"].get<std::string>() << std::endl;
    std::ofstream fout;
    fout.open("../src_lib/pers/diluc.h");
    fout << "#include<headers/g_lib.h>" << std::endl;
    fout << std::endl;
    fout << std::endl;
    fout << "namespace genshin_lib {" << std::endl;
    fout << "class diluc : public character" << std::endl;
    fout << "{" << std::endl;
    fout << "public:" << std::endl;
    fout << "diluc() : character(" << data["name"] << ", element::" << data["element"].get<std::string>() << ", " << data["title"] << ") {}" << std::endl;
    fout << "};" << std::endl;
    fout << "}" << std::endl;
    fout.close();
}

int main()
{
    std::string path = "data/json/";
    for (const auto &entry : std::filesystem::directory_iterator(path))
        make_character(entry.path());
    return 0;
}
