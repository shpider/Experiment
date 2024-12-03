#include <gtest/gtest.h>
#include "Executor.h"
#include"PoseEq.h"

namespace shpider{
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));

    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_defult_pose_when_without_command_and_init_arguments)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    const Pose target({0, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
        executor->Execute("L");
        const Pose target({0, 0, direction::W});
        ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("L");
    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("L");
    const Pose target({0, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("R");
    const Pose target({0, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("R");
    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("R");
    const Pose target({0, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("R");
    const Pose target({0, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("M");
    const Pose target({1, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("M");
    const Pose target({-1, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("M");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("M");
    const Pose target({0, -1, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, move_and_turn)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("L BML");
    const Pose target({-1, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
}