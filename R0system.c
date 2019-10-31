int MySystem(int , const char *arg)
{
	int i = 0;
	char *pTmp[10] = {NULL};
	pid_t pid;
	int status;

	pTmp[i] = strtok(Str, " ");
	i++;

	while (NULL != (pTmp[i] = strtok(NULL," ")))
	{
		i++;
	}
	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == pid)
	{
		execvp(pTmp[0], pTmp);
	}
	else if (pid > 0)
	{
		waitpid(0, &status, 0);
	}
	return status;
}
