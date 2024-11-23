#include"Executor.h"

namespace shpider{
    bool operator ==(const Pose &A,const Pose&B)
    {
        return (A.x==B.x)&&(A.y==B.y)&&(A.heading==B.heading);
    }

    Executor* Executor::NewExecutor(const Pose& my_pose)
    {
        auto*p = new Executor();
        p->SetPose(my_pose);
        return p;
    }

    void Executor::SetPose(const Pose &my_pose)
    {
        this->pose.x = my_pose.x;
        this->pose.y = my_pose.y;
        this->pose.heading = my_pose.heading;
    }

    void Executor::Execute(const std::string& command)
    {
        int i = 0;
        while(command[i]!='\0') {
            if (command[i] == 'M')
                switch (pose.heading) {
                    case 'N':
                        pose.y++;
                        break;
                    case 'S':
                        pose.y--;
                        break;
                    case 'W':
                        pose.x--;
                        break;
                    case 'E':
                        pose.x++;
                        break;
                    default:
                        break;
                }

            else if (command[i] == 'L') TurnLeft();
            else if (command[i] == 'R') TurnRight();
            //else if (command[i] == ' ') continue;
            else std::cout << "Invalid command" << std::endl;
            i++;
        }
    }

    Pose Executor::Query()
    {
        return pose;
    }

    void Executor::TurnLeft()
    {
        switch(pose.heading)
        {
            case 'N':
                pose.heading = 'W'; break;
            case'W':
                pose.heading = 'S';break;
            case'S':
                pose.heading = 'E';break;
            case 'E':
                pose.heading = 'N';break;
            default:break;
        }
    }

    void Executor::TurnRight()
    {
        switch(pose.heading)
        {
            case 'N':
                pose.heading = 'E'; break;
            case'W':
                pose.heading = 'N';break;
            case'S':
                pose.heading = 'W';break;
            case 'E':
                pose.heading = 'S';break;
            default:break;
        }
    }


}