# Introduction #
<p align='justify'>
The Router.sgml file describes the router microarchitecture that will be employed in simulation. In TOPAZ, router architecture can be described with different levels of detail. In <i>Simple</i> description a single component describes the whole router functionality. With this kind of router TOPAZ is able to simulate an elevated amount of cycles per second, at the cost of precision. In contrast, <i>Detailed</i> descriptions require different components to describe each router element (buffers, routing units, crossbar). This makes simulations much slower, but increases results accuracy.<br>
</p>
<p align='justify'>
Every router definition at Router.sgml file has a similar structure. A first tag identifies the structure, as well as some common parameters to all of its components. Second every component inside the router is defined, through one or multiple tags. Finally, the way all the components are interconnected and connected to router inputs and outputs is also defined. <i>Simple</i> and <i>Detailed</i> router definitions present some differences, making necessary an independent explanation for each of them:<br>
<br>
<ul><li><a href='simplerouterSGML.md'>Simple Router Configuration</a>
</li><li><a href='detailedrouterSGML.md'>Detailed Router Configuration</a>
</p>