#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <signal.h>

#define  BUFF_SIZE   1024
#define PORT 4000 // 통신할 Port No 적는다.

int   main( void)
{
    int   server_socket;
    int   client_socket;
    int   client_addr_size;

    int   readn;
    struct sockaddr_in   server_addr;
    struct sockaddr_in   client_addr;

    char   buffer[500];
    int is_disconnected = 0;

    signal(SIGPIPE, SIG_IGN);

    server_socket  = socket( PF_INET, SOCK_STREAM, 0); //서버 접속을 위한 소켓 생성
    // PF_INET : 인터넷 프로토콜(TCP/IP를 사용하기 위해 기본적으로 인터넷 프로토콜 지정)
    // SOCK_STREAM : TCP / SOCK_DGRAM : UDP
    // IPPROTO_TCP : TCP 이지만 0인 경우 type에서 미리 정해진 경우

    if( -1 == server_socket) {
        printf( "server socket create fail\n");
        exit( 1);
    }

    memset( &server_addr, 0, sizeof( server_addr)); //메모리 초기화
    server_addr.sin_family     = AF_INET; //IPv4 인터넷 주소 체계 저장
    server_addr.sin_port       = htons( PORT); //사용할 port 번호는 4000
    server_addr.sin_addr.s_addr= htonl( INADDR_ANY); //32bit IPv4 주소

    if( -1 == bind( server_socket, (struct sockaddr*)&server_addr, sizeof( server_addr) ) )
    {
        printf( "bind() error \n");
        exit( 1);
    }

    if( -1 == listen(server_socket, 5)) {
        printf( "listen() fail.\n");
        exit( 1);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////
    while(!is_disconnected) {
        client_addr_size  = sizeof( client_addr);
        client_socket     = accept( server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        readn = 0;
        buffer[0] = '\0';
        
        while(client_socket) {
            char *p;

            if ( -1 == client_socket) {   
                printf("client connection broken \n");
                exit(1);
            }

            readn = read ( client_socket, buffer, BUFF_SIZE);
            if(readn <= 0){
                printf( "readn_status : %d, errno: %d [%s]\n",readn, errno, strerror(errno));
                is_disconnected = 1;
                break;
            }
            printf( "readn : %d \n",readn);
            
            /* truncate after a null or a new line charactor. */
            p = strchr(buffer, '\n');
            if (p != NULL) *p = '\0';
            
            printf( "receive: %s\n", buffer);
        }
    }
    close( client_socket);
    return 0;
}
