/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Pizza
*/

#include "Plazza/Pizza.hpp"

Pizza::Pizza(PizzaType type, PizzaSize size, std::size_t cookingTimeMultiplier) :  ASerialization()
{
    this->_type = type;
    this->_size = size;
    this->isCooked = false;
    this->setReciepe();
    this->_cookingTimeMultiplier = cookingTimeMultiplier;
}

Pizza::Pizza(const Pizza &other)
{
    this->_size = other._size;
    this->_type = other._type;
    this->_recipe = other._recipe;
    this->_bakeTime = other._bakeTime;
    this->_cookingTimeMultiplier = other._cookingTimeMultiplier;
}

std::size_t Pizza::getBakeTime() const
{
    return (this->_bakeTime);
}

void Pizza::fillAttributes(std::string line)
{
    Utils utils;
    std::vector<std::string> tokens;
    std::size_t pos = 0;
    std::string tmpToken;

    tokens = utils.stringToVector(line);
    if (utils.getTypeMap()[tokens[0]] == this->_type) {
        for (std::size_t i = 0; i != tokens.size() - 1; i++) {
            this->_recipe.push_back(tokens.at(i));
        }
        this->_bakeTime = std::atoi(tokens[tokens.size() - 1].c_str());
    }
}

void Pizza::setCooked(bool newStatus)
{
    isCooked = newStatus;
}

bool Pizza::getCooked() const
{
    return (isCooked);
}

void Pizza::setReciepe()
{
    std::ifstream myfile("./res/.recipe");
    std::string line;

    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            this->fillAttributes(line);
        }
        myfile.close();
    }
}

Pizza::~Pizza()
{
}

std::size_t Pizza::getCookingTimeMultiplier() const
{
    return (_cookingTimeMultiplier);
}

std::string Pizza::serialize()
{
    return (this->serializeObject(this->_type, this->_size));
}

std::shared_ptr<ASerialization> Pizza::unserializeObject(std::string serializeObject)
{
    Utils utils;
    std::vector<std::string> tokens = utils.stringToVector(serializeObject);

    std::shared_ptr<Pizza> pizza = std::make_shared<Pizza>(utils.getTypeMap()[tokens[0]], utils.getSizeMap()[tokens[1]], this->_cookingTimeMultiplier);
    return (pizza);
}