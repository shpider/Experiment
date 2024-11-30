#include"Executor.h"

namespace shpider{


    bool operator ==(const Pose &A,const Pose&B)
    {
        return (A.x==B.x)&&(A.y==B.y)&&(A.dir==B.dir);
    }

    Executor* Executor::NewExecutor(const Pose& my_pose)
    {
        auto*p = new Executor();
        p->SetPose(my_pose);
        return p;
    }

    Executor::Executor():pose({0,0,direction::N})    //作为默认的初始化参数
    {}

    Executor::Executor(Pose my_pose):pose({0,0,direction::N})
    {
        pose = my_pose;
    }

    void Executor::SetPose(const Pose &my_pose)
    {
        pose = my_pose;   //C++允许结构变量整体赋值
        /*this->pose.x = my_pose.x;
        this->pose.y = my_pose.y;
        this->pose.dir = my_pose.dir;*/
    }

    void Executor::Execute(const std::string& command)
    {
        int i = 0;
        while (command[i] != '\0') {
            if (command[i] == 'M')
                switch (pose.dir) {
                case direction::N:
                    pose.y++;
                    break;
                case direction::S:
                    pose.y--;
                    break;
                case direction::W:
                    pose.x--;
                    break;
                case direction::E:
                    pose.x++;
                    break;
                default:
                    break;
                }

            else if (command[i] == 'L')
                TurnLeft();
            else if (command[i] == 'R')
                TurnRight();
            // else if (command[i] == ' ') continue;
            else
                std::cout << "Invalid command" << std::endl;
            i++;
        }
    }

    Pose Executor::Query()
    {
        return pose;
    }

    void Executor::TurnLeft()
    {
        pose.dir = static_cast<direction>((static_cast<int>(pose.dir) + 3) % 4);   //枚举类型映射为整形，计算后再转换回来
        /*switch(pose.dir)
        {
        case direction::N:
                pose.dir = direction::W; break;
            case direction::W:
                pose.dir = direction::S;break;
            case direction::S:
                pose.dir = direction::E;break;
            case direction::E:
                pose.dir = direction::N;break;
            default:break;
        }*/
    }

    void Executor::TurnRight()
    {
        pose.dir = static_cast<direction>((static_cast<int>(pose.dir) + 1) % 4);
        /*switch(pose.dir)
        {
            case direction::N:
                pose.dir = direction::E; break;
            case direction::W:
                pose.dir = direction::N;break;
            case direction::S:
                pose.dir = direction::W;break;
            case direction::E:
                pose.dir = direction::S;break;
            default:break;
        }*/
    }
}