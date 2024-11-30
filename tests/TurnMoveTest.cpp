#include <gtest/gtest.h>
#include "Executor.h"
namespace shpider{
TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
        executor->Execute("L");
        const Pose target({0, 0, direction::W});
        ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_LL_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::W}));
    executor->Execute("LL");
    const Pose target({0, 0, direction::E});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, direction::N}));
    executor->Execute("LRRLLR");
    const Pose target({0, 0, direction::N});
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