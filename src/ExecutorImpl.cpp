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

void ExecutorImpl::SetPose(const Pose &my_pose) noexcept
{
    pose = my_pose;   //C++允许结构变量整体赋值
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
        std::unique_ptr<ICommand> cmder;   //初始化为指向虚基类的指针，后续按照需求使其指向不同的派生类对象
        if(cmd=='M')
            cmder = std::make_unique<MoveCommand>();
        else if(cmd=='R')
            cmder = std::make_unique<TurnRightCommand>();
        else if(cmd == 'L')
            cmder = std::make_unique<TurnLeftCommand>();

        else if(cmd == 'F') cmder = std::make_unique<FastCommand>();
        //else std::cout<<"Invalid command ";
        cmder->DoOperate(*this);
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