#include <gtest/gtest.h>
#include "event_dispatcher.h"

TEST(SampleTest, AssertionTrue) {
    EventDispatcher::hello();

    ASSERT_TRUE(true);
}