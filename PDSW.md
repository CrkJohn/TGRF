
# PDSW LABORATORIO N°3
##PARTE I - Jugando a ser un cliente HTTP
### Punto 1-2-3
``` HTML
Telnet www.escuelaing.edu.co 80
Trying 190.24.150.102...
Connected to hockney.escuelaing.edu.co.
Escape character is '^]'.
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
### Punto 4
``` HTML
  telnet www.httpbin.org 80
Trying 34.238.48.57...
Connected to www.httpbin.org.herokudns.com.
Escape character is '^]'.
GET /html HTTP/1.1
Host: www.httpbin.org

HTTP/1.1 200 OK
Connection: keep-alive
Server: gunicorn/19.9.0
Date: Thu, 30 Aug 2018 14:14:43 GMT
Content-Type: text/html; charset=utf-8
Content-Length: 3741
Access-Control-Allow-Origin: *
Access-Control-Allow-Credentials: true
Via: 1.1 vegur

<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
      <h1>Herman Melville - Moby-Dick</h1>

      <div>
        <p>
          Availing himself of the mild, summer-cool weather that now reigned in these latitudes, and in preparation for the peculiarly active pursuits shortly to be anticipated, Perth, the begrimed, blistered old blacksmith, had not removed his portable forge to the hold again, after concluding his contributory work for Ahab's leg, but still retained it on deck, fast lashed to ringbolts by the foremast; being now almost incessantly invoked by the headsmen, and harpooneers, and bowsmen to do some little job for them; altering, or repairing, or new shaping their various weapons and boat furniture. Often he would be surrounded by an eager circle, all waiting to be served; holding boat-spades, pike-heads, harpoons, and lances, and jealously watching his every sooty movement, as he toiled. Nevertheless, this old man's was a patient hammer wielded by a patient arm. No murmur, no impatience, no petulance did come from him. Silent, slow, and solemn; bowing over still further his chronically broken back, he toiled away, as if toil were life itself, and the heavy beating of his hammer the heavy beating of his heart. And so it was.—Most miserable! A peculiar walk in this old man, a certain slight but painful appearing yawing in his gait, had at an early period of the voyage excited the curiosity of the mariners. And to the importunity of their persisted questionings he had finally given in; and so it came to pass that every one now knew the shameful story of his wretched fate. Belated, and not innocently, one bitter winter's midnight, on the road running between two country towns, the blacksmith half-stupidly felt the deadly numbness stealing over him, and sought refuge in a leaning, dilapidated barn. The issue was, the loss of the extremities of both feet. Out of this revelation, part by part, at last came out the four acts of the gladness, and the one long, and as yet uncatastrophied fifth act of the grief of his life's drama. He was an old man, who, at the age of nearly sixty, had postponedly encountered that thing in sorrow's technicals called ruin. He had been an artisan of famed excellence, and with plenty to do; owned a house and garden; embraced a youthful, daughter-like, loving wife, and three blithe, ruddy children; every Sunday went to a cheerful-looking church, planted in a grove. But one night, under cover of darkness, and further concealed in a most cunning disguisement, a desperate burglar slid into his happy home, and robbed them all of everything. And darker yet to tell, the blacksmith himself did ignorantly conduct this burglar into his family's heart. It was the Bottle Conjuror! Upon the opening of that fatal cork, forth flew the fiend, and shrivelled up his home. Now, for prudent, most wise, and economic reasons, the blacksmith's shop was in the basement of his dwelling, but with a separate entrance to it; so that always had the young and loving healthy wife listened with no unhappy nervousness, but with vigorous pleasure, to the stout ringing of her young-armed old husband's hammer; whose reverberations, muffled by passing through the floors and walls, came up to her, not unsweetly, in her nursery; and so, to stout Labor's iron lullaby, the blacksmith's infants were rocked to slumber. Oh, woe on woe! Oh, Death, why canst thou not sometimes be timely? Hadst thou taken this old blacksmith to thyself ere his full ruin came upon him, then had the young widow had a delicious grief, and her orphans a truly venerable, legendary sire to dream of in their after years; and all of them a care-killing competency.
        </p>
      </div>
  </body>
</html>
```
### Punto 5

```
  wc -c respuesta.html
  3742 resultado.html
```
### Punto 6

```
curl -v www.httpbin.org
curl -i www.httpbin.org

```
 ¿Cuales son las diferencias con los diferentes parámetros?
 La diferencia entre ambos es el encabezado, uno tiene más información
 que otro
 
 ## Parte 2 
 
 ### Punto 1
 
 Un Servlet se utiliza para ampliar las capacidades de un servidor, en este caso este Servlet recibe peticiones de los
 usuarios, son atendidas por el mismo Servlet y envía respuestas al usuario.
 La petición es HttpServletRequest y las respuestas son HttpServletResponse.
 El urlPatterns es helloServlet
 
 ### Punto 3
 
 Revise en el pom.xml para qué puerto TCP/IP está configurado el servidor embebido de Tomcat (ver sección de plugins).
 
 El puerto en el que está configurado el servidor es el 8080
 
 ### Punto 6
 ``` 
    http://localhost:8080//helloServlet?name="Amo PDSW"
    RESULTADO:
    Hello"Amo PDSW"!
 ```
 
 
## Parte 3
### Punto 13

Recompile y ejecute la aplicación. Abra en su navegador http://localhost:8080/index.html , y rectifique que la página hecha anteriormente sea mostrada. Ingrese los datos y verifique los resultados. Cambie el formulario para que ahora en lugar de POST, use el método GET. ¿Qué diferencia observa?

No funciona, bota error el formulario ya que no hay ningún metodo implementado en la clase SampleServlet para el método GET

### Punto 23

Realice una petición por medio del explorador a la url que se está usando para mostrar los “TODOs” sin parámetros adicionales https://jsonplaceholder.typicode.com/todos/ y analice el resultado. ¿Qué información retorna la url? ¿Qué formato tiene? ¿Qué tiene de diferente con la url donde se envía un parámetro (por ejemplo https://jsonplaceholder.typicode.com/todos/1)?

Con la URL https://jsonplaceholder.typicode.com/todos/ nos muestra la informacion de 200 objetos y está en formato json, si se envía un parametr como por ejemplo https://jsonplaceholder.typicode.com/todos/1 solamente nos muestra la información de 1 objeto

### Punto 26

En el explorador abra la url del servlet creado y observe el resultado. ¿Qué se está viendo? Revise cómo están implementados los métodos de la clase Service.java para entender el funcionamiento interno.

Ahora podemos ver la información de los 200 objetos json pero en formato html
