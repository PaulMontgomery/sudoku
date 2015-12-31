#include <assert.h>

#include "square.h"


Square::Square()
{
    // Initialize each square with all possible values from 1 to 9
    for (int counter = 1; counter <= 9; counter++)
    {
        possible_vals.insert(counter);
    }
}

bool Square::is_val_possible(const int &val)
{
    std::set<int>::iterator it;
    it = possible_vals.find(val);
    if (it != possible_vals.end())
    {
        return(true);
    }
    return(false);
}

void Square::remove_val(const int &val)
{
    assert(possible_vals.size() > 0);
    if (possible_vals.size() == 1)
    {
        assert(val != get_first_val());
    }
    possible_vals.erase(val);
}

void Square::set_final_val(const int &val)
{
    possible_vals.clear();
    possible_vals.insert(val);
}

bool Square::is_final_val()
{
    if (possible_vals.size() == 1)
    {
        return(true);
    }
    return(false);
}

int Square::get_first_val()
{
    auto iter = possible_vals.begin();
    return(*iter);
}


/* todo remove this
int main(int argc, char *argv[])
{
    Square box;
    std::cout << "Final start: " << box.is_final_val() << std::endl;
    std::cout << "A: " << box.is_val_possible(5) << std::endl;
    box.remove_val(5);
    std::cout << "B: " << box.is_val_possible(5) << std::endl;
    box.set_final_val(6);
    std::cout << "C: " << box.is_val_possible(6) << std::endl;
    std::cout << "D: " << box.is_val_possible(7) << std::endl;
    std::cout << "Final end: " << box.is_final_val() << std::endl;

    return 0;
}
*/
