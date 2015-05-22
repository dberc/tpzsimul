# Introduction #
<p align='justify'>Among all the results provided, TOPAZ returns the total count of most significant network events for every simulation. With these values, power/energy evaulation tools such as <a href='.md'>ORION</a> can be easily employed to extract power and energy numbers from a certain network configuration. Configuring both tools to emulate similar router structures, power and energy values (even area) for each event are easily extracted from ORION for a wide range of technologies and operation frequencies.<br>
<br>
Event counting provides more flexibility for the final user than the full integration of TOPAZ and ORION. This way, power and energy values extracted from VLSI synthesis tools can be employed instead of ORION models.<br>
<br>
<br>
<hr />
<h1>Events</h1>
<p align='justify'>This table describes the events that are measured in topaz. Finding a zero value for a specific event in simulation results can have two different meanings. In some routers (the less), event count is not fully implemented, we are actively working to complete event count for all routers and we would appreciate the report of any bug found in event count. Some events are associated to components not present in every router, being this the only reason to find a zero value in other cases.<br>
<br>
<table><thead><th> <b>Event</b> </th><th> <b>Description</b> </th></thead><tbody>
<tr><td> Buffer Writes </td><td> A flit is stored in an input buffer </td></tr>
<tr><td> Buffer Reads </td><td> A flit is read from the buffer where it was stored </td></tr>
<tr><td> VC Arbitrations </td><td> Input port arbiter selects one flit among the Virtual channels of each physical port </td></tr>
<tr><td> SW Arbitrations </td><td> Output port arbiter select a winner from the input ports requesting it </td></tr>
<tr><td> SW Traversal </td><td> A flit traverses the crossbar </td></tr>
<tr><td> Link Traversal </td><td> A flit traverses the link between two neighbor routers </td></tr>
<tr><td> Router Bypass </td><td> Router traversals that do not require some actions ( such as buffer read/write) </td></tr>
<tr><td>              </td><td>                    </td></tr>
<tr><td> IS Traversal </td><td> a flit traverses Input Stage (Rotary router) </td></tr>
<tr><td> OS Traversal </td><td> a flit traverses Output Stage (Rotary router) </td></tr>
<tr><td> MP Traversal </td><td> a flit traverses a Multiport Buffer (Rotary router) </td></tr></tbody></table>


<hr />
<h1>Process</h1>

The typical process followed to extract energy numbers involves a few steps described here.<br>
<ol><li><p align='justify'>TOPAZ Configuration: Choose the router configuration desired through all the parameters in router.sgml.<br>
</li><li><p align='justify'>Collect event results: After simulating a certain amount of cycles, your trace or an application through GEMS, collect the values obtained for every event.<br>
</li><li><p align='justify'>ORION energy/event:  Edit the <i>SIM_port.h</i> file in ORION and try to mimic the configuration simulated in TOPAZ. Choose the appropriate frequency and technology parameters for your case. A small correspondence between ORION and TOPAZ parameters to simulate similar structures is pending.<br>
</li><li><p align='justify'>Total Energy: The total energy consumed by the network must be calculated "manually". Scripting languages can be useful to obtain final results here.