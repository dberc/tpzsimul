# Introduction #

<p align='justify'>Multicast support is a desireable feature in any network simulator, due to the important performance advantages in network performance provided by hardware multicast support. Most of the router architectures in TOPAZ are able to work with multi-destination traffic. Both Bubble Routers, any Virtual Channel Router configuration (VCTM) and Rotary are able to deal with this kind of messages. In contrast, structures such as Bufferless router cannot provide multicast support due to correctness issues, while Bidirectional router still needs to implement this feature.<br>
<br>
<p align='justify'>The implementation of multicast support in TOPAZ is performed through routing masks. A bit-vector carried by the message indicates which are its destinations (positions to <i>1</i> value). The length of this vector must be equal to the number of network nodes. Additionally, each output port of each router holds another mask of the same length, indicating in this case which destinations are reachable through that output port with the routing algorithm selected. Two simple bit-to-bit operations between message and port masks provide the necessary information to route these messages. It is important to notice that the value provided to port masks is going to determine the routing policy selected.<br>
<br>
<p align='justify'>Multicast support is limited at this moment, and active work is being carried to improve its features in future TOPAZ versions. As this is intended to be a collaborative tool, external collaborations will be wellcome. Next section describes the main current limitations faced by multicast support in TOPAZ<br>
<br>
<br>
<hr />
<h1>Limitations</h1>

<p align='justify'>The most important limitation might reside on the maximum number of network nodes supported in multicast traffic. Currently masks are coded through a 64-bit data type in c++ (unsigned long long), which limits the number of nodes to 64. An 8x8 mesh network or a three dimensions 4x4x4 network is the maximum size allowed for multicast. NoC typical sizes have made this size enough for the moment, but in the near future larger networks will be required.<br>
<br>
<p align='justify'>Messages with multiple destinations have been limited to 1-flit size. This is the common case in on-chip environments and keeps coding much simple, two important reasons for this limitation. The parent version of TOPAZ, SICOSYS, provided support for multi-flit multi-destination messages. This feature was limited to routers with packet-level flow control (Cut-Through). If demanded, this feature could be made available in TOPAZ for Bubble routers with relatively small effort.<br>
<br>
<p align='justify'>For the moment, functions that automatically calculate port masks (both DOR and ADAP) only work for Bi-dimensional networks. Re-building this code to provide 3-D support is a work in progress.