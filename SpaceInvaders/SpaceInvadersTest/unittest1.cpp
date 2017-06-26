#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\SpaceInvaders\stopwatch.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <mfcaptureengine.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceInvadersTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(StopWatchStart)
		{
			Stopwatch stopwatch = Stopwatch();
			stopwatch.Start();
			Assert::AreEqual(true, stopwatch.IsRunning(), L"message", LINE_INFO());
		}

		TEST_METHOD(StopWatchStop)
		{
			uint64_t sleep_time = 500;
			Stopwatch stopwatch = Stopwatch();
			stopwatch.Start();
			Sleep(sleep_time);

			bool b_in_range = 
				std::abs((long)sleep_time - (long)stopwatch.GetTime()) < 2
				? true
				: false;
			stopwatch.Stop();
			const wchar_t *message = L"Stopped at: " + stopwatch.GetTime();
			Assert::AreEqual(true, b_in_range, message, LINE_INFO());
		}

		TEST_METHOD(StopWatchReset)
		{
			Stopwatch stopwatch = Stopwatch();
			stopwatch.Start();
			Sleep(500);
			stopwatch.Stop();
			stopwatch.Reset();
			uint64_t correct = 0;
			const wchar_t *message = L"Time is: " + stopwatch.GetTime();
			Assert::AreEqual(correct, stopwatch.GetTime(), message, LINE_INFO());

		}

		TEST_METHOD(StopWatchResume)
		{
			uint64_t sleep_time = 500;
			Stopwatch stopwatch = Stopwatch();
			std::ostringstream os;

			stopwatch.Start();
			Sleep(sleep_time);
			stopwatch.Stop();
			os << std::string("before resume: ") << stopwatch.GetTime() << std::endl;
			stopwatch.Resume();
			Sleep(sleep_time);
			stopwatch.Stop();
			os << std::string("after resume: ") << stopwatch.GetTime();
			Logger::WriteMessage(os.str().c_str());
			bool b_in_range =
				std::abs((long)sleep_time*2 - (long)stopwatch.GetTime()) < 2
				? true
				: false;

			const wchar_t *message = L"Stopped at: " + stopwatch.GetTime();
			Assert::AreEqual(true, b_in_range, message, LINE_INFO());
		}

	};
}