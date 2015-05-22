## Multi-thread Execution ##

TOPAZ has been programmed as a multi-threaded simulator to be executed on multi-core systems with shared memory. We have used pthreads (POSIX standard for threads), so the pthread library is needed by this option to be used. By default multithreading is disabled. To enable it you need to selecta at compile time it.  Just enable the 'PTOPAZ' environment variable on `TOPAZ/mak/Makefile`. Multithread has a "small" overhead in single thread simulations, therefore it is advised to be disabled in such cases. If the simulator has been compiled using this option, when you run a simulation with:

```
$shell ./TPZSimul -s REALLY_BIG_NETWORK -N <num_threads> 
***** Using TOPAZ with <num_threads> threads ***** 
```


Multithreaded simulation is advised for very big networks or the use of TOPAZ in conjunction with external full system simulators. TOPAZ has been successfully used with network with more than one million of routers running up to 12 cores. The optimal number of threads is strongly dependent on the size of the network and memory or cores available in the server.

### Implementation ###
The current implementation uses a master thread that controls a set of configurable slave threads, that actually run the simulation.  The nodes and links of the simulated network are assigned linearly to each slave thread. In this way there is no restriction in the number of threads used in the simulation and geometry of the simulated network.

The simulation is performed following sequential process:
  1. The slave threads run during the first half of the clock cycle the simulation of the _routers_.
  1. A subsequent **barrier** (that involves only the slave threads) control the access to the simulation of the _connections_ in the second half of the clock cycle.
  1. At the end of the clock cycle another **barrier**, now that involves all the threads (including the master) controls the next clock cycle simulation, simulation finalization or the synchronization with external full system simulator.

All shared variables (such as statistics) has been managed to avoid unnecessary synchronization beyond the **clock barriers**. With multithreaded simulation the use of the statically preallocated flit POOL is not advised. Remember to disable it in `Makefile`.