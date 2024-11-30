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
    void SetPose(const Pose &my_pose);
    ExecutorImpl();
    explicit ExecutorImpl(Pose my_pose);
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;
    void Execute(const std::string &commands) noexcept final;
    Pose Query() noexcept final;
private:
    void Move() noexcept;
    void TurnLeft() noexcept;
    void TurnRight() noexcept;
    void Accelerate() noexcept;
    Pose pose;
    bool speed;
};

}







