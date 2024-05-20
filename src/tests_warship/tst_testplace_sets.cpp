#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

class test_placement
{
public:
    int B[100];
    test_placement(int *A)
    {
        for(int i = 0; i < 100; i++)
        {
            B[i] = A[i];
        }
    }
    int killedSh(int nc)
    {
        //obj->enemyCells[nc]->setColor(Qt::red);
        B[nc] = 1;
        if(nc >= 1)
        {
            if(B[nc-1] == 2){
                int i = nc - 1;
                while(B[i] == 2)
                {
                    B[i] = 1;
                    if(i == 0) break;
                    i--;
                }
            }
        }
        if(nc < 99)
        {
            if(B[nc+1] == 2)
            {
                int i = nc + 1;
                while(B[i] == 2)
                {
                    B[i] = 1;
                    if(i == 100) break;
                    i++;
                }
            }
        }
        if(nc <= 89)
        {
            if(B[nc+10] == 2)
            {
                int i = nc + 10;
                while(B[i] == 2)
                {
                    B[i] = 1;
                    //disconnect(obj->enemyCells[i], SIGNAL(choosedCell(int)), this, SLOT(attacking(int)));
                    if(i == 100) break;
                    i+=10;
                }
            }
        }
        if(nc >= 10)
        {
            if(B[nc-10] == 2)
            {
                int i = nc - 10;
                while(B[i] == 2)
                {
                    B[i] = 1;
                    if(i == 0) break;
                    i-=10;
                }
            }
        }
        int counter = 0;
        for(int i = 0; i < 100; i++) if(B[i] != 1) counter++;
        return counter;
    }

};

TEST (test_placement_0, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 2;
    test_placement s(A);
    int a = s.killedSh(0);
    EXPECT_EQ(a, 0);
}
TEST (test_placement_1, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 0;
    A[0] = 2;
    A[1] = 2;
    test_placement s(A);
    int a = s.killedSh(0);
    EXPECT_EQ(a, 98);
}
TEST (test_placement_2, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 0;
    A[0] = 2;
    A[1] = 2;
    test_placement s(A);
    int a = s.killedSh(1);
    EXPECT_EQ(a, 98);
}
TEST (test_placement_3, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 0;
    A[0] = 2;
    A[10] = 2;
    A[20] = 2;
    test_placement s(A);
    int a = s.killedSh(10);
    EXPECT_EQ(a, 97);
}
TEST (test_placement_4, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 0;
    A[90] = 2;
    A[80] = 2;
    A[70] = 2;
    test_placement s(A);
    int a = s.killedSh(80);
    EXPECT_EQ(a, 97);
}
TEST (test_placement_5, Test_set_sm)
{
    int A[100];
    for(int i = 0; i < 100; i++) A[i] = 0;
    A[9] = 2;
    test_placement s(A);
    int a = s.killedSh(9);
    EXPECT_EQ(a, 99);
}
