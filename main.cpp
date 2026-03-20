#include <queue>
#include <iostream>

#define PROCESS_OPERATING_TIME 20

struct Process {
    unsigned int pid;
    const char *name;
    unsigned long remaining_time;
};

static unsigned long runProcess(const Process& process) {
    long remaining_time = process.remaining_time - PROCESS_OPERATING_TIME;
    if(remaining_time < 0) remaining_time = 0;
    std::cout << "[tick] Running: "<<process.name<<" (pid="<<process.pid<<") | "
    "remaining: "<<process.remaining_time<<"ms → "<<remaining_time<<"ms" << std::endl;
    return remaining_time;
}

static int lauchScheduler(std::queue<Process>& process_queue) {
    Process current_process;
    while (!process_queue.empty())
    {
        current_process = process_queue.front();
        unsigned long this_process_remaining_time = runProcess(current_process);
        if(!this_process_remaining_time) {
            std::cout << "[tick] Finished: "<<current_process.name<<" (pid="<<current_process.pid<<")" << std::endl;
            process_queue.pop();
        }
        else {
            current_process.remaining_time = this_process_remaining_time;
            process_queue.push(current_process);
            process_queue.pop();
        }
    }
    return 0;    
}

int main() {
    std::queue<Process> process_queue;
    process_queue.push({934, "firefox",   300});
    process_queue.push({904, "terminal",  400});
    process_queue.push({302, "code",      40});
    process_queue.push({553, "chrome",    100});
    process_queue.push({901, "arduino",   500});
    process_queue.push({873, "clion",     90});
    process_queue.push({123, "ps",        490});
    process_queue.push({334, "ls",        600});
    process_queue.push({890, "kicad",     700});
    process_queue.push({190, "ssh-server",119});
    
    return lauchScheduler(process_queue);
}