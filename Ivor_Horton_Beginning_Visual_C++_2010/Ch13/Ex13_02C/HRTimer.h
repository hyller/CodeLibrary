#pragma once
#include "windows.h"

class HRTimer
{
public:

  HRTimer(void) : frequency(1.0 / GetFrequency()) { }

  double GetFrequency(void)
  {
    LARGE_INTEGER proc_freq;
    ::QueryPerformanceFrequency(&proc_freq);
    return static_cast<double>(proc_freq.QuadPart);
  }

  void StartTimer(void)
  {
    DWORD_PTR oldmask = ::SetThreadAffinityMask(::GetCurrentThread(), 0);
    ::QueryPerformanceCounter(&start);
    ::SetThreadAffinityMask(::GetCurrentThread(), oldmask);
  }

  double StopTimer(void)
  {
    DWORD_PTR oldmask = ::SetThreadAffinityMask(::GetCurrentThread(), 0);
    ::QueryPerformanceCounter(&stop);
    ::SetThreadAffinityMask(::GetCurrentThread(), oldmask);
    return ((stop.QuadPart - start.QuadPart) * frequency);
  } 
private:

    LARGE_INTEGER start;
    LARGE_INTEGER stop;
    double frequency;
 };
