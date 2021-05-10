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
            void Player::throw_5_color_cards(Color color);
            bool Player::has_5_color_cards(Color color);


        protected:
            Board _board;
            City _current_city;
            std::set<City> cards;
            bool has_card(City city);
            void throw_card(City city);
            const int CARDS_FOR_CURE=5;



        public:
            Player(const Board & board,const City & current_city);
            Player & take_card(City city);

            //movements options
            virtual Player & drive(City city);
            virtual Player & fly_direct(City city);
            virtual Player & fly_charter(City city);
            virtual Player & fly_shuttle(City city);

            Player & treat(City city);



            Player & discover_cure(Color color);
            Player & build();
            virtual std::string role()=0;
    };



}