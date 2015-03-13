#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(PointTests)
	{
	public:
	
		TEST_METHOD(given_point_when_x_is_negative_then_should_throw_excpetion)
		{
			//Arrange
			const int NEGATIVE_X_VALUE = -1;

			//Action
			bool exceptionThrown = false;
			try
			{
				Point point(NEGATIVE_X_VALUE, 10);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}
			
			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(given_point_when_y_is_negative_then_should_throw_excpetion)
		{
			//Arrange
			const int NEGATIVE_Y_VALUE = -1;

			//Action
			bool exceptionThrown = false;
			try
			{
				Point point(10, NEGATIVE_Y_VALUE);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(given_2_points_to_compare_when_they_are_not_equal_then_should_return_false)
		{
			//arrange
			Point point1(0, 1);
			Point point2(0, 2);
			
			//action 
			bool compareResult = point1 == point2;
			
			//assert
			Assert::IsFalse(compareResult);
		}

		TEST_METHOD(given_2_points_to_compare_when_they_are_equal_then_should_return_true)
		{
			//arrange
			Point point1(1, 1);
			Point point2(1, 1);

			//action 
			bool compareResult = point1 == point2;

			//assert
			Assert::IsTrue(compareResult);
		}

		TEST_METHOD(given_2_points_to_compare_difference_when_they_are_not_equal_then_should_return_true)
		{
			//arrange
			Point point1(1, 0);
			Point point2(2, 0);

			//action 
			bool compareResult = point1 != point2;

			//assert
			Assert::IsTrue(compareResult);
		}

		TEST_METHOD(given_2_points_to_compare_difference_when_they_are_equal_then_should_return_false)
		{
			//arrange
			Point point1(1, 1);
			Point point2(1, 1);

			//action 
			bool compareResult = point1 != point2;

			//assert
			Assert::IsFalse(compareResult);
		}
	};
}