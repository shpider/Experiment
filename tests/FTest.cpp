#include <gtest/gtest.h>
#include "Executor.h"
namespace shpider{
TEST(ExecutorTest, basic_F_Test)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FM");
    const Pose target({0, 2, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, DoubleF_Test)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FFM");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, F_And_Turn_Test)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FL");
    const Pose target({0, 1, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, Mixed_F_Test)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FMFRFLRRFM");
    const Pose target({2, 2, direction::S});
    ASSERT_EQ(target, executor->Query());
}
}
