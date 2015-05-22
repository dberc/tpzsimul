# Introduction #

As a detailed simulator of the network, TOPAZ adds a slow-down to the execution time of GEMS infrastructure. In order to reduce such effect, we have implemented a couple solutions.

# Adaptive Activation #

We have tested that under low-traffic conditions, the simplified network simulator included in ruby is accurate enough. During the simulation of real applications, low-traffic periods mix with heavy-traffic ones, and we have exploited this.

The parameter **g\_MAX\_MESSAGES\_THROUGH\_GEMS** included in rubyconfig.defaults, represents the number of messages on the network that we consider high enough to begin to consider the contention through TOPAZ. When the number of messages crossing GEMS network is larger than this parameter, then messages are injected in TOPAZ (including those which are already on their way). As soon as the number of messages drops bellow the threshold, then GEMS network simulator is used again.

There is an exception when switching between simulators. Whenever there are ordered messages in one of the network simulators, ordered messages will keep being injected through the same simulator until all reach their destinations (then they will follow the general rule).

Keep "g\_MAX\_MESSAGES\_THROUGH\_GEMS: 0" to send all messages through TOPAZ.

# Multi-threaded Execution #

While running with multiple [threads](Multithread.md), there will be a master thread in addition to any number of threads [defined](SimulationConfiguration.md) at execution (1 by default). Since GEMS networks are quite small, you should keep the number of threads fixed to 1.  Whenever we are running only TOPAZ, the master thread will have a negligible workload, since the work was distributed among the children. However, if we execute topaz with GEMS, we must take into account that the parent thread will take care of GEMS, while the children run the network in parallel. Therefore, GEMS and TOPAZ will run in parallel.