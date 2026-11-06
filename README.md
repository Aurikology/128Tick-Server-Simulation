# 128Tick Server Simulation

A microsecond-precision benchmark comparing standard OS heap allocation against fixed-size object pools, built to explore the memory access patterns that matter in high-tick-rate game servers.

## Why this exists

Game servers running at 128 ticks per second have ~7.8 ms per frame to process every player's state. At that budget, a cache miss on player data is the difference between a smooth tick and a dropped one. This project benchmarks the cost of naive `new[]`/`delete[]` allocation against contiguous, pool-allocated memory to quantify the cache locality advantage.

## What it does

- **Scoped microsecond timer** — RAII timer using `std::chrono::high_resolution_clock` that starts on construction and prints elapsed time on destruction. Zero overhead when optimized.
- **Baseline benchmark** — Allocates and linearly writes 100,000 integers via standard OS allocation (`new int[]`), measuring the raw cost of heap allocation + sequential access.
- **Deterministic state tracking** — Structure designed for extending into a fixed-size object pool where entity state (position, health, input) lives in a contiguous block, keeping hot data on the same cache lines.

## Build

```bash
mkdir -p build && cd build
cmake ..
cmake --build .
```

Tested with MSVC (Visual Studio 17 2022) and GCC. Requires C++17 or later.

## Project structure

```
include/
  Timer.h         # RAII microsecond timer
  monitor.h       # Sensor calibration interface
src/
  main.cpp        # Benchmark entry point
  monitor.cpp     # Calibration stub
CMakeLists.txt    # Build config
```

## Tech

`C++17` `CMake` `std::chrono` `RAII` `cache locality`
