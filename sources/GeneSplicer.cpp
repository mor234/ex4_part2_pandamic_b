//1. פורסת גנים - `GeneSplicer`: יכולה לבצע פעולת "גילוי תרופה" בעזרת 5 קלפים כלשהם - לא דווקא מהצבע של המחלה.
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
   
    string GeneSplicer::role(){
        return "GeneSplicer";
    }
    
    Player &GeneSplicer::discover_cure(Color color) {
        if (_board.has_study_station(_current_city)){
            if (!_board.color_has_cure(color)) {
                if (_cards.size()>=5) {
                    int i=CARDS_FOR_CURE;
                    for(auto card:_cards)
                    {
                        throw_card(card);
                        i--;
                        if(i==0)
                        {
                            break;
                        }
                    }
                    _board.color_has_cure(color) = true;
                } else {
                    throw invalid_argument{"Error. can't discover cures without enough cards."};
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