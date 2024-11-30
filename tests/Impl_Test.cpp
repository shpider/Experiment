#include <gtest/gtest.h>
#include "ExecutorImpl.h"
namespace shpider{
TEST(ImplTest,MoveTest)
{
    std::unique_ptr<ExecutorImpl> impl(ExecutorImpl::NewImpl({0, 0, direction::N}));
    impl->Execute("M");
    const Pose target({0, 1, direction::N});
    ASSERT_EQ(target, impl->Query());
}
TEST(ImplTest,TurnTest)
{
    std::unique_ptr<ExecutorImpl> impl(ExecutorImpl::NewImpl({0, 0, direction::N}));
    impl->Execute("ML");
    const Pose target({0, 1, direction::W});
    ASSERT_EQ(target, impl->Query());
}
TEST(ImplTest,TurnTest2)
{
    std::unique_ptr<ExecutorImpl> impl(ExecutorImpl::NewImpl({0, 0, direction::N}));
    impl->Execute("LML");
    const Pose target({-1, 0, direction::S});
    ASSERT_EQ(target, impl->Query());
}
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
}

