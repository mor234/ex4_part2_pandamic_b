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
            Board _board;
            City _current_city;
            std::set<City> _cards;
            bool has_card(City city);
            void throw_card(City city);
            void throw_x_color_cards(Color color,int cards_for_cure=CARDS_FOR_CURE);
            bool has_x_color_cards(Color color,int cards_for_cure=CARDS_FOR_CURE);



        public:
            Player(Board & board,const City & current_city);
            Player & take_card(City city);

            //movements options
            Player & drive(City city);
            virtual Player & fly_direct(City city);
            Player & fly_charter(City city);
            Player & fly_shuttle(City city);

            virtual Player & treat(City city);

            virtual Player & discover_cure(Color color);
            virtual Player & build();
            virtual std::string role()=0;

            void remove_cards();
    };



}