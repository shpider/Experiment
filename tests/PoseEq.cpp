#include"PoseEq.h"
namespace shpider
{
bool operator==(const Pose& pose1, const Pose& pose2)
{
    return std::tie(pose1.x,pose1.y,pose1.dir)==std::tie(pose2.x,pose2.y,pose2.dir);
}

}

