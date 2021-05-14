//1. פראמדיק - `Medic`: כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
//   * אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נמצא בה, גם בלי לבצע פעולת "טיפול במחלה".
#include "Medic.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

namespace pandemic{
    //remove sickness cubes from current city,if the cures exists.
    void Medic::treat_no_throws()
    {
        if(_board->color_has_cure(Board::color_for_city(_current_city)))
        {
                (*_board)[_current_city]=0;
        }
    }

    Medic::Medic( Board & board, const City & city):Player(board,city){
        treat_no_throws();
    }

    string Medic::role(){
        return "Medic";
    }
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
    // Player &Medic::discover_cure(const Color & color)
    //  {
    //     Player::discover_cure(color);
    //     //if discover cure succeeded
    //     if (_board->color_has_cure(Board::color_for_city(_current_city))) {
    //         (*_board)[_current_city] = 0;//if discovered a cure- remove all sickness cubes
    //     }
    //     return *this;
    // }

    Player & Medic::drive(const City & city)
    {
        City early_city=_current_city;
        Player::drive(city);
        //if changed location 
        if(_current_city!=early_city)
        {
            treat_no_throws();
        }
        return *this;

    }
    Player & Medic::fly_direct(const City & city){
        City early_city=_current_city;
        Player::fly_direct(city);
        //if changed location
        if(_current_city!=early_city)
        {
            treat_no_throws();
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
            treat_no_throws();
        }
        return *this;

    }
    Player & Medic::fly_shuttle(const City & city){
        City early_city=_current_city;
        Player::fly_shuttle(city);
        //if changed location
        if(_current_city!=early_city)
        {
            treat_no_throws();
        }
        return *this;
    }
}

