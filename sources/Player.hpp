#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include <string>
namespace pandemic {
    class Player {
        protected:
            //class argument's
            Board * _board;
            static const int CARDS_FOR_CURE=5;
            City _current_city;
            std::set<City> _cards;
            //protected methods
            bool has_card(const City & city);
            void throw_card(const City & city);
            void throw_x_color_cards(const Color& color,int cards_for_cure=CARDS_FOR_CURE);
            bool has_x_color_cards(const Color& color,int cards_for_cure=CARDS_FOR_CURE);
        public:
            //constructor
            Player(Board & board,const City & current_city);
            //game methods
            Player & take_card(const City & city);
            //movements options
            virtual Player & drive(const City & city);
            virtual Player & fly_direct(const City & city);
            virtual Player & fly_charter(const City & city);
            virtual Player & fly_shuttle(const City & city);
            virtual Player & treat(const City & city);
            virtual Player & discover_cure(const Color& color);
            virtual Player & build();
            //return role of player
            virtual std::string role()=0;
            //for checks, end game
            void remove_cards();
    };
}