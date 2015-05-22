

# Introduction #

<p align='justify'>
TOPAZ provides an elegant solution to the generic problem of interconnection network simulation. The same compiled version of TOPAZ can be used to experiment with very different architectural proposals. The specification of the type of experiment is performed through three different SGML files. Each file describes a different set of network components: RouterSGML defines the router microarchitecture as well as the main router parameters, NetworkSGML focuses on the network topological aspects and finally, SimulaSGML describes general parameters of the simulation process. An example of the content that can be found at each file is shown below.<br>
</p>
<p align='justify'>
TOPAZ accesses these files through the <a href='GStarted#Step_3:_Use_It.md'>"TPZSimul.ini"</a> file. Configuration files are interpreted by the simulator at runtime, making code recompilation unnecessary if the user wants to use any of the modules included in the simulation. As seen in <a href='SimulationConfiguration.md'>Command line options</a>, some simulation parameters can be overridden if scripting-based simulation is necessary. However, only the specification of the simulation to evaluate (-s command line parameter) is strictly necessary through command line.<br>
</p>

## Router SGML ##

```
<!-- Detailed implementation of Router DOR 2D Bubble  -->
<!-- uses Virtual CutThrough                                           -->
<Router id="MESH-CT-NOC" inputs=4 outputs=4 bufferSize=11 bufferControl=CT routingControl="MESH-DOR">
   <Injector id="INJ" numHeaders=1 typeInj="CT" numMessTypes=4>
   <Consumer id="CONS">
   
   <SimpleRouter id="ROUTER" inputs="5" outputs="5" headerDelay=0 dataDelay=0 vnets=4 >
      <Input  id=1  type="X+">
      <Input  id=2  type="X-">
      <Input  id=3  type="Y+">
      <Input  id=4  type="Y-">
      <Input  id=5  type="Node">
      <Output id=1  type="X+">
      <Output id=2  type="X-">
      <Output id=3  type="Y+">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </SimpleRouter>
   
   <Connection id="C01" source="INJ" destiny="ROUTER.5">
   <Connection id="C02" source="ROUTER.5" destiny="CONS">

   <Input id="1" type="X+"   wrapper="ROUTER.1">
   <Input id="2" type="X-"   wrapper="ROUTER.2">
   <Input id="3" type="Y+"   wrapper="ROUTER.3">
   <Input id="4" type="Y-"   wrapper="ROUTER.4">

   <Output id="1" type="X+"   wrapper="ROUTER.1">
   <Output id="2" type="X-"   wrapper="ROUTER.2">
   <Output id="3" type="Y+"   wrapper="ROUTER.3">
   <Output id="4" type="Y-"   wrapper="ROUTER.4">
</Router>

<!-- Simular to the previous one but using Wormhole-->
<Router id="MESH-WH-NOC" inputs=4 outputs=4 bufferSize=10 bufferControl=WH routingControl="MESH-DOR">
   <Injector id="INJ" numHeaders=1 typeInj="WH" numMessTypes=4>
   <Consumer id="CONS">
   
   <SimpleRouter id="ROUTER" inputs="5" outputs="5" headerDelay=0 dataDelay=0 vnets=4 >
      <Input  id=1  type="X+">
      <Input  id=2  type="X-">
      <Input  id=3  type="Y+">
      <Input  id=4  type="Y-">
      <Input  id=5  type="Node">
      <Output id=1  type="X+">
      <Output id=2  type="X-">
      <Output id=3  type="Y+">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </SimpleRouter>
   
   <Connection id="C01" source="INJ" destiny="ROUTER.5">
   <Connection id="C02" source="ROUTER.5" destiny="CONS">

   <Input id="1" type="X+"   wrapper="ROUTER.1">
   <Input id="2" type="X-"   wrapper="ROUTER.2">
   <Input id="3" type="Y+"   wrapper="ROUTER.3">
   <Input id="4" type="Y-"   wrapper="ROUTER.4">

   <Output id="1" type="X+"   wrapper="ROUTER.1">
   <Output id="2" type="X-"   wrapper="ROUTER.2">
   <Output id="3" type="Y+"   wrapper="ROUTER.3">
   <Output id="4" type="Y-"   wrapper="ROUTER.4">
</Router>

```

## Nework SGML ##

```
<MeshNetwork id="M44_CT_NOC" sizeX=4  sizeY=4  router="MESH-CT-NOC" delay=0>
<MeshNetwork id="M44_WH_NOC" sizeX=4  sizeY=4  router="MESH-WH-NOC" delay=0>
<MeshNetwork id="M44_FAST_CT_NOC" sizeX=4  sizeY=4  router="MESH-CT-FAST-NOC" delay=0>
<TorusNetwork id="T44_CT_NOC" sizeX=4  sizeY=4  router="TORUS-CT-NOC" delay=0>
```

## Simulation SGML ##

```
<Simulation id="M44-CT-NOC">
   <Network            id="M44_CT_NOC">
   <SimulationCycles   id=20000000000000000>
   <StopInjectionAfterMsg id=200000000000>
   <TrafficPattern     id="MODAL" type=EMPTY numMessTypes=4>
   <Seed               id=113>
   <Load               id=0.1>
   <MessageLength      id=1>
   <PacketLength       id=5>
   <LinkWidth          id=16>
   <FlitSize           id=5>
   <NetworkClockRatio  id=1>
   <UnifyNetworks      id=1>
</Simulation>

<Simulation id="M44-CT-MC-NOC">
   <Network            id="M44_CT_NOC">
   <SimulationCycles   id=20000000000000000>
   <StopInjectionAfterMsg id=5000>
   <TrafficPattern     id="MULTICAST" type=RANDOM numMessTypes=4 probMulticast=0.5 lengthMulticast=8>
   <Seed               id=113>
   <Load               id=0.1>
   <MessageLength      id=1>
   <PacketLength       id=5>
   <LinkWidth          id=16>
   <FlitSize           id=5>
   <NetworkClockRatio  id=1>
   <UnifyNetworks      id=1>
</Simulation>

<Simulation id="M44-WH-NOC">
   <Network            id="M44_WH_NOC">
   <SimulationCycles   id=20000000000000000>
   <StopInjectionAfterMsg id=200000000000>
   <TrafficPattern     id="MODAL" type=EMPTY numMessTypes=4>
   <Seed               id=113>
   <Load               id=0.1>
   <MessageLength      id=1>
   <PacketLength       id=5>
   <LinkWidth          id=16>
   <FlitSize           id=5>
   <NetworkClockRatio  id=1>
   <UnifyNetworks      id=1>
</Simulation>

<Simulation id="M44-WH-MC-NOC">
   <Network            id="M44_WH_NOC">
   <SimulationCycles   id=20000000000000000>
   <StopInjectionAfterMsg id=5000>
   <TrafficPattern     id="MULTICAST" type=RANDOM numMessTypes=4 probMulticast=0.5 lengthMulticast=8>
   <Seed               id=113>
   <Load               id=0.1>
   <MessageLength      id=1>
   <PacketLength       id=5>
   <LinkWidth          id=16>
   <FlitSize           id=5>
   <NetworkClockRatio  id=1>
   <UnifyNetworks      id=1>
</Simulation>

```