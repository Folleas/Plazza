/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Thread
*/

#include "Thread.hpp"

Thread::Thread()
{
}

Thread::Thread(void *(function)(void *), void *param)
{
    createThread(function, param);
}

void Thread::createThread(void *(function)(void *), void *param)
{
    pthread_create(&_threadID, NULL, function, param);
}

void Thread::joinThread()
{
    pthread_join(this->_threadID, &this->_returnValue);
}

void *Thread::getReturnValue()
{
    return (this->_returnValue);
}

Thread::~Thread()
{
}