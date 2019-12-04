#include"gtest.h"
#include"/Repos/— ¿◊≈ÕÕ€≈ — √»“¿(19 —“”ƒ»ﬂ)/mp2-lab3-stack/Stack.h"


TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> s(15));
}
TEST(TStack, cant_create_stack_with_negotive_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-15));
}
TEST(TStack, can_push_elem_in_stack)
{
	int a = 5;
	TStack<int> s(5);
	ASSERT_NO_THROW(s.Push(a));
}
TEST(TStack, cant_push_elem_in_full_stack)
{
	int a = 5;
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	bool f = s.IsFull();
	EXPECT_EQ(1, f);
	ASSERT_ANY_THROW(s.Push(a));
}
TEST(TStack, can_pop_elem_from_stack)
{
	int a;
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(a = s.Pop());
}
TEST(TStack, cant_pop_elem_from_empty_stack)
{
	int a;
	TStack<int> s(5);
	ASSERT_ANY_THROW(a = s.Pop());
}
TEST(TStack, can_look_top_elem_in_no_empty_stack)
{
	
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(s.Top());
}
TEST(TStack, cant_look_top_elem_in_empty_stack)
{

	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Top());
}
TEST(TStack, poped_elem_is_equal_to_top_elem)
{
	int a, k;
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	a = s.Top();
	k = s.Pop();
	EXPECT_EQ(a, k);
}
TEST(TStack, copied_stack_has_own_memory)
{
	TStack<int> s(5);
	TStack<int> l(s);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	for (int i = 0; i < 5; i++)
	{
		l.Push(i+1);
	}
	int a, k;
	a = s.Pop();
	k = l.Pop();
	EXPECT_NE(a, k);
}
TEST(TStack, can_clear_stack)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	s.Clear();
	bool f = s.IsEmpty();
	EXPECT_EQ(1, f);
}
TEST(TStack, can_assign_stack_to_stack)
{
	TStack<int> s(5);
	TStack<int> l(6);
	ASSERT_NO_THROW(l = s);
}
TEST(TStack, assigning_operator_change_size)
{
	TStack<int> s(5);
	TStack<int> l(6);
	l = s;
	EXPECT_EQ(s.GetSize(), l.GetSize());
}
