

char charPik() {
	//total of: <67>  letters and char pool
	char[67] pool{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$*" };
	char finalStr{ "" };
	int l = rand() % 68;
	finalStr = pool[l];
	return finalStr;
}


std::string makeStr(int length)
{
	const std::string lwrcs = "abcdefghijklmnopqrstuvwxyz";
	std::default_random_engine ran(std::time(nullptr));
	std::uniform_int_distribution<int> distribution(0, lwrcs.size() - 1);

	std::string str;
	while (str.size() < length) str += lwrcs[distribution(ran)];
	return str;
}

