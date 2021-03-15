// Copyright 2020 kropachevskiy <kropachev-95@mail.ru>

#include <gtest/gtest.h>

#include <Stack_1.hpp>
#include <Stack_2.hpp>
TEST(Example, EmptyTest) { EXPECT_TRUE(true); }

TEST(Stack_1, NoCopiable_Movable) {
  EXPECT_TRUE(std::is_move_constructible<Stack_1<int>>::value); /* Проверка на наличие конструктора перемещения - да*/
  EXPECT_TRUE(std::is_move_assignable<Stack_1<int>>::value); /* Проверка на наличие оператора перемещения - да*/
  EXPECT_FALSE(std::is_copy_constructible<Stack_1<int>>::value); /* Проверка на наличие конструктора копирования - нет*/
  EXPECT_FALSE(std::is_copy_assignable<Stack_1<int>>::value); /* Проверка на наличие оператора присваивания - нет*/
}

TEST(Stack_1, Rvalue_test) {
  Stack_1<double> a;
  a.push(3.14);
  EXPECT_EQ(a.head(), 3.14);
}

TEST(Stack_1, Lvalue_test){
  Stack_1<std::string> numbers;
  std::string one = "1";
  numbers.push(one);
  EXPECT_EQ(numbers.head(), "1");
  std::string two = "2";
  std::string three = "3";
  numbers.push(two);
  numbers.push(three);
  EXPECT_EQ(numbers.head(), "3");
}

TEST(Stack_1, Pop) {
  Stack_1<int> b;
  b.push(0);
  b.push(1);
  b.push(2);
  b.pop();
  EXPECT_EQ(b.head(), 1);
  b.pop();
  EXPECT_EQ(b.head(), 0);
  b.pop();
}

TEST(Stack_1, Head) {
  Stack_1<int> b;
  b.push(0);
  EXPECT_EQ(b.head(), 0);
  b.push(1);
  EXPECT_EQ(b.head(), 1);
  b.push(2);
  EXPECT_EQ(b.head(), 2);
}
