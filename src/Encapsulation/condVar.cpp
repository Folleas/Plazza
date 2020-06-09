/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** condVar
*/

#include "../../include/Encapsulation/condVar.hpp"

condVar::condVar(void)
{

}

condVar::~condVar(void)
{

}

void condVar::notifyOne(void)
{
    _cond.notify_one();
}

void condVar::notifyAll(void)
{
    _cond.notify_all();
}

void condVar::setLock(std::mutex tmp)
{
    std::unique_lock<std::mutex> fnl(tmp);

    this->_lock = std::unique_lock<std::mutex> (tmp);
}

bool condVar::waitLock(void)
{
    _cond.wait(_lock);
    return true;
}