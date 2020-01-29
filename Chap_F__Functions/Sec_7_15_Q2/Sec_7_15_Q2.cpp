#include <algorithm>
#include <vector>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::vector<Season> seasons{
     { { "Spring", 285.0 },
       { "Summer", 296.0 },
       { "Fall", 288.0 },
       { "Winter", 263.0 } }
    };

    /*
    1) Fully explicit (including <functional> header):

    std::function<bool(const Season&, const Season&)> isWarmer{
        [](const Season& season_i, const Season& season_j) -> bool {
            return season_i.averageTemperature < season_j.averageTemperature;
        }
    };

    2) Using the "auto" to infer the type of the lambda:

    auto isWarmer{
        [](const Season& season_i, const Season& season_j) -> bool {
            return season_i.averageTemperature < season_j.averageTemperature;
        }
    };

    3) Making also the lambda fully generic, making it work with any struct/class having "averageTemperature" as a data member:
    */

    auto isWarmer{
        [](const auto& season_i, const auto& season_j) -> bool {
            return season_i.averageTemperature < season_j.averageTemperature;
        }
    };

    /*
    We don't care about the type of the iterator returned by std::max_element,
    But, explicitly: iter_stud is of type std::vector<Student>::iterator

    If 'auto' is used, iter_stud must be initialized.
    */
    std::sort(seasons.begin(), seasons.end(), isWarmer);

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}