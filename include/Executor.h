#pragma once
#ifndef EXECUTOR_EXECUTOR_H
#define EXECUTOR_EXECUTOR_H
#include<iostream>
#include<cstring>

namespace shpider {
    struct Pose
    {
        int x,y;
        char heading;
    };

    bool operator ==(const Pose &A,const Pose&B);

    class Executor {
    private:
        Pose pose;
    public:
        static Executor* NewExecutor(const Pose &my_pose= {0,0,'N'});
        Executor(void) = default;
        virtual ~Executor(void) = default;

        Executor(const Executor&) = delete;
        Executor& operator=(const Executor&) = delete;

        virtual void SetPose(const Pose &my_pose);
        virtual void Execute(const std::string& command);
        virtual Pose Query();
        virtual void TurnLeft();
        virtual void TurnRight();

    };

}
#endif //EXECUTOR_EXECUTOR_H
