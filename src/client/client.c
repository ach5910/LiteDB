/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 19:50:38 by bschroed          #+#    #+#             */
/*   Updated: 2017/04/23 19:50:39 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	error(char *msg)
{
	perror(msg);
	exit(0);
}

int		main(int argc, char *argv[])
{
	int		sockfd;
	int		portno;
	int		n;
	char	buffer[4096];
	struct	sockaddr_in serv_addr;
	struct	hostent	*server;
	if (argc < 3)
	{
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	server = gethostbyname(argv[1]);
	if (server == NULL)
	{
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr,
		(char *) &serv_addr.sin_addr.s_addr,
		server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd, (const struct sockaddr *) &serv_addr,
		sizeof(serv_addr)) < 0)
			error("ERROR connecting");
	while (1)
	{
		printf("FT_DB> ");
		bzero(buffer, 4096);
		fgets(buffer, 4096, stdin);
		if (n < 0)
			error("ERROR writing to socket");
		if (strncmp(buffer, "quit", 4) == 0)
		{
			shutdown(sockfd, 1);
			return (0);
		}
		if (help_filter(buffer) == 0)
			continue;
		n = write(sockfd, buffer, strlen(buffer));
		bzero(buffer, 4096);
		n = read(sockfd, buffer, 4096);
		if (n < 0)
			error("ERROR reading from socket");
		printf("%s\n", buffer);
	}
	return (0);
}
