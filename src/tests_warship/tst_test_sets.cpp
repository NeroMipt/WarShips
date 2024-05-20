#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QString>
#include <QValidator>


using namespace testing;

QString focusOutEvent(QString str)
{
    QString ip_address = QString("");
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    int pos = 0;
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, 0);
    ip_address = str;



    if(ip_address.isEmpty() || !(ipValidator->validate(ip_address, pos) == QValidator::Acceptable))
    {
        ip_address = QString("");
    }
    return ip_address;
}

TEST(test_case0, test_sets)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(test_case1, test_sets)
{
    QString str = focusOutEvent("");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case2, test_sets)
{
    QString str = focusOutEvent("dfsfdsdfsdfsf");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case3, test_sets)
{
    QString str = focusOutEvent("192.12313.1231.231.124124.132");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case4, test_sets)
{
    QString str = focusOutEvent("001.001.001.001");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 0);
}

TEST(test_case5, test_sets)
{
    QString str = focusOutEvent("192.11.123.0");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 0);
}

TEST(test_case6, test_sets)
{
    QString str = focusOutEvent("192.168.01.5");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 0);
}

TEST(test_case7, test_sets)
{
    QString str = focusOutEvent("123.fdf.32.df");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case8, test_sets)
{
    QString str = focusOutEvent("23..44.3.44");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case9, test_sets)
{
    QString str = focusOutEvent("asda.22.22.22");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case10, test_sets)
{
    QString str = focusOutEvent("0.0.0.0");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 0);
}

TEST(test_case11, test_sets)
{
    QString str = focusOutEvent("\n");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case12, test_sets)
{
    QString str = focusOutEvent("\t");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case13, test_sets)
{
    QString str = focusOutEvent("\0");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case14, test_sets)
{
    QString str = focusOutEvent("....1232443");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case15, test_sets)
{
    QString str = focusOutEvent("please, let me enter!!!");
    int i = 0;
    if(str.isEmpty())i++;
    EXPECT_EQ(i, 1);
}

TEST(test_case16, test_sets)
{
    QString str = focusOutEvent("!!!!");
    int i = 0;
    if(str.isEmpty())i++;
    ASSERT_EQ(i, 1);
}

