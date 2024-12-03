#include <gtest/gtest.h>
#include "ExecutorImpl.h"
#include"PoseEq.h"

namespace shpider{
TEST(ImplTest, should_return_init_pose_when_without_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));

    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}

TEST(ImplTest, should_return_defult_pose_when_without_command_and_init_arguments)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    const Pose target({0, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
//basic initiate tests

TEST(ImplTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("L");
    const Pose target({0, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("L");
    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("L");
    const Pose target({0, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("L");
    const Pose target({0, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
//basic turn left tests

TEST(ImplTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("R");
    const Pose target({0, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("R");
    const Pose target({0, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("R");
    const Pose target({0, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_facing_N_given_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("R");
    const Pose target({0, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
//basic turn right tests

TEST(ImplTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("M");
    const Pose target({1, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("M");
    const Pose target({-1, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("M");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("M");
    const Pose target({0, -1, direction::S});
    ASSERT_EQ(target, executor->Query());
}
//basic move tests

TEST(ImplTest, should_return_y_plus_2_given_command_is_FM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FM");
    const Pose target({0, 2, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_plus_2_given_command_is_FM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FM");
    const Pose target({2, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_minus_2_given_command_is_MF_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FM");
    const Pose target({-2, 0, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_minus_2_given_command_is_MF_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FM");
    const Pose target({0, -2, direction::S});
    ASSERT_EQ(target, executor->Query());
}
//fast and move tests

TEST(ImplTest, should_return_x_plus_1_and_facing_N_given_command_is_FL_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FL");
    const Pose target({1, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_plus_1_and_facing_W_given_command_is_FL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FL");
    const Pose target({0, 1, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_minus_1_and_facing_S_given_command_is_FL_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FL");
    const Pose target({-1, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_minus_1_and_facing_E_given_command_is_FL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FL");
    const Pose target({0, -1, direction::E});
    ASSERT_EQ(target, executor->Query());
}
//fast and turn left tests

TEST(ImplTest, should_return_y_plus_1_and_facing_E_given_command_is_FR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FR");
    const Pose target({0, 1, direction::E});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_plus_1_and_facing_S_given_command_is_FR_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::E}));
    executor->Execute("FR");
    const Pose target({1, 0, direction::S});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_x_minus_1_and_facing_W_given_command_is_FR_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::S}));
    executor->Execute("FR");
    const Pose target({0, -1, direction::W});
    ASSERT_EQ(target, executor->Query());
}
TEST(ImplTest, should_return_y_minus_1_and_facing_N_given_command_is_FR_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("FR");
    const Pose target({-1, 0, direction::N});
    ASSERT_EQ(target, executor->Query());
}
//fast and turn right tests

TEST(ImplTest, should_return_y_plus_1_and_facing_N_given_command_is_FFM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("FFM");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, executor->Query());
}
//double fast test

TEST(ImplTest,MixTest)
{
    std::unique_ptr<ExecutorImpl> impl(ExecutorImpl::NewImpl({0, 0, direction::N}));
    impl->Execute("FMFRFLRRFM");
    const Pose target({2, 2, direction::S});
    ASSERT_EQ(target, impl->Query());
}
TEST(ImplTest,MixTest2)
{
    std::unique_ptr<ExecutorImpl> impl(ExecutorImpl::NewImpl({4, 10, direction::W}));
    impl->Execute("FLFRFLRRFM");
    const Pose target({1, 10, direction::N});
    ASSERT_EQ(target, impl->Query());
}
//mixed commands tests
}

