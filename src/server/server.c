/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroe@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 00:22:58 by bschroed          #+#    #+#             */
/*   Updated: 2017/04/23 00:26:20 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	error(char *msg)
{
	perror(msg);
	exit(1);
}

void	handle_request(int sock, FILE *fp)
{
	int		n;
	time_t	t;
	char	buffer[256];
	char	*ret;

	time(&t);
	fp = fopen("log.txt", "a+");
	while(1)
	{
		bzero(buffer, 256);
		n = read(sock, buffer, 255);
		if (n < 0)
			error("ERROR reading from socket");
		if (strncmp(buffer, "quit", 4) == 0)
		{
			close(sock);
			fclose(fp);
			return;
		}
		else
		{
			printf("Command: %s", buffer);
			fprintf(fp, "%sFT_DB> %s\n", ctime(&t), buffer);
			init_first();
			init_tables();
			init_operators();
			reset_condition_values();
			init_bool_operations();
			ret = strdup(query_validation(buffer));
			write(sock, ret, strlen(ret));
			bzero(ret, strlen(ret));
		}
		if (n < 0)
			error("ERROR writing to socket");
	}
}

int		main(int argc, char *argv[])
{
	FILE			*fp;
	int				sockfd;
	int				newsockfd;
	int				portno;
	int				pid;
	unsigned int	clilen;
	struct			sockaddr_in serv_addr;
	struct			sockaddr_in cli_addr;

	if (argc < 2)
	{
		fprintf(stderr, "Error, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&serv_addr,
		sizeof(serv_addr)) < 0)
			error("ERROR on binding");
	listen(sockfd, 128);
	clilen = sizeof(cli_addr);
	fp = fopen("log.txt", "a+");
	fclose(fp);
	while (1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
		if (newsockfd < 0)
			error("ERROR on accept");
		else
		{
			fopen("log.txt", "a+");
			fprintf(fp, "CLIENT IP: %s\n", inet_ntoa(cli_addr.sin_addr));
			fclose(fp);
		}
		pid = fork();
		if (pid < 0)
			error("ERROR on fork");
		if (pid == 0)
		{
			close(sockfd);
			handle_request(newsockfd, fp);
			exit(0);
		}
		else
			close(newsockfd);
	}
	return (0);
}
