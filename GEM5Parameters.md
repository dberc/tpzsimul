The parameters defined at `gem5/config/Ruby.py` are:

| **Option** | **type** | **help** | **Default value** |
|:-----------|:---------|:---------|:------------------|
|   **--topaz-init-file**  | string   | File that declares _simulation_.sgm, _network_.sgm and _router_.sgm" | "./TPZSimul.ini"  |
|  **--topaz-network**  | string   |  Network listed in _simulation_.sgm to be used by TOPAZ| _unset_           |
|   **--topaz-flit-size** | int      |  Number of bytes per physical router-to-router wire | 16                |
|   **--topaz-clock-ratio** |  int     | Memory-network clock multiplier| 1                 |
| **--topaz-adaptive-interface-threshold** |  int     | Number of messages that has to be transmitted through ruby before to activate TOPAZ (see [here](GEMSAdaptiveRun.md) how this works)| 0                 |


_Multithreaded simulation has been not yet implemented for this interface_