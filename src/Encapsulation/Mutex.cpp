/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Mutex
*/

#include "Encapsulation/Mutex.hpp"

Encapsulation::Mutex::Mutex()
{
    pthread_mutex_init(&this->_mutexID, NULL);
}

Encapsulation::Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->_mutexID);
}

int Encapsulation::Mutex::mutexLock()
{
    return (pthread_mutex_lock(&this->_mutexID));
}

int Encapsulation::Mutex::mutexUnlock()
{
    return (pthread_mutex_unlock(&this->_mutexID));
}

int Encapsulation::Mutex::mutexTrylock()
{
    return (pthread_mutex_trylock(&this->_mutexID));
}

pthread_mutex_t Encapsulation::Mutex::getMutexID()
{
    return (this->_mutexID);
}