#include "gtest/gtest.h"
#include "include/logger.h"

TEST(LOGGER, FATAL){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(5);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(-1, flag1);
    EXPECT_EQ(-1, flag2);
    EXPECT_EQ(-1, flag3);
    EXPECT_EQ(-1, flag4);
    EXPECT_EQ(-1, flag5);
    
    
}

TEST(LOGGER, ERROR){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(4);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(0, flag1);
    EXPECT_EQ(-1, flag2);
    EXPECT_EQ(-1, flag3);
    EXPECT_EQ(-1, flag4);
    EXPECT_EQ(-1, flag5);
    
}

TEST(LOGGER, WARN){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(3);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(0, flag1);
    EXPECT_EQ(0, flag2);
    EXPECT_EQ(-1, flag3);
    EXPECT_EQ(-1, flag4);
    EXPECT_EQ(-1, flag5);
    
}

TEST(LOGGER, INFO){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(2);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(0, flag1);
    EXPECT_EQ(0, flag2);
    EXPECT_EQ(0, flag3);
    EXPECT_EQ(-1, flag4);
    EXPECT_EQ(-1, flag5);
    
}

TEST(LOGGER, DEBUG){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(1);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(0, flag1);
    EXPECT_EQ(0, flag2);
    EXPECT_EQ(0, flag3);
    EXPECT_EQ(0, flag4);
    EXPECT_EQ(-1, flag5);
    
}

TEST(LOGGER, TRACE){
    system_log::Logger* logger = system_log::Logger::getLogger();
    logger->set_level(0);
    std::string log = "log messages";
    int flag = logger->fatal(log);
    int flag1 = logger->error(log);
    int flag2 = logger->warn(log);
    int flag3 = logger->info(log);
    int flag4 = logger->debug(log);
    int flag5 = logger->trace(log);
    EXPECT_EQ(0, flag);
    EXPECT_EQ(0, flag1);
    EXPECT_EQ(0, flag2);
    EXPECT_EQ(0, flag3);
    EXPECT_EQ(0, flag4);
    EXPECT_EQ(0, flag5);
    
}

TEST(LOGGER, GETLOGGER){
    system_log::Logger* logger = system_log::Logger::getLogger();
    system_log::Logger* logger1 = system_log::Logger::getLogger();
    EXPECT_TRUE(logger != NULL);
    EXPECT_TRUE(logger1 != NULL);
    EXPECT_TRUE(logger1 == logger);
    
}