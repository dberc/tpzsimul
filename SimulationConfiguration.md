# Command Options #

**_CAVEAT:_**

_Some switches may not  work with some routers and/or networks. For example **if you have a router with buffer sizes specified buffer by buffer in the SGML**, the **-u** option **is ignored.** You have to change SGML to modify those values (or play with the source the source code to override SGML values with command line option._

_Other parameters, such as **message length greater than 1 packet** could be **ignored** (message is associated to network interface level and packets to the network). To have multi-message support you need disassembling/reassembling logic at network interfaces, and by default is not implemented in most consumers and injectors_

## Most common options ##

  * `'s' <simulation_name>` : simulation\_name must match one of the tags at the `SimulationSgml` file.
  * `'l' <normalized_applied_load>` : applied load expressed in percentage of bisection (overwrites the value given at `SimulationSgml`).
  * `'p' <applied_load>` : applied load expressed in flit per cycle and per router injected (overwrites the value given at `SimulationSgml`).
  * `'q'` : used for silent messaging. During simulation progress nothing is printed.
  * `'c' <simulation_cycles>` : overwrites the number of simulation cycles given at `SimulationSgml`.
  * `'t' <traffic_pattern >` : overwrites the traffic pattern set in `SimulationSgml`.
  * `'L' <packet_length>` : overwrites packet length given at `SimulationSgml`.
  * `'u' <buffer_size>` : overwrites buffer size given in `RouterSgml`.
  * `'v' <level>` : verbosity level in statistics.
  * `'F' <filename>`: Initialization file. By default `./TPZSimul.ini`

## Traffic Options ##
  * `'B' <length, probability>` : probability of the bimodal traffic generation. The two parameters required are for describing the length and the probability of the second type of message.
  * `'D' ` : discards packets at injection if injection queues are saturated. This avoids large memory usage.

## Result Options ##
  * `'m' <printing_period>` : prints each `printing_period` the network statistics. Useful to analyze network evolution during a simulation.
  * `'d' <packets_samples>` : prints each the reception of `Packets_samples` the network statistics. Useful to analyze network evolution during a simulation.
  * `'l' <printing_period>` : prints each `printing_period` the injection and consumption maps.
  * `'v' <verbosity>` : different levels of detail when printing simulation results. Values range from 0 to 3.

## Other Options ##
  * `'b' <buffer_file>` : prints to the file buffer\_file the evolution of buffers occupation. Needs additional software to interpret the resulting file.
  * `'f' <pattern_file>` : file containing a description of traffic pattern that overwrites the one in `SimulationSgml`.
  * `'r' <random_seed>` : when used, a random seed is generated for the simulation performed.
  * `'N' <number_of_threads>` : defines the number of children running in a multi-thread execution (default=1).