/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Fork
*/

#include "../../include/Encapsulation/Fork.hpp"

Fork::Fork()
{
}

Fork::~Fork()
{
}

pid_t Fork::addFork(void)
{
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Error: fork failed.\n";
        return (-1);
    } _pid.push_back(pid);
    return pid;
}

void Fork::delFork(pid_t curr)
{
    kill(curr, SIGKILL);
}

bool waitPid(pid_t pid)
{
    if (waitpid(pid, 0, 0) == -1)
        return false;
    return true;
}