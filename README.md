*This project was created for 42 cursus by ssabound*

# Philosopher

## Description

Philosophers is a project that implements the **dining philosophers problem**.
 
A certain number of philosophers are seated around a round table. Between each philosopher lies a fork. They follow a routine:
 
- Eat
- Sleep
- Think
To eat, a philosopher needs both the fork on his left and the fork on his right. There are as many forks as there are philosophers.
 
To solve this, the project introduces multi-threaded programming:
 
- Thread creation and synchronization with `pthread`
- Shared resource protection using mutexes


## Instructions

### Compilation

```bash 
   make
```
 Other available targets: `make re` to recompile from scratch, `make fclean` to remove all build files, `make clean` to remove object files only.
### Execution

```bash
    ./philo number_of_philosophers time_to_die  time_to_eat  time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Argument

- number_of_philosophers :  Number of philosophers
- time_to_die :  Time in ms after which a philosopher dies if they haven't eaten
- time_to_eat : Duration in ms of a meal
- time_to_sleep :  Duration in ms of sleep
- [number_of_times_each_philosopher_must_eat] : (optional) Program stops once every philosopher has eaten at least this many times


## Ressouces

For this project I used especially the peer learning and used AI to understand different concepts. Links I used :

- https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

- https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/