#pragma once

#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include<array>


#include <iostream>

namespace pandemic {
    class Board {
    private:
        static bool is_first_time;
        static std::map <City, std::pair<Color, std::set < City>> >
        board_city_map;
        std::map <City, std::pair<int /*sickness_cubes*/, bool /*study_station*/>> city_attributes;
        std::array<bool, COLOR_NUMBER> cures;

        static void initialize_board();

    public:
        Board();

        void remove_stations();

        void remove_cures();

        bool is_clean();

        //operator []
        const int &operator[](const City &city) const;

        int &operator[](const City &city);

        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend std::ostream &operator<<(std::ostream &output, const Board &board);

        //----------------------------------
        // help functions
        //----------------------------------
        static const Color &color_for_city(const City &city);

        static std::set <City> near_cities(const City &city);

        static bool are_cities_connected(const City &city1, const City &city2);

        const bool &has_study_station(City city) const;

        bool &has_study_station(const City &city);

        bool &color_has_cure(const Color &color);


    };
}