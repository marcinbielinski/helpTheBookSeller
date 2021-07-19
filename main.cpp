#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt,
                                    std::vector<std::string> &categories)
    {
        std::string result;
        std::map <char, size_t> mapOfCat;

        if (lstOfArt.empty())
        {
            result += "";
            return result;
        }
        if (categories.empty())
        {
            result += "";
            return result;
        }

        for (int i = 0; i < lstOfArt.size(); i++)
        {
            for (int j = 0; j < categories.size(); j++)
            {
                if ( lstOfArt[i].front() == categories[j].front() )
                {
                    auto it = std::find(begin(lstOfArt[i]), end(lstOfArt[i]), ' ');
                    std::string my_num {it + 1, end(lstOfArt[i])};
                    auto strToInt = std::stoi(my_num);
                    mapOfCat[lstOfArt[i][0]] += strToInt;
                }
            }
        }

        for (int i = 0; i < categories.size(); i++)
        {
            std::string oof = "(" + categories[i] + " : " + std::to_string(mapOfCat[categories[i][0]]) + ")";
            result += oof;
            if (i != categories.size() - 1)
            {
                result += " - ";
            }
        }

        return result;
    }
};
int main() {
    std::vector<std::string> L =
            {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"};
    std::vector<std::string> M = {"A", "B", "C", "W"};
    std::vector<std::string> X = {"U", "V", "W", "T", "H", "L"};


    StockList::stockSummary(L, M);
    std::cout << StockList::stockSummary(L, M);

    std::cout << StockList::stockSummary(L, X);
    return 0;
}
