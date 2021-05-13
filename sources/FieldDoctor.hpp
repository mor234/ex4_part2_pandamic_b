// רופא שטח - `FieldDoctor`: יכול לבצע פעולת "טיפול במחלה" לא רק בעיר שהוא נמצא בה אלא בכל עיר סמוכה לעיר שהוא נמצא
// בה (ע"פ מפת הקשרים), בלי להשליך קלף עיר.
#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class FieldDoctor:public Player
    {
        public:
            FieldDoctor ( Board & board, const City & city):Player(board,city){}
            virtual std::string role() override; 
            Player & treat(const City & city) override;
    };
}