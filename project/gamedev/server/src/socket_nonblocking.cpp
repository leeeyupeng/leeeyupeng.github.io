#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

#define MAXLINE 10000

struct sockaddr_in  servaddr;

class Socket_NonBlocking{
private:
    int listenfd;
    unordered_set<int> fdus;

    char  buff[MAXLINE];
public:
    Socket_NonBlocking(int port){
        if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
            printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        }
        //设置非阻塞
        int flags = fcntl(listenfd,F_GETFL,0);
        fcntl(listenfd,F_SETFL,flags|O_NONBLOCK);

        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(port);

        if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
            printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        }

        if( listen(listenfd, 10) == -1){
            printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        }

        
    }

    void updateaccept()
    {
        int fd=1;
        while(fd !=-1){
            fd = accept(listenfd, (struct sockaddr*)NULL, NULL);
            if(fd != -1){
                fdus.insert(fd);
            }
        }
    }

    void updaterecv(){
        int rlen;
        vector<int> vclose1;
        vector<int> vclose2;
        unordered_set<int>::iterator ite = fdus.begin();
        for(ite = fdus.begin();ite!=fdus.end();ite++){
            while(1){
                rlen = recv(*ite,buff,MAXLINE,MSG_DONTWAIT);
                if(rlen==0){
                    vclose1.push_back(*ite);
                    break;
                }
                else if(rlen < 0){
                    if(errno == EAGAIN || errno == EWOULDBLOCK){
                        break;
                    }
                    else{
                        vclose2.push_back(*ite);
                        break;
                    }
                }
                else{
                    buff[rlen] = '\0';
                    printf("n:%d",rlen);
                    printf("recv msg from client: %s\n", buff);
                }
            }
        }

        for(int i = 0; i < vclose1.size(); i++){
            fdus.erase(vclose1[i]);
        }

        for(int i = 0; i < vclose2.size(); i++){
            close(vclose2[i]);
            fdus.erase(vclose2[i]);
        }
    }

    void updatesend(char _buff[],int len){
        vector<int> vclose1;
        vector<int> vclose2;
        unordered_set<int>::iterator ite = fdus.begin();
        for(ite = fdus.begin();ite!=fdus.end();ite++){
            int rlen = send(*ite,_buff,len,MSG_DONTWAIT);
            // if(rlen==0){
            //     vclose1.push_back(*ite);
            //     break;
            // }
            // else 
            if(rlen <= 0){
                if(errno == EAGAIN || errno == EWOULDBLOCK){
                    break;
                }
                else{
                    vclose2.push_back(*ite);
                    break;
                }
            }
            else{
            }
        }

        for(int i = 0; i < vclose1.size(); i++){
            fdus.erase(vclose1[i]);
        }

        for(int i = 0; i < vclose2.size(); i++){
            close(vclose2[i]);
            fdus.erase(vclose2[i]);
        }
    }
};


// int main(){
//     int len;
//     char buff[MAXLINE];

//     Socket_NonBlocking socket(6666);
//     while(1){
//         socket.updateaccept();
//         socket.updaterecv();

//         len = rand() & MAXLINE;
//         len ++;    
//         for(int i = 0; i < len;i++){
//             buff[i] = rand()%26;
//             buff[i]+=97;
//         }
//         socket.updatesend(buff,len);

//         cout<<"usleep(1000000);"<<endl;
//         usleep(1000000);
//     }
//     return 0;
// }