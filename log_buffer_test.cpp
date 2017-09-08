#include "gtest/gtest.h"
#include "include/log_buffer.h" 

TEST(LogBuffer, DEFAULTCONSTRUCTOR)
{

    logsystem_buffer::LogBuffer log_buffer;

    EXPECT_EQ(30, log_buffer.get_buffer_size());
}

TEST(LogBuffer, CONSTRUCTOR)
{

    logsystem_buffer::LogBuffer log_buffer(50);

    EXPECT_EQ(50, log_buffer.get_buffer_size());

    logsystem_buffer::LogBuffer log_buffer(-1);

    EXPECT_EQ(30, log_buffer.get_buffer_size());
}

TEST(LogBuffer, WRITE)
{

    logsystem_buffer::LogBuffer log_buffer();

    EXPECT_EQ(0, log_buffer.write("message", "/log", "test.log"));
}

TEST(LogBuffer, READ)
{

    logsystem_buffer::LogBuffer log_buffer();
    EXPECT_TRUE(log_buffer.read("/log", "test.log") != NULL);
}
