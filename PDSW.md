``` HTML
Telnet www.escuelaing.edu.co 80
Trying 190.24.150.102...
Connected to hockney.escuelaing.edu.co.
Escape character is '^]'.
get sssss/abc.html HTTP/1.0
GET sssss/abc.html HTTP/1.0
GET /sssss/abc.html HTTP/1.0
HTTP/1.1 400 Bad Request
Date: Thu, 30 Aug 2018 14:50:23 GMT
Server: Apache/2.2.22 (Fedora)
Content-Length: 406
Connection: close
Content-Type: text/html; charset=iso-8859-1

<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>400 Bad Request</title>
</head><body>
<h1>Bad Request</h1>
<p>Your browser sent a request that this server could not understand.<br />
Request header field is missing ':' separator.<br />
<pre>
GET sssss/abc.html HTTP/1.0</pre>
</p>
<hr>
<address>Apache/2.2.22 (Fedora) Server at www.escuelaing.edu.co Port 80</address>
</body></html>
Connection closed by foreign host.
```