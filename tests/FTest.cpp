#include <gtest/gtest.h>
#include "Executor.h"
#include"PoseEq.h"

namespace shpider{
TEST(FTest, should_return_y_plus_2_given_command_is_FM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FM");
    const Pose target({0, 2, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_x_plus_2_given_command_is_FM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FM");
    const Pose target({2, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_x_minus_2_given_command_is_MF_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FM");
    const Pose target({-2, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_y_minus_2_given_command_is_MF_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FM");
    const Pose target({0, -2, direction::S});
    ASSERT_EQ(target, executor->Query());
}

TEST(FTest, should_return_x_plus_1_and_facing_N_given_command_is_FL_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FL");
    const Pose target({1, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_y_plus_1_and_facing_W_given_command_is_FL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FL");
    const Pose target({0, 1, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_x_minus_1_and_facing_S_given_command_is_FL_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FL");
    const Pose target({-1, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_y_minus_1_and_facing_E_given_command_is_FL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FL");
    const Pose target({0, -1, direction::E});
    ASSERT_EQ(target, executor->Query());
}

TEST(FTest, should_return_y_plus_1_and_facing_E_given_command_is_FR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FR");
    const Pose target({0, 1, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_x_plus_1_and_facing_S_given_command_is_FR_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FR");
    const Pose target({1, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_x_minus_1_and_facing_W_given_command_is_FR_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FR");
    const Pose target({0, -1, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(FTest, should_return_y_minus_1_and_facing_N_given_command_is_FR_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FR");
    const Pose target({-1, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}

TEST(FTest, should_return_y_plus_1_and_facing_N_given_command_is_FFM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FFM");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, executor->Query());
}

TEST(FTest, Mixed_F_Test)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FMFRFLRRFM");
    const Pose target({2, 2, direction::S});
    ASSERT_EQ(target, executor->Query());
}

}
