{
	bool flag_2[10];
	int sum;
	sum = m;
	for (int l = 0; l < 10; ++l)
	{
		flag_2[l] = false;
	}
	for (int l = 1; l <= m; ++l)
	{
		if (l == i) continue;

		if (sd[l][j] != 0)
		{
			flag_2[sd[l][j]] = true;
			sum--;
		}
		else
		{
			for (int s = 1; s <= m; ++s)
			{
				if (check[l][j][s] == false && flag_2[s] == false)
				{
					flag_2[s] = true;
					sum--;
				}
			}
		}
	}
	if (sum == 1)
	{
		for (int l = 1; l <= m; ++l)
		{
			if (flag_2[l] == false)
			{
				sd[i][j] = l;
			}
		}
		return;
	}
	sum = m;
	for (int s = 0; s < 10; ++s)
	{
		flag_2[s] = false;
	}
	for (int s = 1; s <= m; ++s)
	{
		if (s == j) continue;

		if (sd[i][s] != 0)
		{
			flag_2[sd[i][s]] = true;
			sum--;
		}
		else
		{
			for (int l = 1; l <= m; ++l)
			{
				if (check[i][s][l] == false && flag_2[l] == false)
				{
					flag_2[l] = true;
					sum--;
				}
			}
		}
	}
	if (sum == 1)
	{
		for (int l = 1; l <= m; ++l)
		{
			if (flag_2[l] == false)
			{
				sd[i][j] = l;
			}
		}
		return;
	}