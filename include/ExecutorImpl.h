#pragma once
#ifndef CPP_TRAINING_EXECUTORIMPL_H
#define CPP_TRAINING_EXECUTORIMPL_H

#endif  // CPP_TRAINING_EXECUTORIMPL_H

#include "Executor.h"
#include<memory>
namespace shpider
{
class ExecutorImpl final : public Executor
{
public:
    static ExecutorImpl* NewImpl(const Pose &my_pose= {0,0,direction::N});
    ExecutorImpl();
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;
    void Execute(const std::string &commands) noexcept;
    Pose Query();
private:
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Accelerate(void) noexcept;
    Pose pose;
    bool speed;
};

}







