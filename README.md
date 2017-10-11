# SchedulingProcesses
Repository for allocating the first project of the Operating Systems course at Federal University of Paraiba.

## Implemented Algorithms
* First Come, First Served (FCFS)
* Shortest Job First (SJF)
* Round Robin (RR)

The output is composed by measurements of efficiency for each of the algorithms implemented.
It's displayed the average of return time, response time and wait time for a given input.

## Compiling and Running:

To compile, just run the command:

```bash
make
```

To run the executable:

```bash
./escalonador PATH_TO_INPUT_FILE.txt
```

## Example of output:

```bash
./escalonador Instances/ex1.txt
```

    FCFS 30.5 19.5 19.5
    SJF 21.5 10.5 10.5
    RR 31.5 2.0 20.5
