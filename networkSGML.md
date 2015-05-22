# Introduction #
<p align='justify'>
The Network.sgml file describes the way routers are connected to each other. This includes topology, network size, number of dimensions, delay of the links and the router employed at each node. While <a href='simSGML.md'>simulation</a> of the <a href='routerSGML.md'>router microarchitecture</a> requires multiple tags for a complete definition, a single tag is enough to describe all network parameters. Below we provide an example of a network definition which belongs to this SGML file.<br>
</p>

```
<MeshNetwork id="M44_WH_NOC" sizeX=4  sizeY=4  router="MESH-WH-NOC" delay=1>
```



---

# Elements #
#### Topology ####
<p align='justify'>The first word of the tag determines the topology selected for the network. TOPAZ provides the following topologies, identified by its corresponding words:<br>
<ul><li>MeshNetwork: connect nodes using a mesh topology (like the example).<br>
</li><li>TorusNetwork: connect nodes using a torus topology.<br>
</li><li>MidimewNetwork: connect nodes using a midimew topology.<br>
</li><li>SquareMidimewNetwork: connect nodes using a square midimew topology.</li></ul>

<h4>Identifier</h4>
<p align='justify'>The 'id=' component is the identifier of the network. This label is used by <a href='simSGML.md'>simulation sgml</a> to reference the network used in simulations.<br>
<br>
<h4>sizeX</h4>
<p align='justify'>Defines the size of the network (number of routers) in the X-axis. For midimew networks it has a different meaning, defining in this case the total amount of nodes in the network.<br>
<br>
<h4>sizeY</h4>
<p align='justify'>Defines the size of the network in the Y-axis. Despite being bi-dimensional, Midimew topologies have a singular matching and the total amount of routers is defined in X axis. For this reason, this value must be set to one in this case.<br>
<br>
Playing with this value will allow us to obtain additional topologies. If we choose a TorusNetwork and fix SizeY=1 we are defining a Ring topology.<br>
<br>
<h4>sizeZ</h4>
<p align='justify'>Optional. Defines the size of the network in the Z-axis. If not present in the description tag its default value is one, meaning that we will be working with bi-dimensional networks.<br>
<br>
<h4>router</h4>
<p align='justify'>
This label defines the router architecture that will be employed at each network node. Notice that not every router is valid for any network topology or for every number of dimensions. This way, despite sharing all working characteristics (flow control, routing, buffer size, etc.) routers for 2D and 3D networks have always a different description. Similarly, some router parameters limit topologies that can be selected. For example, if we want to work with a router with Dimension Order Routing, and WH flow control, only Mesh topologies are eligible, because torus topologies will produce a network deadlock.<br>
</p>

<h4>delay</h4>
<p align='justify'>The delay parameter determines the amount of cycles required to move a flit between two neighbor routers. For the moment, this parameter can only be configured with the same value for every link. Different delays for different dimensions are not supported yet.