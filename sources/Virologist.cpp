//1. וירולוגית - `Virologist`: יכולה לבצע פעולת "טיפול במחלה", לא רק בעיר  שהיא נמצאת בה, אלא בכל עיר בעולם - ע"י השלכת קלף של אותה העיר.

#include "Virologist.hpp"
#include "Player.hpp"
#include <string>

using namespace std;

namespace pandemic {
    /**
     * @brief 
     * 
     * @return string of player role
     */
    string Virologist::role() {
        return "Virologist";
    }

    /**
     * @brief can treat other city if has card, if it's own city- doesn't need a card
     * 
     * @param city 
     * @return Player& 
     */
    Player &Virologist::treat(const City &city) {
        if (city == _current_city) {
            return Player::treat(city);
        }
        if ((*_board)[city] > 0) //if has sickness cubes, done only when city!=_current_city
        {
            if (!has_card(city)) {
                throw invalid_argument{"Error. can't treat city without matching card."};
            }
            throw_card(city);
            (*_board)[city]--;
            if (_board->color_has_cure(Board::color_for_city(city))) {
                (*_board)[city] = 0;//if discovered a cure- remove all sickness cubes
            }

        } else {
            throw invalid_argument{"Error. can't treat a healthy city."};
        }
        return *this;
    }
}

