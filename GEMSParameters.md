# GEMS Parameters to control TOPAZ #

A new set of parameters has been added to `ruby` configuration in order to ease the pain of make lots of simulations with lots of configurations. In this way, you can overwrite SML simulation configuration (something like command line options). As you know, you can use environment variable to modify then from running scripts using `mfacet.py`. Also they can be modified statically at compile time of ruby. At this time we do not supply the equivalent `gen-*.py` to auto-generate launching script files. They are strongly site specific (queue system and workloads available).

The parameters defined are:
  * **g\_TOPAZ\_SIMULATION:**  This defines the simulation defined in SGML you want to use. It should be coherent with the upper working size and configuration. It may use **FILE\_SPECIFIED\_TOPOLOGY** in CMP or **TORUS\_2D** in SMP. _You should be aware that file specification should agree with TOPAZ network definition_
  * **g\_TOPAZ\_FLIT\_SIZE:** Establish the flit size in **bytes**. It determines the packet length. Be aware that flow control and buffering sizes should be defined in accordance.
  * **g\_TOPAZ\_CLOCK\_RATIO:** Establish the clock ratio between memory system and interconnection network. A number x greater than 1 indicates that the network clock is x times slower that then memory system. Accept non integers ratios. Also accept numbers bellow 1.
  * **g\_TOPAZ\_COMMAND\_SIZE:** Indicates the number of bytes in a command message. Ruby statically in some place of the code says 16bytes, which it might be ok... or might be no.
  * **g\_TOPAZ\_TRACE\_FILE:** Trace for TOPAZ
  * **g\_MAX\_MESSAGES\_THROUGH\_GEMS:** Number of messages within ruby original network simulator required to activate TOPAZ. 0 means TOPAZ is always running. This technique allows speedup simulations with limited error. More info available [here](GEMSAdaptiveRun.md)