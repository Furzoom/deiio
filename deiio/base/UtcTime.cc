// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/base/UtcTime.h>

#include <inttypes.h>  // PRId64
#include <stdio.h>
#include <sys/time.h>

namespace deiio {

UtcTime::UtcTime()
  : microSecondsSinceEpoch_(0) {}

UtcTime::UtcTime(int64_t microseconds)
  : microSecondsSinceEpoch_(microseconds) {}

string UtcTime::toString() const {
  char buf[32] = {0};
  int64_t seconds = microSecondsSinceEpoch_ / kMicroSecondsPerSecond;
  int64_t microseconds = microSecondsSinceEpoch_ % kMicroSecondsPerSecond;
  snprintf(buf, sizeof(buf) - 1, "%" PRId64 ".%06" PRId64 "",
           seconds, microseconds);
  return buf;
}

UtcTime UtcTime::now() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  int64_t seconds = tv.tv_sec;
  return UtcTime(seconds * kMicroSecondsPerSecond + tv.tv_usec);
}

UtcTime UtcTime::invalid() {
  return UtcTime();
}

}  // namespace deiio

