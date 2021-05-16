//1. פראמדיק - `Medic`: כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
//   * אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נמצא בה, גם בלי לבצע פעולת "טיפול במחלה".
#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
    class Medic:public Player
    {   private:
            void has_cure_zero();

        public:
            Medic ( Board & board, const City & city);
            virtual std::string role() override; 
            // virtual Player &discover_cure(const Color & color) override;
            virtual Player &treat(const City & city) override;

            virtual Player & drive(const City & city)override;
            virtual Player & fly_direct(const City & city)override;
            virtual Player & fly_charter(const City & city)override;
            virtual Player & fly_shuttle(const City & city)override;


    };
}