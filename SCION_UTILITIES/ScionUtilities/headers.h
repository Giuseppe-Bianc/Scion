#pragma once
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(push)
#pragma warning(disable : 6386 6385 4005)
#endif
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <execution>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numbers>
#include <omp.h>
#include <optional>
#include <random>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "casts.h"
// Restore warning levels.
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(pop)
#endif

static inline constexpr long double infinity = std::numeric_limits<long double>::infinity();
static inline constexpr long double pi = std::numbers::pi_v<long double>;
static inline constexpr long double twoPi = 2 * pi;
static inline constexpr long double halfPi = pi / 2;
