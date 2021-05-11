// רופא שטח - `FieldDoctor`: יכול לבצע פעולת "טיפול במחלה" לא רק בעיר שהוא נמצא בה אלא בכל עיר סמוכה לעיר שהוא נמצא
// בה (ע"פ מפת הקשרים), בלי להשליך קלף עיר.
#include "FieldDoctor.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
   
    string FieldDoctor::role(){
        return "FieldDoctor";
    }
    Player &Player::treat(City city) {
        bool isNearCity=false;
        for(City n_city:_board.near_cities(city))
        {
            if(n_city==city)
            {
                isNearCity=true;
                break;
            }
        }
        if (city != _current_city &&!isNearCity) {
            throw invalid_argument{"can't treat a city without being in it or near it."};
        }
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