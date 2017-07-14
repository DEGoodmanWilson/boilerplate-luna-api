////
//// Created by Don Goodman-Wilson on 14/07/2017.
////
//
//#include <gtest/gtest.h>
//
//#pragma once
//
//class Environment :
//        public ::testing::Environment
//{
//public:
//    std::string host;
//
//    virtual void SetUp() override
//    {
//        std::string port{"8080"};
//        if (auto port_str = std::getenv("PORT"))
//        {
//            port = port_str;
//        }
//        host = "http://localhost:" + port;
//    }
//
//    virtual void TearDown() override
//    {
//    }
//};
//
//const Environment* const env{static_cast<Environment *>(::testing::AddGlobalTestEnvironment(new Environment))};