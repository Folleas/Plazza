/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Queue
*/

#include "Queue.hpp"

template <typename Type>
Queue<Type>::Queue(const Queue<Type> &other)
{
    this->_queue = other->_queue;
}

template <typename Type>
Queue<Type>::~Queue()
{
}

template <typename Type>
void Queue<Type>::push(Type newValue)
{
    this->_queue.push(newValue);
}

template <typename Type>
void Queue<Type>::pop(void)
{
    this->_queue.pop();
}

template <typename Type>
bool Queue<Type>::empty()
{
    return (this->_queue.empty());
}

template <typename Type>
size_t Queue<Type>::size()
{
    return (this->_queue.size());
}

template <typename Type>
void Queue<Type>::swap(Queue<Type> &first, Queue<Type> &second)
{
    this->_queue.swap(first, second);
}

template <typename Type>
void Queue<Type>::swap(std::queue<Type> &first, std::queue<Type> &second)
{
    this->_queue.swap(first, second);
}

template <typename Type>
void Queue<Type>::emplace(Type newValue)
{
    this->_queue.emplace(newValue);
}

template <typename Type>
Type &Queue<Type>::front(void)
{
    return (this->_queue.front());
}

template <typename Type>
Type &Queue<Type>::queue(void)
{
    return (this->_queue.queue());
}