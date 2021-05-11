#include "Player.hpp"
#include "OperationsExpert.hpp"
#include <string>
using namespace std;
namespace pandemic{
 
    string OperationsExpert::role()
    {
        return "OperationsExpert";
    }
    /**
     * @brief doesn't need a maching card to build a study station,
     * so build anyway
     * 
     * @return Player& 
     */
    Player &OperationsExpert::build() {
        _board.has_study_station(_current_city) = true;
        return *this;
    }


}