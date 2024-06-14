#include <gtest/gtest.h>
#include "event_dispatcher.h"
//
//class EventDispatcherTest : public ::testing::Test {
//protected:
//    EventDispatcher::EventDispatcher dispatcher;
//
//    static void testCallback(void* event) {
//        ++callbackCount;
//    }
//
//    static int callbackCount;
//
//    void SetUp() override {
//        callbackCount = 0;
//    }
//};
//
//int EventDispatcherTest::callbackCount = 0;
//
//TEST_F(EventDispatcherTest, AddEventListener) {
//    dispatcher.addEventListener("testEvent", testCallback);
//    ASSERT_TRUE(dispatcher.hasEventListener("testEvent", testCallback));
//}
//
//TEST_F(EventDispatcherTest, RemoveEventListener) {
//    dispatcher.addEventListener("testEvent", testCallback);
//    dispatcher.removeEventListener("testEvent", testCallback);
//    ASSERT_FALSE(dispatcher.hasEventListener("testEvent", testCallback));
//}
//
//TEST_F(EventDispatcherTest, DispatchEvent) {
//    dispatcher.addEventListener("testEvent", testCallback);
//    dispatcher.dispatchEvent("testEvent");
//    ASSERT_EQ(callbackCount, 1);
//}
//
//TEST_F(EventDispatcherTest, NoCallbackCalledIfListenerRemoved) {
//    dispatcher.addEventListener("testEvent", testCallback);
//    dispatcher.removeEventListener("testEvent", testCallback);
//    dispatcher.dispatchEvent("testEvent");
//    ASSERT_EQ(callbackCount, 0);
//}

// todo: create Test class that creates event dispatcher instance and calls
//  instance methods using namespace notation
TEST(SampleTest, AssertionTrue) {
    EventDispatcher::hello();

    ASSERT_TRUE(true);
}