#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main() {
    // 소켓을 생성합니다.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // 서버의 주소와 포트를 설정합니다.
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8181);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 서버에 연결합니다.
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // 데이터를 전송합니다.
    char *data = "Hello, world!";
    int len = strlen(data);
    if (send(sockfd, data, len, 0) < 0) {
        perror("send");
        exit(1);
    }



}
