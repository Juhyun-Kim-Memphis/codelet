#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define  BUFF_SIZE   1024
#define PORT 4000 // 통신할 Port No 적는다.
#define IP_ADDR "127.0.0.1" // 통신할 IP No 적는다.

int main(void)
{
    int   client_socket;
    struct sockaddr_in   server_addr;

    int writen;
    char buffer[500];
    struct tm *t;
    time_t timer;

    int year ;
    int mon ;
    int day ;
    int hour ;
    int min ;
    int sec ;

    int is_disconnected = 0;

    signal(SIGPIPE, SIG_IGN);

    client_socket  = socket( PF_INET, SOCK_STREAM, 0);
    if( -1 == client_socket)
    {
        printf( "socket 생성 실패=%d\n",errno);
        exit( 1);
    }

    memset( &server_addr, 0, sizeof( server_addr));
    server_addr.sin_family     = AF_INET;
    server_addr.sin_port       = htons(PORT); //Port 번호
    server_addr.sin_addr.s_addr= inet_addr(IP_ADDR); // 서버의 주소

    if( -1 == connect( client_socket, (struct sockaddr*)&server_addr, sizeof( server_addr) ) )
    {
        printf( "접속 실패. errno=%d\n", errno); 
        exit( 1);
    }
////////////////////////////////////////////////////////////////////////////////////////////////    
    while(!is_disconnected)
    {
        if ( -1 == client_socket)
        {
            printf("서버 접속 실패=%d\n",errno);
            exit (1);
        }
  
        printf("starting Write\n");
        writen = 0;
        buffer[0] = '\0';
        
        //buffer size 보내주기!
//        write( client_socket, 
        while(client_socket){

            timer = time(NULL);
            t = localtime(&timer);
            year = t->tm_year + 1900;
            mon = t->tm_mon + 1;
            day = t->tm_mday;
            hour = t->tm_hour;
            min = t->tm_min;
            sec = t->tm_sec;
        
            int message[6]={ year, mon, day, hour, min, sec};

            printf("%d년" "%d월" "%d일" "%d시" "%d분" "%d초\n",
                   message[0],message[1],message[2],message[3],message[4],message[5]);

            sprintf(buffer,"%d년" "%d월" "%d일" "%d시" "%d분" "%d초\n",
                   message[0],message[1],message[2],message[3],message[4],message[5]);
                    
            writen = write( client_socket, buffer, strlen(buffer));
            printf("writen_status: %d\n",writen);

            if( -1 == writen)
            {    
                printf("if_error : %d [%s] \n",errno, strerror(errno));
                close( client_socket);
                exit(1);
            }
            
            usleep(900000);
        }

        
    }
    close( client_socket);
                                                 
    return 0;
}
