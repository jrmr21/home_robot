#include <stdio.h>
#include <string.h>
#include <unistd.h>


#ifdef WIN32    /*sous windows*/

#include <winsock2.h>
WSADATA WSAData;        /*  objet   WSADATA */
#define error -1

#elif defined(linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     /*  close   */
#include <netdb.h>      /*  get hostbyname  */
#define error -1
#define INVALID_SOCKET -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error os no defined

#endif // defined

SOCKADDR_IN ssin;       //  structure TCP
SOCKET sock;            //  soccket     ( surement inutil )


int main()
{

	short int check=100;
	int sock;
	char command[50];


    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if(sock == INVALID_SOCKET)                                  //  error socket
    {
        printf("\n Socket not created %d\n", sock);
    }
    else                                                    //  sinon preparation serveur
    {

        printf("socket create \n");
        SOCKADDR_IN ssin;
        ssin.sin_addr.s_addr = htonl(INADDR_ANY);           //  all IP accept
        ssin.sin_family = AF_INET;
        ssin.sin_port = htons(5006);

        check = bind(sock, (SOCKADDR*)&ssin, sizeof(ssin));      //  bind declaration
        if(check == error )
        {
            printf("fail bind \n");
            closesocket(sock);                  //  fin socket si fail
        }
        else
        {
            char buffer[15];
            buffer[15]='\0';
            
		printf("succes bind \n");
            do
            {
                int taille;                        //   taille des sockets reçus
                taille = sizeof(ssin);                  //  affectation de la taille
		strcpy(buffer, "\0");

            	if(recvfrom != error)                                        //  sock -1 = error ou fin socket
                	printf("la socket est : %d \n",sock);
                recvfrom(sock, buffer, sizeof(buffer)-1, 0,((SOCKADDR*)&ssin), &taille);         //  lecture du msg

                printf("le msg est %s \n", buffer);
		strcpy(command, "echo '");
		strcat(command, buffer);
		strcat(command, "' > /dev/ttyUSB0");
		system(command);		
                   // sendto(sock, bufferS, sizeof(bufferS), 0,((SOCKADDR*)&ssin), sizeof(ssin));        //  send confirmation de reception

            }while(strcmp(buffer, "1005") != 0);             //  tant que l'ecoute est ok on attend

            closesocket(sock);      //  fin socket
        }
    }
#ifdef WIN32    /*sous windows*/
WSACleanup();       //  netoie l'initialisation de la librairies
#endif
}
