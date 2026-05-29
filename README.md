# Plazza

A pizza restaurant simulation using processes, threads and IPC.

## Description

Plazza simulates a pizza restaurant. A reception takes orders from stdin, distributes them across kitchens, and each kitchen manages a pool of cooks running in separate threads. Kitchens run as child processes and communicate with the reception using POSIX message queues.

## Build

```
mkdir build && cd build
cmake ..
make
```

## Usage

```
./plazza <multiplier> <nb_cooks> <restock_time>
```

- `multiplier` : cooking time multiplier (float, e.g. 1.0)
- `nb_cooks` : number of cooks per kitchen (integer)
- `restock_time`: time in ms between ingredient restocks (integer)

## Commands

Orders are entered on stdin. Multiple orders can be placed on the same line separated by semicolons.

```
<pizza> <size> x<quantity>[; <pizza> <size> x<quantity>; ...]
```

Available pizzas: `Regina`, `Margarita`, `Americana`, `Fantasia`

Available sizes: `S`, `M`, `L`, `XL`, `XXL`

Example:
```
Regina XL x2; Margarita S x1
```

Special commands:
- `status` : print the status of each kitchen (alive, free cooks, remaining stock)
- `quit`   : stop all kitchens and exit

## Architecture

- `Reception` : reads stdin, parses orders, manages kitchens
- `Kitchen` : child process, holds a pool of cooks, manages ingredient stock
- `Cook` : runs in a thread, consumes ingredients and sleeps for cook time
- `IPC` : wraps POSIX message queues for process communication
- `Process` : wraps fork/waitpid
- `Mutex` : wraps pthread_mutex
- `ScopedLock` : RAII lock guard
