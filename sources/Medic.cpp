//1. פראמדיק - `Medic`: כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
//   * אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נמצא בה, גם בלי לבצע פעולת "טיפול במחלה".
#include "Medic.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
   
    string Medic::role(){
        return "Medic";
    }
    Player &Medic::treat(City city) {
    if (city != _current_city) {
        throw invalid_argument{"can't treat a city without being in it."};
    }
    if (_board.sickness_cubes(city) > 0) {
        _board.sickness_cubes(city)=0;
    } else {
        throw invalid_argument{"Error. can't treat a healthy city."};
    }
    return *this;
    }
    Player &Medic::discover_cure(Color color)
     {
        Player::discover_cure(color);
        //if discover cure succeeded
        if (_board.color_has_cure(_board.color_for_city(_current_city))) {
            _board.sickness_cubes(_current_city) = 0;//if discovered a cure- remove all sickness cubes
        }
        return *this;
    }
}

