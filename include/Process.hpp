/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** Process
*/

#ifndef PROCESS_HPP_
    #define PROCESS_HPP_
    #include <unistd.h>
    #include <exception>
    #include <sys/wait.h>

template <typename Func>
class Process
{
private:
    pid_t _pid;

public:
    Process() {};
    ~Process() = default;
    void startProcess(Func function)
    {
        _pid = fork();
        if (_pid == 0) {
            function();
            _exit(0);
        }
    };
    pid_t getPid() { return _pid; };
    void waitForProcess() {
        int status;
        while (waitpid(_pid, &status , WUNTRACED | WIFSTOPPED(status)) > 0);
    };
};

#endif /* !PROCESS_HPP_ */
