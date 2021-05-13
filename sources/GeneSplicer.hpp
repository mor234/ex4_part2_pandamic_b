//1. פורסת גנים - `GeneSplicer`: יכולה לבצע פעולת "גילוי תרופה" בעזרת 5 קלפים כלשהם - לא דווקא מהצבע של המחלה.
#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
    class GeneSplicer:public Player
    {
        public:            
            GeneSplicer ( Board & board, const City & city):Player(board,city){}
            virtual std::string role() override; 
            virtual Player & discover_cure(const Color & color) override;
        
    };
}