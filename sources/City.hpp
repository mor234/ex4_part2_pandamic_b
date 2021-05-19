
#pragma once
#include <string>
#include <array>
namespace pandemic {
    const int NUMBER_OF_CITIES=48;
    enum City {
        Algiers, Atlanta,
        Baghdad, Bangkok, Beijing, Bogota, BuenosAires,
        Cairo, Chennai, Chicago,
        Delhi,
        Essen,
        HoChiMinhCity, HongKong,
        Istanbul,
        Jakarta, Johannesburg,
        Karachi, Khartoum, Kinshasa, Kolkata,
        Lagos, Lima, London, LosAngeles,
        Madrid, Manila, MexicoCity, Miami, Milan, Montreal, Moscow, Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco, Santiago, SaoPaulo, Seoul, Shanghai, StPetersburg, Sydney,
        Taipei, Tehran, Tokyo, Washington
    };
    const std::array<std::string, NUMBER_OF_CITIES> STRING_CITIES={
        "Algiers", "Atlanta",
        "Baghdad", "Bangkok", "Beijing", "Bogota", "BuenosAires",
        "Cairo", "Chennai", "Chicago",
        "Delhi",
        "Essen",
        "HoChiMinhCity", "HongKong",
        "Istanbul",
        "Jakarta", "Johannesburg",
        "Karachi", "Khartoum", "Kinshasa", "Kolkata",
        "Lagos", "Lima", "London", "LosAngeles",
        "Madrid", "Manila", "MexicoCity", "Miami", "Milan", "Montreal", "Moscow", "Mumbai",
        "NewYork",
        "Osaka",
        "Paris",
        "Riyadh",
        "SanFrancisco", "Santiago", "SaoPaulo", "Seoul", "Shanghai", "StPetersburg", "Sydney",
        "Taipei", "Tehran", "Tokyo", "Washington"};

    inline std::string string_for_city(const City & city )
    {
        return STRING_CITIES.at((unsigned long)city);
    }
};
