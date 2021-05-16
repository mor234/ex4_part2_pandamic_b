//1. חוקרת - `Researcher`: יכולה לבצע פעולת "גילוי תרופה" בכל עיר - לא חייבת להיות בתחנת מחקר.
#include "Researcher.hpp"
#include "Player.hpp"
#include "Color.hpp"

#include <string>

using namespace std;

namespace pandemic {
    /**
     * @brief 
     * 
     * @return string of player role
     */
    string Researcher::role() {
        return "Researcher";
    }
    /**
     * @brief discover cure without being in a study station
     * 
     * @param color 
     * @return Player& 
     */
    Player & Researcher::discover_cure(const Color & color) 
    {
        if (!_board->color_has_cure(color)) 
        {
            if (has_x_color_cards(color)) 
            {
                throw_x_color_cards(color);
                _board->color_has_cure(color) = true;
            } 
            else 
            {
                throw invalid_argument{"Error. can't discover cures without enough cards in the maching color"};
            }
        }
        return *this;
    }
}

