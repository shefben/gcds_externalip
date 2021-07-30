NuWON Networking                     |
5/20/2021			     |
Ground Control Dedicated Server Patch|
--------------------------------------

Fixes GCDS to allow players to join your server.


How it works:
-------------
This Patch is a winsock proxy dll.  What it does is redirect the function inet_ntoa()
to the new dll.  The proxy dll then checks for the server's external IP address,
Once it has the external IP it returns the function back to the original winsock dll
which takes care of the rest. 

Uses:
-----
Due to Ground Control being an old games, when it was developed things like routers 
and local networks where not worried about because most normal people used 56k dial-up.
The Ground Control Dedicated Server broadcasts to NuWON with the server's local IP address.
This patch replaced the Local IP with your Remote IP so players can join your server
without any issues.

How to install:
---------------
Extract wsock32.dll into your Ground Control Dedicated Server root folder; Where 
DedicatedServer.exe and DosDSS.exe are located.

After extracting the dll, start up your dedicated server and tell all your friends
you have a working Ground Control server!

Contact Us:
-----------
If your have any problems or ideas, please feel free to post on https://NuWON.net
or email support: support@neuwon.com