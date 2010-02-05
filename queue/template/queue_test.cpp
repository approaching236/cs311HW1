#include "queue.h"
#include <gtest/gtest.h>

using namespace std;

class QueueTest : public testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST(QueueTest, constructor) {
  queue q;
  EXPECT_TRUE(q.isEmpty());
  EXPECT_EQ(0, q.getSize());
}

TEST(QueueTest, add) {
  queue q;
  q.add('a');
  EXPECT_FALSE(q.isEmpty());
  EXPECT_EQ(1, q.getSize());
}

TEST(QueueTest, isFull) {
  queue q;
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  EXPECT_FALSE(q.isFull());
  q.add('a');
  EXPECT_TRUE(q.isFull());
}

TEST(QueueTest, remove) {
  queue q;
  char c;

  q.add('a');
  EXPECT_EQ(1, q.getSize());
  q.add('b');
  q.remove(c);
  EXPECT_EQ(1, q.getSize());
  EXPECT_EQ('a', c);
}

TEST(QueueTest, remove_failure) {
  queue q;
  char c;
  EXPECT_THROW(q.remove(c), queue::Underflow);
}

TEST(QueueTest, add_failure) {
  queue q;
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  q.add('a');
  EXPECT_TRUE(q.isFull());
  EXPECT_THROW(q.add('f'), queue::Overflow);
}

TEST(QueueTest, get_front) {
  queue q;
  char c;
  q.add('a');
  q.add('b');
  q.getFront(c);
  EXPECT_EQ('a', c);
  q.remove(c);
  q.getFront(c);
  EXPECT_EQ('b', c);
}

TEST(QueueTest, check_front_underflow) {
  queue q;
  char c;
  EXPECT_THROW(q.getFront(c), queue::Underflow);
}

TEST(QueueTest, go_to_back_fail) {
  queue q;
  EXPECT_THROW(q.goToBack(), queue::Underflow);
}

TEST(QueueTest, go_to_back) {
  queue q;
  char c;
  q.add('a');
  q.add('b');
  q.goToBack();
  q.remove(c);
  EXPECT_EQ('b', c);
  q.remove(c);
  EXPECT_EQ('a', c);

}

TEST(QueueTest, modulus_cases) {
  queue q;
  char c;
  for (int i = 0; i < 9; ++i) {
    for (int i = 0; i < 9; ++i) {
      q.add('a');
    }
    for (int i = 0; i < 9; ++i) {
      c = ' '; // resets char to ' ' to see if it successfully obtains the char from the queue
      q.remove(c);
      EXPECT_EQ('a', c);
    }
  }
}

int main(int argc, char **argv) {
  std::cout << "Running main() from gmain.cc\n";

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
