# Introduction #
<p align='justify'>
The most relevant publication about multicast support in Virtual Channel routers for on-chip environments can be found <a href='http://projects.csail.mit.edu/wiki/pub/LSPgroup/PublicationList/multicast.pdf'>here</a>. This router reduces the number of bits required to encode multicast information, assignating an ID to each different set of destinations and storing this information at each router rather than at message header. TOPAZ provides most of its routers with multicast support, including all <a href='Virtual_Channel_Router.md'>Virtual Channel Router</a> implementations. This way we are able to mimic the behavior of VCTM router with unlimited storage capacity for <b>destination sets</b>. Therefore, what we call VCTM router is merely a Virtual Channel Router with classical multicast support through DOR trees. This can be seen as an idealized VCTM router without setup phase and with unlimited storage for destiantion sets information".<br>
</p>

# Details #
<p align='justify'>
The way to simulate the idealized version of VCTM is to pick your <a href='Virtual_Channel_Router.md'>Virtual Channel router</a> configuration and choose the appropriate injector: WH-MCAST (the one which does not convert one multicast message into multiple unicast ones).<br>
</p>