_This project has been created as part of the 42 curriculum by tmkrtumy._

# Philosophers

## Description

The **main goal** of Philosophers is to learn how to work with **threads, mutexes, synchronization, and shared resources** without accidentally creating complete chaos.

The project is based on the classic **Dining Philosophers Problem**.

A number of philosophers are sitting around a table. Each philosopher repeatedly:

* thinks
* takes two forks
* eats
* sleeps

Unfortunately, every fork is shared between two philosophers, and philosophers have the inconvenient habit of **dying if they do not eat in time**.

The challenge is therefore to correctly synchronize all philosophers while avoiding:

* **data races**
* **deadlocks**
* incorrect timing
* philosophers stealing each other's forks
* philosophers mysteriously dying because the scheduler had other plans

Each philosopher is represented by a **thread**, while forks are protected using **mutexes**.

The simulation must correctly detect when a philosopher dies and optionally stop when every philosopher has eaten the required number of times.

## Instructions

1. Clone the repository and enter the project directory.

2. Compile the project:

```bash
make
```

3. Run the program:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All time values are given in **milliseconds**.

For example:

```bash
./philo 5 800 200 200
```

This starts a simulation with:

* 5 philosophers
* 800 ms before a philosopher dies from starvation
* 200 ms to eat
* 200 ms to sleep

You can also specify how many times every philosopher must eat:

```bash
./philo 5 800 200 200 7
```

In that case, the simulation finishes when every philosopher has eaten at least **7 times**, unless somebody dies first.

To clean the generated object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

## Resources

| Concept                     | Link                                                             |
| --------------------------- | ---------------------------------------------------------------- |
| POSIX Threads               | https://man7.org/linux/man-pages/man7/pthreads.7.html            |
| `pthread_create`            | https://man7.org/linux/man-pages/man3/pthread_create.3.html      |
| Mutexes                     | https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html |
| `gettimeofday`              | https://man7.org/linux/man-pages/man2/gettimeofday.2.html        |
| Dining Philosophers Problem | https://en.wikipedia.org/wiki/Dining_philosophers_problem        |
| Race Conditions             | https://en.wikipedia.org/wiki/Race_condition                     |
| Deadlocks                   | https://en.wikipedia.org/wiki/Deadlock                           |

### AI usage

* understand how to check data races
* help prepare and improve this README


> Beware !! do not click on suspicious links :)
