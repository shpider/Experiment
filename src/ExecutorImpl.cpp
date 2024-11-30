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

void ExecutorImpl::SetPose(const Pose &my_pose)
{
    pose = my_pose;   //C++允许结构变量整体赋值
    /*this->pose.x = my_pose.x;
    this->pose.y = my_pose.y;
    this->pose.dir = my_pose.dir;*/
}

 ExecutorImpl::ExecutorImpl(Pose my_pose):pose({0,0,direction::N}), speed(false)
 {
     pose = my_pose;
 }

ExecutorImpl::ExecutorImpl():Executor(),pose({0,0,direction::N}),speed(false)
{}

void ExecutorImpl::Execute(const std::string &commands) noexcept
{
    for(const auto cmd:commands)
    {
        if(cmd=='M') {
            if(speed) Move();
            Move();
        }
        else if(cmd=='R') {
            if(speed)Move();
            TurnRight();
        }
        else if(cmd == 'L')
        {
            if(speed) Move();
            TurnLeft();
        }
        else if(cmd == 'F') Accelerate();
        else std::cout<<"Invalid command ";
    }
}

void ExecutorImpl::Move() noexcept
{
    pose.x += Distance[static_cast<int>(pose.dir)].x;
    pose.y += Distance[static_cast<int>(pose.dir)].y;
}

void ExecutorImpl::TurnLeft() noexcept
{
    pose.dir = static_cast<direction>((static_cast<int>(pose.dir) + 3) % 4);
}

void ExecutorImpl::TurnRight() noexcept
{
    pose.dir = static_cast<direction>((static_cast<int>(pose.dir) + 1) % 4);
}

void ExecutorImpl::Accelerate() noexcept
{
    speed = !speed;
}

Pose ExecutorImpl::Query() noexcept
{
    return pose;
}
}