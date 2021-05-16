//1. מדענית - `Scientist`: יכולה לבצע פעולת "גילוי תרופה" בעזרת `n` קלפים בלבד (במקום 5)
//, כאשר הפרמטר `n` מועבר בבנאי (במשחק המקורי `n=4`).
#include "Scientist.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
    /**
     * @brief Construct a new Scientist:: Scientist object
     * keep the amount of cards needed for discovering cure
     * @param board 
     * @param city 
     * @param num 
     */
    Scientist::Scientist(Board & board, const City & city, const int & num):Player(board,city),_cards_needed_for_cure(num)
    {
        if(_cards_needed_for_cure<0)
        {
            _cards_needed_for_cure=0;
            throw out_of_range{"Error. number of cards can't be negative"};
        }
    }   
    /**
     * @brief 
     * 
     * @return string of player role
     */
    string Scientist::role(){
        return "Scientist";
    }
    /**
     * @brief discover cure but with the amount of cards given in initialization
     * 
     * @param color of cure to discover
     * @return Player& 
     */
    Player & Scientist::discover_cure(const Color & color){
        if (_board->has_study_station(_current_city)){
            if (!_board->color_has_cure(color)) {
                if (has_x_color_cards(color,_cards_needed_for_cure)) {
                    throw_x_color_cards(color,_cards_needed_for_cure);
                    _board->color_has_cure(color) = true;
                } else {
                    throw invalid_argument{"Error. can't discover cures without enough cards in the maching color"};
                }
            }
        } 
        else
        {
            throw invalid_argument{"Error. can't discover cures without study station in the city"};
        }
        return *this;
    }
}