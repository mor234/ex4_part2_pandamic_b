#include "Player.hpp"
#include "Board.hpp"

#include "City.hpp"
#include "Color.hpp"//check if have to

using namespace std;
namespace pandemic {
    /**
     * @brief Construct a new Player:: Player object
     * 
     * @param board 
     * @param current_city 
     */
    Player::Player(Board &board, const City &current_city) {
        _board = &board;
        _current_city = current_city;
    }

    /**
     * @brief return true if the player has the city's card, otherwise false.
     * to be used in other functions
     * @param city 
     * @return true 
     * @return false 
     */
    bool Player::has_card(const City &city) {
        return _cards.find(city) != _cards.end();
    }

    /**
     * @brief remove one card the player holds, to be used in other functions
     * 
     * @param city 
     * @return iterator 
     */
    void Player::throw_card(const City &city) {
        _cards.erase(city);

    }

    /**
     * @brief take the given card by inserting it to the cards set. if already there, nothing happend.
     * 
     * @param city 
     * @return Player& 
     */
    Player &Player::take_card(const City &city) {
        _cards.insert(city);
        return *this;
    }
    //----------------------------------
    // movements options:
    //----------------------------------
    /**
     * @brief move to a connected city
     * throw if the given city is not a connected city 
     * or if tries to fly to the same city he is in.
     * @param city 
     * @return Player& 
     */
    Player &Player::drive(const City &city) {
        if (city == _current_city) {
            throw invalid_argument{"Error. can't drive to the same city."};
        }
        if (Board::are_cities_connected(_current_city, city)) {
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't drive to an un connected city."};
        }
        return *this;
    }

    /**
     * @brief move to a city with card of the city to go to
     *  throw if doesn't has given city card or tries to fly to the same city he is in.
     * @param city 
     * @return Player& 
     */
    Player &Player::fly_direct(const City &city) {
        if (city == _current_city) {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        if (has_card(city)) {
            throw_card(city);
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't fly directly to a city without maching card."};
        }
        return *this;
    }

    /**
     * @brief move to a city with card of the city we go from.
     *  throw if doesn't has current city card or tries to fly to the same city he is in.
     * @param city 
     * @return Player& 
     */
    Player &Player::fly_charter(const City &city) {
        if (city == _current_city) {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        if (has_card(_current_city)) {
            throw_card(_current_city);
            _current_city = city;
        } else {
            throw invalid_argument{"Error. can't fly charter from a city without maching card."};
        }
        return *this;
    }

    /**
     * @brief  move between 2 cities who has study stations.
     *  throw if the current city or th city we go to does,n't have study station, 
     * or if tries to fly to the same city he is in.
     * @param city 
     * @return Player& 
     */
    Player &Player::fly_shuttle(const City &city) {
        if (city == _current_city) {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        //if the current city doesn't have study station 
        if (!_board->has_study_station(_current_city)) {
            throw invalid_argument{"Error. can't fly shuttle from a city without study station."};
        }
        //if the destination city doesn't have study station 
        if (!_board->has_study_station(city)) {
            throw invalid_argument{"Error. can't fly shuttle to a city without study station."};
        }
        //both has study stations
        _current_city = city;
        return *this;
    }

    /**
     * @brief if the current city has sickness cube remove one,
     * if has cure for the color off the city remove all sickness cubes
     * throw if tries to treat different city\doesn't have sickness cubes 
     * @param city 
     * @return Player& 
     */
    Player &Player::treat(const City &city) {
        if (city != _current_city) {
            throw invalid_argument{"can't treat a city without being in it."};
        }
        //if has sickness cubes
        if ((*_board)[city] > 0) {
            (*_board)[city]--;
            if (_board->color_has_cure(Board::color_for_city(city))) {
                (*_board)[city] = 0;//if discovered a cure- remove all sickness cubes
            }
        } else {
            throw invalid_argument{"Error. can't treat a healthy city."};
        }
        return *this;
    }

    /**
     * @brief check if has the given card number in the given color'
     * defulf value for cards number is CARDS_FOR_CURE=5
     * to be used in discover_cure function
     */
    bool Player::has_x_color_cards(const Color &color, int cards_for_cure/*defult: CARDS_FOR_CURE=5*/) {
        int counter = 0;
        for (auto card:_cards) {
            if (Board::color_for_city(card) == color) {
                counter++;
            }
        }
        return counter >= cards_for_cure;
    }

    /**
    * @brief throw the given number of card (defult value-  CARDS_FOR_CURE=5)
    * in the given color.
    * assumes has enough card in the color
    * to be used in discover_cure function
    */
    void Player::throw_x_color_cards(const Color &color, int cards_for_cure/*defult: CARDS_FOR_CURE=5*/) {

        for (auto card_itr = _cards.begin(); card_itr != _cards.end();) {
            if (Board::color_for_city(*card_itr) == color) {
                // Remove string from set if length is greater than 3.
                card_itr = _cards.erase(card_itr);
                cards_for_cure--;
                if (cards_for_cure == 0) {
                    break;
                }
            } else {
                card_itr++;
            }
        }
    }

    /**
     * @brief discover_cure in the given color,
     * if has 5 cards in the same color' and throe them
     * 
     * @param color 
     * @return Player& 
     */
    Player &Player::discover_cure(const Color &color) {
        if (_board->has_study_station(_current_city)) {
            if (!_board->color_has_cure(color)) {
                if (has_x_color_cards(color)) {
                    throw_x_color_cards(color);
                    _board->color_has_cure(color) = true;
                } else {
                    throw invalid_argument{"Error. can't discover cures without enough cards in the maching color"};
                }
            }
        } else {
            throw invalid_argument{"Error. can't discover cures without study station in the city"};
        }
        return *this;
    }

    /**
     * @brief build study station in current city, if has current city card
     * else throw
     * @return Player& 
     */
    Player &Player::build() {
        if (!_board->has_study_station(_current_city)) {
            if (has_card(_current_city)) {
                throw_card(_current_city);
                _board->has_study_station(_current_city) = true;
            } else {
                throw invalid_argument{"Error. can't build study station without matching card."};
            }
        }
        return *this;
    }

    /**
     * @brief remove all player cards,
     * to be used in checks
     */
    void Player::remove_cards() {
        _cards.clear();
    }

}