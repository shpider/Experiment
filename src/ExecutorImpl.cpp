#include"ExecutorImpl.h"

namespace shpider
{

dist Distance[4] = {{0,1},{1,0},{0,-1},{-1,0}};

ExecutorImpl* ExecutorImpl::NewImpl(const Pose& my_pose)
{
    auto*p = new ExecutorImpl();
    p->SetPose(my_pose);
    return p;
}

ExecutorImpl::ExecutorImpl():Executor(),pose({0,0,direction::N}),speed(false)
{}

void ExecutorImpl::Execute(const std::string &commands) noexcept
{
    for(const auto cmd:commands)
    {
        if(cmd=='M') Move();
        else if(cmd=='R') TurnRight();
        else if(cmd == 'L') TurnLeft();
        else if(cmd == 'F') Accelerate();
        else std::cout<<"Invalid command ";
    }
}

void ExecutorImpl::Move() noexcept
{
    pose.x += Distance[static_cast<int>(pose.dir)].x;
    pose.y += Distance[static_cast<int>(pose.dir)].y;
}

void ExecutorImpl::TurnLeft(void) noexcept
{

}

void ExecutorImpl::TurnRight(void) noexcept
{

}

void ExecutorImpl::Accelerate() noexcept
{

}

Pose ExecutorImpl::Query()
{
    return pose;
}
}