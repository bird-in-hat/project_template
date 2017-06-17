#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/header_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;


class NAMEAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(NAME, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a application\\..*");
}

TEST_F(NAME, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"arg1", "arg2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}