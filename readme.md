# 🔄 Mini Round-Robin Scheduler — Android/Linux Kernel Inspired

A lightweight simulation of a **Round-Robin process scheduler** written in C++, inspired by the scheduling algorithm at the heart of Android OS and Linux kernels.

## 📖 What is Round-Robin Scheduling?

Round-Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot called a **quantum** (20ms here). Processes take turns in a circular queue — no process is prioritized over another. When a process finishes its quantum, it goes to the back of the queue and waits for the next turn.

This is exactly how Android manages running apps like Firefox, Chrome, and CLion "simultaneously" on your device.

## 🧠 How It Works

```
Queue: [firefox] → [terminal] → [code] → [chrome] → ...

tick 1 → firefox runs 20ms   → back of queue
tick 2 → terminal runs 20ms  → back of queue
tick 3 → code runs 20ms      → back of queue
...
tick N → code finishes        → removed from queue ✅
```

Each tick:
1. The scheduler takes the **first process** in the queue
2. Runs it for `min(remaining_time, 20ms)`
3. If finished → removes it from the queue
4. If not finished → updates remaining time and pushes it to the **back of the queue**
5. Repeats until the queue is empty

## 🛠️ Tech Stack

- **Language**: C++17
- **Compiler**: g++
- **Data structure**: `std::queue<Process>` — naturally models FIFO scheduling
- **No external dependencies**

## 🚀 Build & Run

```bash
g++ main.cpp -o scheduler
./scheduler
```

## 📊 Sample Output

```
[tick] Running: firefox (pid=934) | remaining: 300ms → 280ms
[tick] Running: terminal (pid=904) | remaining: 400ms → 380ms
[tick] Running: code (pid=302) | remaining: 40ms → 20ms
[tick] Running: chrome (pid=553) | remaining: 100ms → 80ms
...
[tick] Finished: code (pid=302)
...
[tick] Finished: firefox (pid=934)
...
[tick] Finished: kicad (pid=890)
```

## 🏗️ Project Structure

```
main.cpp
├── struct Process       → pid, name, remaining_time
├── runProcess()         → simulates one quantum of execution
├── launchScheduler()    → round-robin loop over the process queue
└── main()               → initializes processes and starts scheduler
```

## 💡 Key Design Decisions

- **`std::queue` over `std::vector`** — enforces strict FIFO order, no random access needed
- **Simulation mode** — no real timers or sleep calls; time is decremented mathematically for simplicity and speed
- **`long` for remaining time** — handles underflow when remaining time < quantum (avoids unsigned integer overflow)
- **`const Process&` parameter** — `runProcess` doesn't mutate the process directly; it returns the new remaining time for the caller to apply

## 📚 Concepts Illustrated

- Round-Robin CPU scheduling
- Process queue management
- Quantum-based preemption
- Process lifecycle (running → finished)

## 👨‍💻 Author

**Ferdinand ATI** — Electronics Engineering Student & C++ Developer  
ENSET Lokossa, Bénin 🇧🇯  
[LinkedIn](https://www.linkedin.com/in/ferdinand-ati) | [GitHub](https://github.com/Ferdinaelectro1)