#include <iostream>
#include <string>
#include <regex>
#include <vector>
//buscador de url y sus sitios que coincidan con el nombre
std::vector<std::string> FindURLs(const std::string& input)
{
    std::vector<std::string> urls;
    std::regex urlRegex(R"(https?://[^\s/$.?#].[^\s]*)");

    std::sregex_iterator it(input.begin(), input.end(), urlRegex);
    std::sregex_iterator end;

    while (it != end)
    {
        urls.push_back(it->str());
        ++it;
    }

    return urls;
}

void PrintBanner()
{
    std::string banner =
        "  ____        _   _      _     \n"
        " |  _ \\      | | | |    | |    \n"
        " | |_) | __ _| |_| | ___| |__  \n"
        " |  _ < / _` | __| |/ _ \\ '_ \\ \n"
        " | |_) | (_| | |_| |  __/ |_) |\n"
        " |____/ \\__,_|\\__|_|\\___|_.__/ \n";

    std::cout << banner << std::endl;
}

int main()
{
    PrintBanner();

    std::string userInput;
    std::cout << "Ingrese un texto que pueda contener URLs: ";
    std::getline(std::cin, userInput);

    std::vector<std::string> foundURLs = FindURLs(userInput);

    if (foundURLs.empty())
    {
        std::cout << "No se encontraron URLs en el texto ingresado." << std::endl;
    }
    else
    {
        std::cout << "URLs encontradas:" << std::endl;
        for (const std::string& url : foundURLs)
        {
            std::cout << url << std::endl;
        }
    }

    return 0;
}
