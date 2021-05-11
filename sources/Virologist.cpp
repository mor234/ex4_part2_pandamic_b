//1. וירולוגית - `Virologist`: יכולה לבצע פעולת "טיפול במחלה", לא רק בעיר  שהיא נמצאת בה, אלא בכל עיר בעולם - ע"י השלכת קלף של אותה העיר.

#include "Virologist.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
   
    string Virologist::role(){
        return "Virologist";
    }
    Player & Virologist::treat(City city){
        if (_board.sickness_cubes(city) > 0) {
            _board.sickness_cubes(city)--;
            if (_board.color_has_cure(_board.color_for_city(city))) {
                _board.sickness_cubes(city) = 0;//if discovered a cure- remove all sickness cubes
            }
        } else {
            throw invalid_argument{"Error. can't treat a healthy city."};
        }
        return *this;
    }
}