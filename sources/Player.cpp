#include "Player.hpp"
#include "Board.hpp"

#include "City.hpp"
#include "Color.hpp"//check if have to

using namespace std;
namespace pandemic {
    Player::Player(Board &board, const City &current_city) {
        _board = board;
        _current_city = current_city;
    }

    bool Player::has_card(City city) {
        return _cards.find(city) != _cards.end();
    }

    /**
     * @brief remove card the player holds and return iterator to the next place in the set
     * 
     * @param city 
     * @return iterator 
     */
    void Player::throw_card(City city) {
        _cards.erase(city);
    }

    // City Player::rand_city()
    // {
    //     return (City)rand()%board.NUMBER_OF_CITIES;
    // }
    Player &Player::take_card(City city) {
        _cards.insert(city);
        return *this;
    }

    //movements options
    Player &Player::drive(City city) {
        if (Board::are_cities_connected(_current_city, city)) {
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't drive to an un connected city."};
        }
        return *this;
    }

    Player &Player::fly_direct(City city) {
        if (has_card(city)) {
            throw_card(city);
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't fly directly to a city without maching card."};
        }
        return *this;
    }

    Player &Player::fly_charter(City city) {
        if (has_card(_current_city)) {
            throw_card(_current_city);
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't fly charter from a city without maching card."};
        }
        return *this;
    }

    Player &Player::fly_shuttle(City city) {
        //if the destination city doesn't have study station 
        if (!_board.has_study_station(_current_city)) {
            throw invalid_argument{"Error. can't fly shuttle from a city without study station."};
        }
            //if the destination city doesn't have study station 
        if (!_board.has_study_station(city)) {
            throw invalid_argument{"Error. can't fly shuttle to a city without study station."};
        } else//both has study stations
        {
            _current_city = city;
        }
        return *this;
    }

    Player &Player::treat(City city) {
        if (city != _current_city) {
            throw invalid_argument{"can't treat a city without being in it."};
        }
        if (_board.sickness_cubes(city) > 0) {
            _board.sickness_cubes(city)--;
            if (_board.color_has_cure(Board::color_for_city(city))) {
                _board.sickness_cubes(city) = 0;//if discovered a cure- remove all sickness cubes
            }
        } else {
            throw invalid_argument{"Error. can't treat a healthy city."};
        }
        return *this;
    }

    bool Player::has_x_color_cards(Color color,int cards_for_cure/*defult: CARDS_FOR_CURE=5*/) {
        int counter = 0;
        for (auto card:_cards) {
            if (_board.color_for_city(card) == color) {
                counter++;
            }
        }
        return counter >= cards_for_cure;
    }

    void Player::throw_x_color_cards(Color color,int cards_for_cure/*defult: CARDS_FOR_CURE=5*/) {
        int counter = cards_for_cure;
        for (auto card_itr = _cards.begin(); card_itr != _cards.end(); card_itr++) {

            if (_board.color_for_city(*card_itr) == color) {
                counter--;
                if (counter == 0) {
                    break;
                }
                throw_card(*card_itr);
                //card_itr++;
            }
        }
    }

    Player &Player::discover_cure(Color color) {
        if (_board.has_study_station(_current_city)){
            if (!_board.color_has_cure(color)) {
                if (has_x_color_cards(color)) {
                    throw_x_color_cards(color);
                    _board.color_has_cure(color) = true;
                } else {
                    throw invalid_argument{"Error. can't discover cures without enough cards in the maching color"};
                }
            }
        } 
        else
        {
            throw invalid_argument{"Error. can't discover cures without study station in the city"};
        }
        return *this;
    }

    Player &Player::build() {
        if (has_card(_current_city)) {
            if (!_board.has_study_station(_current_city)) {
                throw_card(_current_city);
                _board.has_study_station(_current_city) = true;
            }
        } else {
            throw invalid_argument{"Error. can't build study station without matching card."};
        }
        return *this;
    }

    void Player::remove_cards() {
        _cards.clear();
    }

}