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
    void SetPose(const Pose &my_pose) noexcept override;
    ExecutorImpl();
    explicit ExecutorImpl(Pose my_pose);
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;
    void Execute(const std::string &commands) noexcept final;
    Pose Query() noexcept final;
private:
    Pose pose;
    bool speed{false};
    void Move() noexcept;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
    void Accelerate() noexcept override;

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    };


    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl & executor)const noexcept override
        {
            if(executor.speed) executor.Move();
            executor.Move();
        }
    };
    class TurnRightCommand final :public ICommand
    {
    public:
        void DoOperate(ExecutorImpl & executor)const noexcept override
        {
            if(executor.speed) executor.Move();
            executor.TurnRight();
        }
    };
    class TurnLeftCommand final: public ICommand
    {
    public:
        void DoOperate(ExecutorImpl & executor)const noexcept override
        {
            if(executor.speed) executor.Move();
            executor.TurnLeft();
        }
    };
    class FastCommand final: public ICommand
    {
    public:
        void DoOperate(ExecutorImpl & executor)const noexcept override
        {
            executor.Accelerate();
        }
    };
};

}







