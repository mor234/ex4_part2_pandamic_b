//1. קצין מבצעים - `OperationsExpert`:יכול לבצע פעולת "בנייה" בכל עיר שהוא נמצא בה, בלי להשליך קלף-עיר מתאים.
#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class OperationsExpert : public Player {
    public:
        OperationsExpert(Board &board, const City &city) : Player(board, city) {}

        virtual std::string role() override;

        virtual Player &build() override;

    };
}