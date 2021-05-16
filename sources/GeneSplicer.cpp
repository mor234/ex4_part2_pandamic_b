//1. פורסת גנים - `GeneSplicer`: יכולה לבצע פעולת "גילוי תרופה" בעזרת 5 קלפים כלשהם - לא דווקא מהצבע של המחלה.
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include <string>

using namespace std;

namespace pandemic {
    /**
     * @brief 
     * 
     * @return string of player role 
     */
    string GeneSplicer::role() {
        return "GeneSplicer";
    }

    /**
     * @brief discover cure by throwing 5 cards in a city with study station
     * 
     * @param color 
     * @return Player& 
     */
    Player &GeneSplicer::discover_cure(const Color &color) {
        if (_board->color_has_cure(color)) {
            return *this;
        }
        if (_board->has_study_station(_current_city)) {
            if (_cards.size() >= CARDS_FOR_CURE) {
                int cards_for_cure = CARDS_FOR_CURE;
                for (auto card_itr = _cards.begin(); card_itr != _cards.end();) {
                    // Remove string from set if length is greater than 3.
                    card_itr = _cards.erase(card_itr);
                    cards_for_cure--;
                    if (cards_for_cure == 0) {
                        break;
                    }

                }
                _board->color_has_cure(color) = true;
            } else {
                throw invalid_argument{"Error. can't discover cures without enough cards."};
            }
        } else {
            throw invalid_argument{"Error. can't discover cures without study station in the city"};
        }
        return *this;
    }
}