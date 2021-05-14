#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include <string>
namespace pandemic{
    class Player{
        private:
            City rand_city();



        protected:
            static const int CARDS_FOR_CURE=5;
            City _current_city;
            std::set<City> _cards;
            bool has_card(const City & city);
            void throw_card(const City & city);
            void throw_x_color_cards(const Color& color,int cards_for_cure=CARDS_FOR_CURE);
            bool has_x_color_cards(const Color& color,int cards_for_cure=CARDS_FOR_CURE);



        public:
            Board * _board;

            Player(Board & board,const City & current_city);
            Player & take_card(const City & city);

            //movements options
            virtual Player & drive(const City & city);
            virtual Player & fly_direct(const City & city);
            virtual Player & fly_charter(const City & city);
            virtual Player & fly_shuttle(const City & city);

            virtual Player & treat(const City & city);

            virtual Player & discover_cure(const Color& color);
            virtual Player & build();
            virtual std::string role()=0;

            void remove_cards();
    };



}