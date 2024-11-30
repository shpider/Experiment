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

}

