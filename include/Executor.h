#pragma once
#ifndef EXECUTOR_EXECUTOR_H
#define EXECUTOR_EXECUTOR_H
#include<iostream>
#include<cstring>

enum class direction {N,E,S,W};

namespace shpider {
    struct Pose
    {
        int x,y;
        enum direction dir;
    };

    bool operator ==(const Pose &A,const Pose&B);

    class Executor {
    private:
        Pose pose;
    public:
        static Executor* NewExecutor(const Pose &my_pose= {0,0,direction::N});
        Executor();
        explicit Executor(Pose my_pose);
        virtual ~Executor() = default;

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
