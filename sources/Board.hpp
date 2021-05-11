#pragma once
#include "City.hpp"
#include "Color.hpp"

#include "Player.hpp"
#include <map>
#include <set>
#include<array> 


#include <iostream>

namespace pandemic{
    class Board{
        private:
            static std::map< City, std::pair <Color, std::set <City> > >board_city_map;
            static void initialize_board();
            // int sickness_cubes_num;
            std::map<City,std::pair<int /*sickness_cubes*/,bool /*study_station*/>> city_attributes;
            std::array<bool,COLOR_NUMBER>cures;
        public:
            Board ();
            void remove_cures();
            bool is_clean();
            static const Color & color_for_city(City city);
            static std::set <City> near_cities(City city);
            static bool are_cities_connected(City city1,City city2);
            bool & has_study_station(City city);
            bool & color_has_cure(Color color);
            int & sickness_cubes (City city);
            //operator []
            const int & operator[](City city) const;
            int& operator[](City city);
            //----------------------------------
            // friend global IO operators
            //----------------------------------
            friend std::ostream& operator<< (std::ostream& output, const Board & board);
    };
}