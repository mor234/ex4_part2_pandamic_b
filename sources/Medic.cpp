//1. פראמדיק - `Medic`: כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
//   * אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נמצא בה, גם בלי לבצע פעולת "טיפול במחלה".
#include "Medic.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
    
    /**
     * @brief remove sickness cubes from current city,if the cures exists.
     * to be used in other functions
     */
    void Medic::has_cure_zero()
    {
        if(_board->color_has_cure(Board::color_for_city(_current_city)))
        {
                (*_board)[_current_city]=0;
        }
    }

    /**
     * @brief Construct a new Medic:: Medic object,
     * if has cure- remove sickness cubes from current city
     * 
     * @param board 
     * @param city 
     */
    Medic::Medic( Board & board, const City & city):Player(board,city){
        has_cure_zero();
    }
    /**
     * @brief 
     * 
     * @return string of player role 
     */
    string Medic::role(){
        return "Medic";
    }
    /**
     * @brief remove all sickness cubes from current city
     * 
     * @param city 
     * @return Player& 
     */
    Player &Medic::treat(const City & city) {
    if (city != _current_city) {
        throw invalid_argument{"can't treat a city without being in it."};
    }
    if ((*_board)[city] > 0) {
        (*_board)[city]=0;
    } else {
        throw invalid_argument{"Error. can't treat a healthy city."};
    }
    return *this;
    }
    //----------------------------------
    // remove all sickness cubes from every city he enters- if has cure.
    //----------------------------------
    Player & Medic::drive(const City & city)
    {
        City early_city=_current_city;
        Player::drive(city);
        //if changed location 
        if(_current_city!=early_city)
        {
            has_cure_zero();
        }
        return *this;

    }
    Player & Medic::fly_direct(const City & city){
        City early_city=_current_city;
        Player::fly_direct(city);
        //if changed location
        if(_current_city!=early_city)
        {
            has_cure_zero();
        }
        return *this;

    }
    Player & Medic::fly_charter(const City & city)
    {
        City early_city=_current_city;
        Player::fly_charter(city);
        //if changed location
        if(_current_city!=early_city)
        {
            has_cure_zero();
        }
        return *this;

    }
    Player & Medic::fly_shuttle(const City & city){
        City early_city=_current_city;
        Player::fly_shuttle(city);
        //if changed location
        if(_current_city!=early_city)
        {
            has_cure_zero();
        }
        return *this;
    }
}

