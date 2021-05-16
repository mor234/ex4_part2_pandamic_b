//1. קצין תעבורה - `Dispatcher`: כשהוא נמצא בתחנת-מחקר, הוא יכול לבצע פעולת "טיסה ישירה" לכל עיר שהוא רוצה, ללא השלכת קלף-עיר.
#include "Dispatcher.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
   /**
    * @brief  
    * @return string of player role 
    */
    string Dispatcher::role(){
        return "Dispatcher";
    }
    /**
     * @brief move to every city without throwing card if in city with study station
     * 
     * @param city 
     * @return Player& 
     */
    Player &Dispatcher::fly_direct(const City & city) {
        if(city==_current_city)
        {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        if(_board->has_study_station(_current_city))
        {
            _current_city=city;
        }
        else
        {
            Player::fly_direct(city);
        }
        return *this;
    }
}