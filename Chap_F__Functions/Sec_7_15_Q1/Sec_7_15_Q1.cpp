#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//#include<functional>

struct Student {
    std::string name;
    int points;
};

int main() 
{
    std::vector<Student> vec{
    { 
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };
    
    /*
    1) Fully explicit (including <functional> header): 

    std::function<bool(const Student&, const Student&)> hasBetterGrade{
        [](const Student& stud_i, const Student& stud_j) -> bool {
            return stud_i.points < stud_j.points;
        }
    };

    2) Using the "auto" to infer the type of the lambda:

    auto hasBetterGrade{
        [](const Student& stud_i, const Student& stud_j) -> bool {
            return stud_i.points < stud_j.points;
        }
    };
    
    3) Making also the lambda fully generic, making it work with any struct/class having "points" as a data member:
    */

    auto hasBetterGrade{
        [](const auto& stud_i, const auto& stud_j) -> bool {
            return stud_i.points < stud_j.points;
        }
    };

    /*
    We don't care about the type of the iterator returned by std::max_element, 
    But, explicitly: iter_stud is of type std::vector<Student>::iterator
    
    If 'auto' is used, iter_stud must be initialized.
    */
    auto iter_stud{ std::max_element(vec.begin(), vec.end(), hasBetterGrade) };

    std::cout << iter_stud->name << " is the best students (points = " << iter_stud->points << ")\n";

    return 0;
}